#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../CComplex/CComplex.h"
#include <sstream>
#include <vector>

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

SCENARIO("Testing overloaded binary *") {
	GIVEN("2 complex numbers") {
		CComplex c1(2, 2), c2(3, 3);
		WHEN("you multiply them") {
			CComplex result = c1 * c2;
			CHECK(result.Im() == 12);
			CHECK(result.Re() == 0);
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 4);
		double f = 2;
		WHEN("you multiply float by complex") {
			CComplex result = c * f;
			CHECK(result.Im() == 8);
			CHECK(result.Re() == 8);
		}
		AND_WHEN("you multiply complex by float") {
			CComplex result = f * c;
			CHECK(result.Im() == 8);
			CHECK(result.Re() == 8);
		}
	}
}

SCENARIO("Testing overloaded binary /") {
	GIVEN("2 complex numbers") {
		CComplex c1(1, 2), c2(3, 4);
		WHEN("you divide them") {
			CComplex result = c1 / c2;
			CHECK(result.Im() == 0.08);
			CHECK(result.Re() == 0.44);
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 4);
		double f = 2;
		WHEN("you divide float by complex") {
			CComplex result = c / f;
			CHECK(result.Im() == 2);
			CHECK(result.Re() == 2);
		}
		AND_WHEN("you divide complex by float") {
			CComplex result = f / c;
			CHECK(result.Im() == -0.25);
			CHECK(result.Re() == 0.25);
		}
	}
	GIVEN("Complex number and 0") {
		CComplex c(0, 1);
		double zero = 0;
		WHEN("you divide number by zero") {
			THEN("you get an exception") {
				CHECK_THROWS_AS(c / zero, std::runtime_error);
			}			
		}
	}
}


SCENARIO("Testing overloaded +=") {
	GIVEN("2 complex numbers") {
		CComplex c1(1, 2), c2(3, 4), c3(1, 1);
		WHEN("you addition assignment them") {
			c1 += c2 += c3;
			CHECK(c1.Im() == 7);
			CHECK(c1.Re() == 5);
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 4);
		double f = 2;
		WHEN("you addition assignment float to complex") {
			c += f += 3;
			CHECK(c.Im() == 4);
			CHECK(c.Re() == 9);
		}
	}
}

SCENARIO("Testing overloaded -=") {
	GIVEN("2 complex numbers") {
		CComplex c1(1, 2), c2(3, 4), c3(1, 1);
		WHEN("you subtraction assignment them") {
			(c1 -= c2) -= c3;
			CHECK(c1.Im() == -3);
			CHECK(c1.Re() == -3);
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 4);
		double f = 2;
		WHEN("you subtraction assignment float to complex") {
			(c -= f) -= 3;
			CHECK(c.Im() == 4);
			CHECK(c.Re() == -1);
		}
	}
}

SCENARIO("Testing overloaded *=") {
	GIVEN("2 complex numbers") {
		CComplex c1(1, 2), c2(3, 4), c3(1, 1);
		WHEN("you multiplication assignment them") {
			(c1 *= c2) *= c3;
			CHECK(c1.Im() == 5);
			CHECK(c1.Re() == -15);
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 4);
		double f = 2;
		WHEN("you multiplication assignment float to complex") {
			(c *= f) *= 3;
			CHECK(c.Im() == 24);
			CHECK(c.Re() == 24);
		}
	}
}

SCENARIO("Testing overloaded /=") {
	GIVEN("2 complex numbers") {
		CComplex c1(1, 2), c2(3, 4), c3(1, 1);
		WHEN("you division assignment them") {
			(c1 /= c2) /= c3;
			CHECK(c1.Im() == -0.18);
			CHECK(c1.Re() == 0.26);
		}
	}
	GIVEN("complex and float number") {
		CComplex c(4, 8);
		double f = 2;
		WHEN("you division assignment float to complex") {
			(c /= f) /= 4;
			CHECK(c.Im() == 1);
			CHECK(c.Re() == 0.5);
		}
	}
	GIVEN("Complex number and 0") {
		CComplex c(0, 1);
		double zero = 0;
		WHEN("you division assignment float to complex") {
			THEN("you get an exception") {
				CHECK_THROWS_AS((c /= zero) /= 4 , std::runtime_error);
			}
		}
	}
}

SCENARIO("Testing overloaded == !=") {
	GIVEN("2 complex numbers") {
		CComplex c1(1, 1), c2(1, 1), c3(2, 1);
		CHECK(c1 == c2);
		CHECK(c1 != c3);
	}
	GIVEN("complex and float numbers") {
		CComplex c1(4, 8), c2(4);
		double n1 = 4, n2 = 0;
		CHECK(c1 != n1);
		CHECK(c1 != n2);
		CHECK(c2 == n1);
		CHECK(c2 != n2);
		CHECK(n1 != c1);
		CHECK(n1 == c2);
	}
}

SCENARIO("Testing overloaded unar + -") {
	GIVEN("complex number") {
		CComplex c1(1, 1);
		//CComplex cc = +c1;
		//CComplex* p1 = &c1, *p2 = &cc;
		CHECK(-c1 == 0 - c1);
		CHECK(c1 == +c1);
		//CHECK(p1 != p2);
	}
}

SCENARIO("Testing overloaded << >>") {
	GIVEN("output string stream") {
		std::stringstream ss;
		CComplex ca[6] = { {-3.5, -4.8}, {4, 2}, {-3, 2}, {0, -2}, {0, 0}, {3, -0} };
		for (int i = 0; i < 6; i++) {
			ss << ca[i] << "\n";
		}
		CHECK(ss.str() == "-3.5-4.8i\n4+2i\n-3+2i\n0-2i\n0+0i\n3+0i\n");
	}
	GIVEN("input string stream") {
		std::stringstream ss("-3.5-4.8i 4+2i -3+2i 3-2i");
		CComplex c;
		std::vector<CComplex> vc;
		std::vector<CComplex> vcProper = { {-3.5, -4.8}, {4, 2}, {-3, 2}, {3, -2} };
		while (ss >> c) {
			vc.push_back(c);
		}
		CHECK_THAT(vc, Catch::Matchers::Equals(vcProper));
	}
}