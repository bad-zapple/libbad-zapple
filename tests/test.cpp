#include <catch2/catch_test_macros.hpp>
#include "dummy.hpp"



TEST_CASE( "Dummy is tested", "[dummy]") {
	REQUIRE( dummy() == 0);
	REQUIRE( dummy() != 1);
}
