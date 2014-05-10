#include "inversions.h"
#include <cassert>
#include <fstream>

using namespace std;

int main()
{
	Inversions i;

	int size = 6;
	int arr1[] = { 1, 2, 3, 4, 5, 6 };
	int arr2[] = { 6, 5, 4, 3, 2, 1 };
	int arr3[] = { 1, 3, 5, 2, 4, 6 };
	int arr4[] = { 1, 6, 3, 2, 4, 5 };

	assert(i.count(arr1, size) == 0);
	assert(i.count(arr2, size) == 15);
	assert(i.count(arr3, size) == 3);
	assert(i.count(arr4, size) == 5);

	size = 5;
	int arr5[] = { 5, 4, 3, 2, 1 };
	int arr6[] = { 1, 5, 3, 2, 4 };

	assert(i.count(arr5, size) == 10);
	assert(i.count(arr6, size) == 4);

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
