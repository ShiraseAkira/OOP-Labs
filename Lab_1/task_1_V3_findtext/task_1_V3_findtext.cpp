#include <fstream>
#include <iostream>
#include <string>
#include <optional>

using namespace std;

struct Args
{
	string inputFileName;
	string stringToFind;
};

optional<Args> ParseArgs(int argc, char* argv[]) {
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: findtext.exe <file name> <line to search>" << endl;
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.stringToFind = argv[2];
	return args;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	std::ifstream file;
	file.open(args->inputFileName);
	if (!file.is_open())
	{
		cout << "Can not open " << argv[1] << endl;
		return 1;
	}

	string s;
	bool isFound = false;
	int count = 1;

	while (getline(file, s))
	{
		if (s == args->stringToFind)
		{
			isFound = true;
			cout << count << endl;
		}
		count++;
	}

	if (file.bad())
	{
		cout << "Failed to read data from input file" << endl;
		return 1;
	}

	if (!isFound)
	{
		cout << "Text not found" << endl;
		return 1;
	}

	return 0;
}
