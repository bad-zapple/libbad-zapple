#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "dummy.hpp"

int main(int ac, char *av[] ) {
	int result = Catch::Session().run(ac, av);
	return result;
}

int tests_basic(int ac, char **av) {
	return main(ac, av);
}


TEST_CASE( "Dummy is tested", "[dummy]") {
	REQUIRE( dummy() == 0);
	REQUIRE( dummy() != 1);
}
