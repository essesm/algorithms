#include "max.h"
#include <cassert>

using namespace std;

int main()
{
	Max m;
	int arr1[] = {1, 2, 3, 4, 5, 9, 8};
	int arr2[] = {1, 2, 3, 4, 5, 6, 7};
	int arr3[] = {7, 6, 5, 4, 3, 2, 1};
	int size = 7;

	assert(m.max(arr1, size) == 9);
	assert(m.max(arr2, size) == 7);
	assert(m.max(arr3, size) == 7);

	int arr4[] = { 1 };
	size = 1;
	
	assert(m.max(arr4, size) == 1);

	int arr5[] = {1, 2};
	int arr6[] = {2, 1};
	size = 2;

	assert(m.max(arr5, size) == 2);
	assert(m.max(arr6, size) == 2);
}
