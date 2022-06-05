#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../DriveCar/Car.h"

TEST_CASE("Encoding strings for HTML")
{
	SECTION("Empty string encoded as empty string") {
		std::string s;
		REQUIRE(HTMLEncode(s) == "");
	}
}