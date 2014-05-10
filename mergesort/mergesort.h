#ifndef __MERGESORT_H__
#define __MERGESORT_H__

class MergeSort
{
	public:
		void sort(int arr[], int size);

	private:
		void merge(int arr[], int a1[], int s1, int a2[], int s2);
};

void MergeSort::sort(int arr[], int size)
{
	if (size < 2)
	{
		return;
	}

	int *first = arr;
	int firstSize = size / 2;
	int *second = arr + size / 2;
	int secondSize = size - size / 2;

	sort(first, firstSize);
	sort(second, secondSize);

	merge(arr, first, firstSize, second, secondSize);
}

void MergeSort::merge(int arr[], int a1[], int s1, int a2[], int s2)
{
	int *temp = new int[s1 + s2];

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < s1 && j < s2)
	{
		if (a1[i] <= a2[j])
		{
			temp[k++] = a1[i++];
		}

		if (a2[j] <= a1[i])
		{
			temp[k++] = a2[j++];
		}
	}

	while (i < s1)
	{
		temp[k++] = a1[i++];
	}

	while (j < s2)
	{
		temp[k++] = a2[j++];
	}

	for (int i = 0; i < s1 + s2; i++)
	{
		arr[i] = temp[i];
	}

	delete[] temp;
}

#endif /* __MERGESORT_H__ */
