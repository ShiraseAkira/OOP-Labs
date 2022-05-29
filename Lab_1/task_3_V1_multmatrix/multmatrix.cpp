#include <iostream>
#include <fstream>
#include <optional>
#include <iomanip>

using namespace std;

struct Args
{
	float matrix[2][3][3];
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: multmatrix.exe <matrix file1> <matrix file2>" << endl;
		return nullopt;
	}

	Args args;
	ifstream file;
	for (int i = 1; i < 3; i++)
	{
		file.open(argv[i]);
		if (!file.is_open())
		{
			cout << "Can not open " << argv[i] << endl;
			return nullopt;
		}

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				file >> args.matrix[i-1][j][k];
			}
		}

		file.close();
	}

	return args;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

    float result[3][3] = {0};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				result[i][j] += args->matrix[0][i][k] * args->matrix[1][k][j];				
			}
		}
	}

	cout << fixed << setprecision(3);

	for (int i = 0; i < 3; i++)
	{
		cout << round(result[i][0] * 1000.f) / 1000.f << "\t" 
			 << round(result[i][1] * 1000.f) / 1000.f << "\t" 
			 << round(result[i][2] * 1000.f) / 1000.f << endl;
	}

	return 0;
}

