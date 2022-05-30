#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../GeneratePrimeNumbers/GeneratePrimeNumbersSet.h"

TEST_CASE("Generating prime numbers")
{
	std::set<int> st;
	SECTION("There is no primes less than 2") {
		st = GeneratePrimeNumbersSet(0);
		REQUIRE(st.size() == 0);
		st = GeneratePrimeNumbersSet(1);
		REQUIRE(st.size() == 0);
	}
	SECTION("Set contains right number of primes") {
		st = GeneratePrimeNumbersSet(2);
		REQUIRE(st.size() == 1);
		st = GeneratePrimeNumbersSet(3);
		REQUIRE(st.size() == 2);
		st = GeneratePrimeNumbersSet(5);
		REQUIRE(st.size() == 3);
		st = GeneratePrimeNumbersSet(7);
		REQUIRE(st.size() == 4);
		st = GeneratePrimeNumbersSet(100);
		REQUIRE(st.size() == 25);
		st = GeneratePrimeNumbersSet(1000);
		REQUIRE(st.size() == 168);
		st = GeneratePrimeNumbersSet(1000000);
		REQUIRE(st.size() == 78498);
		st = GeneratePrimeNumbersSet(100000000);
		REQUIRE(st.size() == 5761455);
	}
}