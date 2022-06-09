#include <fstream>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

const int REQUIRED_ARGUMENTS_COUNT = 3;
const string ARGUMENTS_COUNT_ERROR = "Invalid arguments count\nUsage: findtext.exe <file name> <line to search>";
const string CAN_NOT_OPEN_FILE_ERROR = "Can not open file:'"; 
const string ERROR_EMPTY_FILE_NAME = "File name is missing";
const string ERROR_EMPTY_SUBSTRING = "String to find is missing";
const string ERROR_CAN_NOT_READ_FILE = "Failed to read data from input file";
const string MESSAGE_TEXT_NOT_FOUND = "Text not found";

struct Args
{
	string inputFileName;
	string stringToFind;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != REQUIRED_ARGUMENTS_COUNT)
	{
		cout << ARGUMENTS_COUNT_ERROR << endl;
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	if (args.inputFileName.length() == 0) {
		cout << ERROR_EMPTY_FILE_NAME << endl;
		return nullopt;
	}
	args.stringToFind = argv[2];
	if (args.stringToFind.length() == 0)
	{
		cout << ERROR_EMPTY_SUBSTRING << endl;
		return nullopt;
	}
	return args;
}

bool HasSubstring(const string& haystack, const string& needle)
{
	auto pos = haystack.find(needle, 0);
	return pos != string::npos;
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
		cout << CAN_NOT_OPEN_FILE_ERROR << argv[1] << "'" << endl;
		return 1;
	}

	string s;
	bool isFound = false;
	int count = 1;

	while (getline(file, s))
	{
		if (HasSubstring(s, args->stringToFind))
		{
			isFound = true;
			cout << count << endl;
		}
		count++;
	}

	if (file.bad())
	{
		cout << ERROR_CAN_NOT_READ_FILE << endl;
		return 1;
	}

	if (!isFound)
	{
		cout << MESSAGE_TEXT_NOT_FOUND << endl;
		return 1;
	}

	return 0;
}
