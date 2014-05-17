#ifndef __LAST_PIVOT_H__
#define __LAST_PIVOT_H__

class LastPivot
{
	public:
		long lastPivot(int arr[], int size);

	private:
		void sort(int arr[], int size);
		void sort(int arr[], int left, int right);
		int partition(int arr[], int left, int right);
		void swap(int &x, int &y);
		long comparisons;
};

long LastPivot::lastPivot(int arr[], int size)
{
	comparisons = 0;
	sort(arr, size);

	return comparisons;
}

void LastPivot::sort(int arr[], int size)
{
	sort(arr, 0, size);
}

void LastPivot::sort(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}

	int middle = partition(arr, left, right);
	sort(arr, left, middle);
	sort(arr, middle + 1, right);

}

int LastPivot::partition(int arr[], int left, int right)
{
	comparisons += (right - left - 1);

	swap(arr[left], arr[right - 1]);
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

void LastPivot::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif /* __LAST_PIVOT_H__ */
