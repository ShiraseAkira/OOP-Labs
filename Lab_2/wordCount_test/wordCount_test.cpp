#include <iostream>
#include <string>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../WordCount/WordCounter.h"

TEST_CASE("counting words")
{
	SECTION("counts word") {
		std::map<std::string, int> wordCount;
		CountWord(std::string("word"), wordCount);
		REQUIRE(getCountedWords(wordCount) == "word->1\n");
	}
	SECTION("counts word when word repeated") {
		std::map<std::string, int> wordCount;
		CountWord(std::string("word"), wordCount);
		CountWord(std::string("word"), wordCount);
		REQUIRE(getCountedWords(wordCount) == "word->2\n");
	}
	SECTION("counts word in different cases as one") {
		std::map<std::string, int> wordCount;
		CountWord(std::string("word"), wordCount);
		CountWord(std::string("WORD"), wordCount);
		CountWord(std::string("WoRd"), wordCount);
		REQUIRE(getCountedWords(wordCount) == "word->3\n");
	}
	SECTION("counts words when different words") {
		std::map<std::string, int> wordCount;
		CountWord(std::string("word"), wordCount);
		CountWord(std::string("another_word"), wordCount);
		REQUIRE(getCountedWords(wordCount) == "another_word->1\nword->1\n");
	}
}