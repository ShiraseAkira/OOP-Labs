// vectorTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//V2.1.1

#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../vector/ProcessVector.h"

TEST_CASE("Vectors can be processed")
{
	std::vector<double> v;
	SECTION("Processing empty vector does not change it") {
		ProcessVector(v);
		REQUIRE_THAT(v, Catch::Matchers::Equals(std::vector<double>{}));
	}
	SECTION("Processing vector with 1 as smallest element does not change it") {
		v = {100.0, 5 , 1};
		ProcessVector(v);
		REQUIRE_THAT(v, Catch::Matchers::Equals(std::vector<double>{100.0, 5, 1}));
	}
	SECTION("Processing vector with 0 as smallest element turns it to vector of 0's") {
		v = { 100.0, 5 , 1, 0 };
		ProcessVector(v);
		REQUIRE_THAT(v, Catch::Matchers::Equals(std::vector<double>{0, 0, 0, 0}));
	}
	SECTION("Processing vector results in vector, with each element being multiplied by lowest element") {
		v = { 100.0, 5 , 1, 0, -1, -5, 0.38 };
		ProcessVector(v);
		REQUIRE_THAT(v, Catch::Matchers::Equals(std::vector<double>{-500.0, -25, -5, 0, 5, 25, -1.9}));
	}
}