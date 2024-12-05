#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>
#include "dummy.hpp"

int main(int ac, char *av[] ) {
	int result = Catch::Session().run(ac, av);
	return result;
}


TEST_CASE( "Dummy is tested", "[dummy]") {
	REQUIRE( dummy() == 0);
	REQUIRE( dummy() != 1);
}
