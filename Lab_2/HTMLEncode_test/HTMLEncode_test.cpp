#include <iostream>
#include <string>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../HTMLEncode/HTMLEncoder.h"

TEST_CASE("Encoding strings for HTML")
{
	
	SECTION("Empty string encoded as empty string"){
		std::string s;
		REQUIRE(HTMLEncode(s) == "");
	}
	SECTION("String without chars that needs to be encoded stays the same") {
		std::string s("test string no encode needed");
		REQUIRE(HTMLEncode(s) == s);
	}
	SECTION("'\"' character in string gets replaced by &quot;") {
		std::string s("test string with \"");
		REQUIRE(HTMLEncode(s) == "test string with &quot;");
	}
	SECTION("''' character in string gets replaced by &apos;") {
		std::string s("test string with '");
		REQUIRE(HTMLEncode(s) == "test string with &apos;");
	}
	SECTION("'<' character in string gets replaced by &lt;") {
		std::string s("test string with <");
		REQUIRE(HTMLEncode(s) == "test string with &lt;");
	}
	SECTION("'>' character in string gets replaced by &gt;") {
		std::string s("test string with >");
		REQUIRE(HTMLEncode(s) == "test string with &gt;");
	}
	SECTION("'&' character in string gets replaced by &amp;") {
		std::string s("test string with &");
		REQUIRE(HTMLEncode(s) == "test string with &amp;");
	}

	SECTION("String with multiple characters to encode processed correctly as well") {
		std::string s("Cat <says> \"Meow\".M & M\'s");
		REQUIRE(HTMLEncode(s) == "Cat &lt;says&gt; &quot;Meow&quot;.M &amp; M&apos;s");
	}

	
}