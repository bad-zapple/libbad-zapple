#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "dummy.hpp"



TEST_CASE( "Dummy is tested", "[dummy]") {
	REQUIRE( dummy() == 0);
	REQUIRE( dummy() != 1);
}
