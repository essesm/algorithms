#include <unordered_set>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
	vector<long> vals;
	unordered_set<long> table;
	ifstream infile("2sum.txt");
	long temp;
	int counter = 0;

	while (infile >> temp)
	{
		table.insert(temp);
	}

	for (unordered_set<long>::iterator i = table.begin(); i != table.end(); i++)
	{
		vals.push_back(*i);
	}

	for (int i = -10000; i <= 10000; i++)
	{
		for (unsigned int j = 0; j < vals.size(); j++)
		{
			if (table.count(i - vals[j]) > 0)
			{
				counter++;
				break;
			}
		}
	}

	assert(counter == 427);
}
