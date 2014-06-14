#include "median.h"
#include <cassert>
#include <fstream>

int main()
{
	Median m;
	m.insert(1);
	assert(m.get() == 1);
	m.insert(2);
	assert(m.get() == 1);
	m.insert(3);
	assert(m.get() == 2);
	m.insert(5);
	assert(m.get() == 2);
	m.insert(6);
	assert(m.get() == 3);

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
