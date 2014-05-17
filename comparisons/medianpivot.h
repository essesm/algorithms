#ifndef __MEDIAN_PIVOT_H__
#define __MEDIAN_PIVOT_H__

class MedianPivot
{
	public:
		long medianPivot(int arr[], int size);

	private:
		void sort(int arr[], int size);
		void sort(int arr[], int left, int right);
		int partition(int arr[], int left, int right);
		void swap(int &x, int &y);
		long comparisons;
		void setPivot(int arr[], int left, int right);
		int min(int a, int b);
		int max(int a, int b);
};

long MedianPivot::medianPivot(int arr[], int size)
{
	comparisons = 0;
	sort(arr, size);

	return comparisons;
}

void MedianPivot::sort(int arr[], int size)
{
	sort(arr, 0, size);
}

void MedianPivot::sort(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}

	int middle = partition(arr, left, right);
	sort(arr, left, middle);
	sort(arr, middle + 1, right);

}

int MedianPivot::partition(int arr[], int left, int right)
{
	comparisons += (right - left - 1);

	setPivot(arr, left, right);
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

void MedianPivot::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void MedianPivot::setPivot(int arr[], int left, int right)
{
	int t1 = arr[left];
	int t2 = arr[right - 1];
	int t3 = arr[left + (right - 1 - left) / 2];

	int median = max(min(t1, t2), min(max(t1, t2), t3));

	if (median == t1)
	{
		return;
	}

	if (median == t2)
	{
		swap(arr[left], arr[right - 1]);
		return;
	}

	if (median == t3)
	{
		swap(arr[left], arr[left + (right - 1 - left) / 2]);
		return;
	}
}

int MedianPivot::max(int a, int b)
{
	return a > b ? a : b;
}

int MedianPivot::min(int a, int b)
{
	return a < b ? a : b;
}

#endif /* __MEDIAN_PIVOT_H__ */
