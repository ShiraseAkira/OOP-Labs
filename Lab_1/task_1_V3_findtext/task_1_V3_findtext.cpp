#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl;
		cout << "Usage: findtext.exe <file name> <line to search>" << endl;
		return 1;
	}

	std::ifstream file;
	file.open(argv[1]);

	if (!file.is_open())
	{
		cout << "Can not open " << argv[1] << endl;
		return 1;
	}

	string stringToFind = argv[2];
	string s;
	bool isFound = false;
	int count = 1;

	while (getline(file, s))
	{
		if (s == stringToFind)
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
