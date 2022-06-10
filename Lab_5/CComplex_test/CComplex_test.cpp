#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../CComplex/CComplex.h"

SCENARIO("Testing basic functionality") {
	CComplex c0;
	GIVEN("0") {
		CHECK(c0.Im() == 0);
		CHECK(c0.Re() == 0);
		CHECK(c0.GetMagnitude() == 0);
		CHECK(c0.GetArgument() == 0);
	}
	CComplex c1(1);
	GIVEN("real 1") {
		CHECK(c1.Im() == 0);
		CHECK(c1.Re() == 1);
		CHECK(c1.GetMagnitude() == 1);
		CHECK(c1.GetArgument() == 0);
	}
	CComplex ci(0, 1);
	GIVEN("complex i") {
		CHECK(ci.Im() == 1);
		CHECK(ci.Re() == 0);
		CHECK(ci.GetMagnitude() == 1);
		CHECK_THAT(ci.GetArgument(), Catch::Matchers::WithinAbs(3.1415/2, 0.0001));
	}
}