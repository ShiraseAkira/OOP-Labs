// vectorTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("Some_test")
{
	REQUIRE(2 + 2 == 4);
}