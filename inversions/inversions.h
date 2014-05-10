#ifndef __INVERSIONS_H__
#define __INVERSIONS_H__

class Inversions
{
	public:
		int count(int arr[], int size);

	private:
		void sort(int arr[], int size);
		void merge(int arr[], int a1[], int s1, int a2[], int s2);
		int inversions;
};


int Inversions::count(int arr[], int size)
{
	inversions = 0;
	sort(arr, size);

	return inversions;
}

void Inversions::sort(int arr[], int size)
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

void Inversions::merge(int arr[], int a1[], int s1, int a2[], int s2)
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
			inversions += (s1 - i);
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

#endif /* __INVERSIONS_H__ */
