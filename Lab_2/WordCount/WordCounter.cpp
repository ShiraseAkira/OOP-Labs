#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;
void CountWord(const string& text, map<string, int>& wordList) {
	string s;
	s.resize(text.length());
	transform(text.begin(), text.end(), s.begin(), [](char c) {return tolower(c); });
	++wordList[s];
}

string getCountedWords(map<string, int>& wordList) {
	string s;
	for ( auto& word : wordList) {
		s += word.first + "->" + to_string(word.second) + "\n";
	}
	return s;
}