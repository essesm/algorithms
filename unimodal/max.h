#ifndef __MAX_H__
#define __MAX_H__

#include <iostream>
using namespace std;

class Max
{
	public:
		int max(int arr[], int size);

	private:
		int max(int arr[], int left, int right);
};

int Max::max(int arr[], int size)
{
	return max(arr, 0, size);
}

int Max::max(int arr[], int left, int right)
{
	if (right - left == 1)
	{
		return arr[left];
	}

	int mid = (left + right) / 2;

	if (arr[mid] > arr[mid - 1])
	{
		return max(arr, mid, right);
	}

	return max(arr, left, mid);
}

#endif /* __MAX_H__ */
