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
		CHECK_THAT(ci.GetArgument(), Catch::Matchers::WithinAbs(3.1415 / 2, 0.0001));
	}
	CComplex c(3, 4);
	GIVEN("complex number with both real and image parth") {
		CHECK(c.Im() == 4);
		CHECK(c.Re() == 3);
		CHECK(c.GetMagnitude() == 5);
		CHECK_THAT(c.GetArgument(), Catch::Matchers::WithinAbs(0.9273, 0.0001));
	}
}

SCENARIO("Testing overloaded binary +") {	
	GIVEN("2 complex numbers") {
		CComplex c1(0, 1), c2(1, 0);
		WHEN("you add them") {
			CComplex result = c1 + c2;
			CHECK(result.Im() == 1);
			CHECK(result.Re() == 1);			
			CHECK_THAT(result.GetMagnitude(), Catch::Matchers::WithinAbs(1.4142, 0.0001));
			CHECK_THAT(result.GetArgument(), Catch::Matchers::WithinAbs(3.1415 / 4, 0.0001));
		}
	}
	GIVEN("complex and float number") {
		CComplex c(3, 3);
		double f = 1;
		WHEN("you add float to complex") {
			CComplex result = c + f;
			CHECK(result.Im() == 3);
			CHECK(result.Re() == 4);
			CHECK(result.GetMagnitude() == 5);
			CHECK_THAT(result.GetArgument(), Catch::Matchers::WithinAbs(0.6435, 0.0001));
		}
		AND_WHEN("you add complex to float") {
			CComplex result = f + c;
			CHECK(result.Im() == 3);
			CHECK(result.Re() == 4);
			CHECK(result.GetMagnitude() == 5);
			CHECK_THAT(result.GetArgument(), Catch::Matchers::WithinAbs(0.6435, 0.0001));
		}
	}
}

SCENARIO("Testing overloaded binary -") {
	GIVEN("2 complex numbers") {
		CComplex c1(2, 2), c2(1, 1);
		WHEN("you subtract them") {
			CComplex result = c1 - c2;
			CHECK(result.Im() == 1);
			CHECK(result.Re() == 1);
			CHECK_THAT(result.GetMagnitude(), Catch::Matchers::WithinAbs(1.4142, 0.0001));
			CHECK_THAT(result.GetArgument(), Catch::Matchers::WithinAbs(3.1415 / 4, 0.0001));
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 4);
		double f = 1;
		WHEN("you subtract float from complex") {
			CComplex result = c - f;
			CHECK(result.Im() == 4);
			CHECK(result.Re() == 3);
			CHECK(result.GetMagnitude() == 5);
			CHECK_THAT(result.GetArgument(), Catch::Matchers::WithinAbs(0.9273, 0.0001));
		}
		AND_WHEN("you subtract complex from float") {
			CComplex result = f - c;
			CHECK(result.Im() == -4);
			CHECK(result.Re() == -3);
			CHECK(result.GetMagnitude() == 5);
			CHECK_THAT(result.GetArgument(), Catch::Matchers::WithinAbs(0.9273 - 3.1415, 0.0001));
		}
	}
}