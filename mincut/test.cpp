#include "karger.h"
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

int main()
{
	KargerGraph g;
	ifstream infile("kargerMinCut.txt");
	string line;
	int v1;
	int v2;

	while (getline(infile, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2)
		{
			g.addEdge(v1, v2);
		}
	}

	assert(g.minCut() == 17);
}
