#pragma once
#include <string>
#include <map>


void CountWord(const std::string& text, std::map<std::string, int>& wordList);
std::string getCountedWords(std::map<std::string, int>& wordList);