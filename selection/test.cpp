#include "selection.h"
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
	int size = 8;
	int a1[] = {4, 8, 2, 1, 3, 5, 6, 7};
	Select s;
	for (int i = 0; i < size; i++)
	{
	  	assert(s.select(a1, size, i) == i + 1);
	}

	size = 5;
	int a2[] = {5, 4, 3, 2, 1};
	for (int i = 0; i < size; i++)
	{
	  	assert(s.select(a2, size, i) == i + 1);
	}

	size = 10;
	int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < size; i++)
	{
	  	assert(s.select(a3, size, i) == i + 1);
	}

	size = 1;
	int a5[] = { 1 };
	for (int i = 0; i < size; i++)
	{
	  	assert(s.select(a5, size, i) == i + 1);
	}

	size = 2;
	int a6[] = {2, 1};
	for (int i = 0; i < size; i++)
	{
	  	assert(s.select(a6, size, i) == i + 1);
	}

	return 0;
}
