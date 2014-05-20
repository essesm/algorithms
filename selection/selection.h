#ifndef __SELECT_H__
#define __SELECT_H__

class Select
{
	public:
		int select(int arr[], int size, int idx);

	private:
		int partition(int arr[], int left, int right);
		void swap(int &x, int &y);
};

int Select::select(int arr[], int size, int idx)
{
	if (size == 1)
	{
		return arr[0];
	}

	int pivot = partition(arr, 0, size);

	if (pivot > idx)
	{
		return select(arr, pivot, idx);
	}

	if (pivot < idx)
	{
		return select(arr + pivot + 1, size - pivot - 1, idx - pivot - 1);
	}

	return arr[pivot];
}

int Select::partition(int arr[], int left, int right)
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

void Select::swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif /* __SELECT_H__ */
