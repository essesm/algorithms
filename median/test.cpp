#include "median.h"
#include <cassert>
#include <fstream>

using namespace std;

int main()
{
	Median m;
	ifstream infile("Median.txt");
	Median median;
	int temp;
	int sum = 0;

	infile >> temp;

	while (!infile.eof())
	{
		median.insert(temp);
		sum += median.get();

		infile >> temp;
	}

	assert(sum % 10000 == 1213);
}
