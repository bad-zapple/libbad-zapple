#include "SocketW.hpp"
#include <sys/errno.h>
#include <cstring>
#include <cmath>

namespace zap
{

SocketW::SocketW(int newFd) : os(), is(), fd(newFd), consumable(false)
{
	
}

SocketW::~SocketW()
{

}

int	SocketW::Send()
{
	std::string tmp;

	tmp = os.str();
	os.clear();
	os.str(std::string());
	tmp += MSG_SEPARATOR;
	return (send(fd, tmp.c_str(), tmp.size(), 0));
}

bool	SocketW::Receive()
{
	char	buffer[4096 + 1];
	int		rd;
	
	rd = recv(fd, (void *)buffer, 4096, 0);
	
	if (rd < 0)
		throw ERecvError();
	if (rd == 0)
		throw EConnectionClosed();

	buffer[rd] = '\0';
	is << buffer;
	consumable = (is.str().find(MSG_SEPARATOR) != std::string::npos);
	return (consumable);
}

bool	SocketW::Consume(std::string &ret)
{
	std::string tmp;
	size_t		pos;

	if (!consumable)
		return (false); /* bad consume, throw exception maybe ? */

	tmp = is.str();
	pos = tmp.find(MSG_SEPARATOR);
	is.str(std::string(tmp.substr(pos + 1)));
	is.clear();
	ret = tmp.substr(0, pos);
	consumable = (is.str().find(MSG_SEPARATOR) != std::string::npos); /* Set the Consummable flag */
	return (true);
}

SocketW::operator bool() const
{
    return (os.operator bool());
}

const char *SocketW::EConnectionClosed::what() const throw()
{
	return ("Remote connection dropped");
}

const char *SocketW::ERecvError::what() const throw()
{
	return (std::strerror(errno));
}

}; /* namespace zap */