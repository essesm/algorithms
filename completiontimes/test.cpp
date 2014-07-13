#include "difference.h"
#include "product.h"
#include <cassert>
#include <fstream>

using namespace std;

int main()
{
	BadScheduler bs;
	GoodScheduler gs;
	ifstream infile("jobs.txt");
	int numJobs;
	int weight;
	int length;

	infile >> numJobs;

	for (int i = 0; i < numJobs; i++)
	{
		infile >> weight >> length;

		bs.addJob(weight, length);
		gs.addJob(weight, length);
	}

	assert(bs.minWeight() == 69119377652);
	assert(gs.minWeight() == 67311454237);
}
