#include <iostream>
#include <string>


#include "WordCounter.h"

using namespace std;
int main()
{
	string s;
	map<string, int> wordCount;

	while (cin >> s) {		
		CountWord(s, wordCount);
	}

	s = getCountedWords(wordCount);

	cout << s;

	return 0;
}
