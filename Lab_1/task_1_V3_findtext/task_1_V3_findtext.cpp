#include <iostream>
#include <fstream>

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

}
