#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LibBadZapple.hpp"

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
		sock << "Hello testserver";
		REQUIRE(sock.Send() > 0); /* We should be sending at least 1byte */
		REQUIRE(sock.Receive() == true);
		REQUIRE(sock.Consume() == "Hello testclient");
	}

    close(fd);
}