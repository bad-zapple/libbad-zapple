#include <cstdlib>
#include <iostream>
#include <catch2/catch_all.hpp>

#include <LibBadZapple.hpp>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

# define TEST_PORT 0xBAAD

TEST_CASE("Basic SocketW tests", "[Client SocketW]")
{
    sockaddr_in saddr_in;
    int fd;
    int err;
    
    std::memset(&saddr_in, 0, sizeof(sockaddr_in));
    saddr_in.sin_family = AF_INET;
    saddr_in.sin_port = htons(TEST_PORT);
    saddr_in.sin_addr.s_addr = inet_addr("127.0.0.1");

    fd = socket(PF_INET, SOCK_STREAM, 0);
    REQUIRE(fd >= 0);
    err = connect(fd, (const sockaddr*)&saddr_in, sizeof(sockaddr_in));
    REQUIRE(err >= 0);

	SocketW sock(fd);

	/* We're connected to the test server, we can run test suites */
	SECTION("1. Simple handshake")
	{
        std::string msg;
		sock << "Hello testserver";
		REQUIRE(sock.Send() > 0); /* We should be sending at least 1byte */
		REQUIRE(sock.Receive() == true);
		REQUIRE(sock.Consume(msg) == true);
        REQUIRE(msg == "Hello testclient");
	}

    close(fd);
}



#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

#define TEST_PORT 0xBAAD
#define ERR_RET(msg) {perror(msg); return(errno);}

void answerTest(SocketW& client)
{
    std::string msg;

	client.Receive();
	while (client.Consume(msg) == true) /* Until we can't consume anymore */
	{
		if (msg == "Hello testserver") /* 1. */
		{
			client << "Hello testclient";
			client.Send();
		}
	}
}

int main(int ac, char **av)
{
	sockaddr_in saddr_in;
	int ssock;
	int csock;
	int ret;

	pid_t pid = fork();

	if (pid == 0) {
		int result = Catch::Session().run(ac, av);
		exit(result);
	}
	
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

	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret)) {
		return WEXITSTATUS(ret);
	} else {
		return 1;
	}

	return (0);
}
