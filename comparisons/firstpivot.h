#ifndef __FIRST_PIVOT_H__
#define __FIRST_PIVOT_H__

class FirstPivot
{
	public:
		long firstPivot(int arr[], int size);

	private:
		void sort(int arr[], int size);
		void sort(int arr[], int left, int right);
		int partition(int arr[], int left, int right);
		void swap(int &x, int &y);
		long comparisons;
};

long FirstPivot::firstPivot(int arr[], int size)
{
	comparisons = 0;
	sort(arr, size);

	return comparisons;
}

void FirstPivot::sort(int arr[], int size)
{
	sort(arr, 0, size);
}

void FirstPivot::sort(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}

	int middle = partition(arr, left, right);
	sort(arr, left, middle);
	sort(arr, middle + 1, right);

}

int FirstPivot::partition(int arr[], int left, int right)
{
	comparisons += (right - left - 1);

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

void FirstPivot::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif /* __FIRST_PIVOT_H__ */
