#include "firstpivot.h"
#include "lastpivot.h"
#include "medianpivot.h"
#include <cassert>
#include <fstream>

using namespace std;

int main()
{
	FirstPivot fp;
	LastPivot lp;
	MedianPivot mp;

	int size = 10;
	int arr1[] = { 3, 9, 8, 4, 6, 10, 2, 5, 7, 1 };
	int arr2[] = { 3, 9, 8, 4, 6, 10, 2, 5, 7, 1 };
	int arr3[] = { 3, 9, 8, 4, 6, 10, 2, 5, 7, 1 };

	assert(fp.firstPivot(arr1, size) == 25);
	assert(lp.lastPivot(arr2, size) == 29);
	assert(mp.medianPivot(arr3, size) == 21);

	const int SIZE = 10000;
	ifstream in("QuickSort.txt");
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		in >> arr[i];
	}
	in.close();
	assert(fp.firstPivot(arr, SIZE) == 162085);

	in.open("QuickSort.txt");
	for (int i = 0; i < SIZE; i++)
	{
		in >> arr[i];
	}
	in.close();
	assert(lp.lastPivot(arr, SIZE) == 164123);

	in.open("QuickSort.txt");
	for (int i = 0; i < SIZE; i++)
	{
		in >> arr[i];
	}
	in.close();
	assert(mp.medianPivot(arr, SIZE) == 138382);
}
