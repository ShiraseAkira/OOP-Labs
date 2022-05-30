#include <iostream>
#include <sstream>
#include <optional>
#include <set>
#include "GeneratePrimeNumbersSet.h"

using namespace std;

optional<int> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: generateprimenumbers.exe <upper bound>" << endl;
		return nullopt;
	}

	int val;
	istringstream iss(argv[1]);
	if (!((iss >> val) && iss.eof()))
	{
		cout << "Invalid argument type\n";
		cout << "Argument should be a whole decimal number" << endl;
		return nullopt;
	}

	if (val > 100000000)
	{
		cout << "Invalid argument value\n";
		cout << "Argument should be not greater than 100 000 000" << endl;
		return nullopt;
	}

	return val;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	set<int> st = GeneratePrimeNumbersSet(args.value());
	copy(st.begin(), st.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}
