#include "LibBadZapple.hpp"

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

#define TEST_PORT 0xBAAD
#define ERR_RET(msg) {perror(msg); return(errno);}

void answerTest(SocketW& client)
{
	client.Receive();
	while (client.CanConsume() == true) /* Until we can't consume anymore */
	{
		if (client.Consume() == "Hello testserver") /* 1. */
		{
			client << "Hello testclient";
			client.Send();
		}
	}
}

int main(int , char **)
{
	sockaddr_in saddr_in;
	int ssock;
	int csock;
	int ret;
	
	ssock = socket(PF_INET, SOCK_STREAM, 0);
	if (ssock < 0) ERR_RET("socket");

	std::memset(&saddr_in, 0, sizeof(sockaddr_in));
	saddr_in.sin_family = AF_INET;
	saddr_in.sin_port = htons(TEST_PORT);
	saddr_in.sin_addr.s_addr = INADDR_ANY;

	ret = bind(ssock, (const sockaddr*)&saddr_in, sizeof(sockaddr_in));
	if (ret < 0) ERR_RET("bind");

	ret = listen(ssock, 5);
	if (ret < 0) ERR_RET("listen");

	csock = accept(ssock, NULL, NULL);
	if (ret < 0) ERR_RET("accept");

	SocketW sock(csock);
	fd_set rfds;

	while (true)
	{
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(csock, &rfds);

		ret = select(FD_SETSIZE, &rfds, NULL, NULL, NULL);
		if (ret < 0) ERR_RET("select");

		if (FD_ISSET(csock, &rfds))
		{
			try {
				answerTest(sock);
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
				return (0);
			}
		}

		if (FD_ISSET(0, &rfds))
		{
			char buffer[128];
			ret = read(0, buffer, 128);
			if (ret <= 0) /* Server asked to be closed */
				break;
		}
	}

	return (0);
}