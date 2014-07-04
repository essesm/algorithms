#include "inversions.h"
#include <cassert>
#include <fstream>

using namespace std;

int main()
{
	Inversions i;
	const int SIZE = 100000;
	ifstream in("IntegerArray.txt");
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		in >> arr[i];
	}

	assert(i.count(arr, SIZE) == 2407905288);

	return 0;
}
