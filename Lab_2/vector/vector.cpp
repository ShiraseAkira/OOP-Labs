#include <iostream>
#include <vector>
#include <algorithm>
#include "ProcessVector.h"

using namespace std;

vector<double> readInput()
{
	return vector<double>(istream_iterator<double>(cin), istream_iterator<double>());
}

void writeOutput(vector<double> & vec)
{
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
}

int main()
{
	auto vec = readInput();
	ProcessVector(vec);
	writeOutput(vec);
}
