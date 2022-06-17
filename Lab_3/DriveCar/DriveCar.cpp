#include <iostream>
#include "CarController.h"
#include <string>

using namespace std;

int main()
{
	CarController CC;
	string s;
	while (cin >> s) {
		CC.control(s);
	}
	return 0;
}
