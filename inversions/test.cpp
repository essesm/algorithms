#include "inversions.h"
#include <cassert>

using namespace std;

int main()
{
	int size = 6;
	int arr1[] = { 1, 2, 3, 4, 5, 6 };
	int arr2[] = { 6, 5, 4, 3, 2, 1 };

	Inversions in;
	assert(in.count(arr1, size) == 0);
	assert(in.count(arr2, size) == 15);
}
