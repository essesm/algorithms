#ifndef __FIRST_PIVOT_H__
#define __FIRST_PIVOT_H__

#include <iostream>
using namespace std;

class FirstPivot
{
	public:
		long firstPivot(int arr[], int size);

	private:
		void sort(int arr[], int size);
		int partition(int arr[], int size);
		void swap(int &x, int &y);
		int comparisons;
};

long FirstPivot::firstPivot(int arr[], int size)
{
	comparisons = 0;
	sort(arr, size);

	return comparisons;
}

void FirstPivot::sort(int arr[], int size)
{
	if (size < 2)
	{
		return;
	}

	int middle = partition(arr, size);

	sort(arr, middle);
	sort(arr + middle, size - middle);

	comparisons += size - 2;
}

int FirstPivot::partition(int arr[], int size)
{
	int pivot = arr[0];

	int i = 1;
	for (int j = 1; j < size; j++)
	{
		if (arr[j] < pivot)
		{
			swap(arr[i++], arr[j]);
		}
	}

	swap(arr[0], arr[i - 1]);

	return i - 1;
}

void FirstPivot::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif /* __FIRST_PIVOT_H__ */
