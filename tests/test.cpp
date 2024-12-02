#include <catch.hpp>
#include "dummy.hpp"

#define CATCH_CONFIG_MAIN


TEST_CASE( "Dummy is tested", "[dummy]") {
	REQUIRE( dummy() == 0);
	REQUIRE( dummy() != 1);
}
