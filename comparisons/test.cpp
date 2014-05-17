#include "firstpivot.h"
#include <cassert>

using namespace std;

int main()
{
	int size = 10;
	int a1[] = {3, 9, 8, 4, 6, 10, 2, 5, 7, 1};
	FirstPivot fp;

	fp.firstPivot(a1, size);
//	assert(fp.firstPivot(a1, size) == 25);

	return 0;
}
