#include <iostream>
#include <string>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../HTMLEncode/HTMLEncoder.h"

TEST_CASE("Generating prime numbers")
{
	
	SECTION("Empty string encoded as empty string"){
		std::string s;
		REQUIRE(HTMLEncode(s) == "");
	}
	SECTION("String without chars that needs to be encoded stays the same") {
		std::string s("test string no encode needed");
		REQUIRE(HTMLEncode(s) == s);
	}
}