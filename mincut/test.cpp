#include "karger.h"
#include <fstream>
#include <sstream>
#include <cassert>

int main()
{
	KargerGraph g1;
	g1.addEdge(make_pair(1, 2));
	g1.addEdge(make_pair(1, 3));
	g1.addEdge(make_pair(1, 4));
	g1.addEdge(make_pair(1, 5));
	g1.addEdge(make_pair(2, 3));
	g1.addEdge(make_pair(2, 4));
	g1.addEdge(make_pair(2, 5));
	g1.addEdge(make_pair(3, 4));

	assert(g1.minCut() == 2);

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
			if (v1 < v2)
			{
				g.addEdge(make_pair(v1, v2));
			}
		}
	}

	assert(g.minCut() == 17);
}
