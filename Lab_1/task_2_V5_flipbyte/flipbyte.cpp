#include <iostream>
#include <sstream>
#include <optional>

using namespace std;

optional<int> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: flipbyte.exe.exe <input byte>" << endl;
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

	if (val < 0 || val > 255)
	{
		cout << "Invalid argument value\n";
		cout << "Argument should be between 0 and 255" << endl;
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

	int val = args.value();
	auto result = 0;

	for (int i = 0; i < 8; i++)
	{
		result <<= 1;
		result |= (val & 1);
		val >>= 1;
	}

	cout << result;

	return 0;
}

