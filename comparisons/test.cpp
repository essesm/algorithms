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
