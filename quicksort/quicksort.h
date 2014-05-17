#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

class QuickSort
{
	public:
		void sort(int arr[], int size);

	private:
		int partition(int arr[], int size);
		void swap(int &x, int &y);
};

void QuickSort::sort(int arr[], int size)
{
	if (size < 2)
	{
		return;
	}

	int middle = partition(arr, size);
	sort(arr, middle);
	sort(arr + middle, size - middle);
}

int QuickSort::partition(int arr[], int size)
{
	swap(arr[0], arr[size / 2]);
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

void QuickSort::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif /* __QUICKSORT_H__ */
