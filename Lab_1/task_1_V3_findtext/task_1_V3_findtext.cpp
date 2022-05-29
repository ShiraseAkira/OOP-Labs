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
}
