#ifndef SOCKETW_HPP
# define SOCKETW_HPP

# include <sstream>
# include <string>
# include <sys/socket.h>
# include <sys/types.h>
# include <exception>

# define MSG_SEPARATOR "\n"

class SocketW
{
	private:
	std::ostringstream	os;
	std::ostringstream	is;
	int					fd;
	bool				consumable;

		public:
	SocketW(int newFd);
	~SocketW();

	/* Send the buffer built with operator<< and appends MSG_SEPARATOR at the end */
	int			Send();

	/* Read data from the socket buffer, returns true if a message is available for "consume" */
	bool		Receive();
	
	/* Get the latest message read from the socket if consumable */
	bool	    Consume(std::string &ret);

	/* Check if os::operator<< went well */
	explicit	operator bool() const;

	/* Exception throw by Receive() if the remote socket was closed */
	class EConnectionClosed : public std::exception
	{
			public:
		virtual const char *what() const throw();
	};

	/* Exception thrown by Receive() when recv returns < 0 */
	class ERecvError : public std::exception
	{
			public:
		virtual const char *what() const throw();
	};
	
	/* Appends data to the output buffer */
	template <typename T>
	SocketW& operator<<(const T &val)
	{
		os << val;
		return (*this);
	}
};

#endif