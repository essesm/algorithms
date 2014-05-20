#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

class QuickSort
{
	public:
		void sort(int arr[], int size);

	private:
		void sort(int arr[], int left, int right);
		int partition(int arr[], int left, int right);
		void swap(int &x, int &y);
};

void QuickSort::sort(int arr[], int size)
{
	sort(arr, 0, size);
}

void QuickSort::sort(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}

	int middle = partition(arr, left, right);
	sort(arr, left, middle);
	sort(arr, middle + 1, right);
}

int QuickSort::partition(int arr[], int left, int right)
{
	int pivot = arr[left];

	int i = left + 1;
	for (int j = left + 1; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			swap(arr[i++], arr[j]);
		}
	}

	swap(arr[left], arr[--i]);

	return i;
}

void QuickSort::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif /* __QUICKSORT_H__ */
