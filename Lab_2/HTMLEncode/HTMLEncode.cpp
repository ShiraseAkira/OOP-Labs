#include <iostream>
#include <string>

#include "HTMLEncoder.h"

using namespace std;
int main()
{
	string s;
	while (getline(cin, s)) {
		cout << HTMLEncode(s) << endl;
	}

	return 0;
}
