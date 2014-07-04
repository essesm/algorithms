#include "kosaraju.h"
#include <fstream>
#include <cassert>

int main()
{
	ifstream infile("SCC.txt");
	Graph g(875714);
	int v1;
	int v2;

	while (infile >> v1 >> v2)
	{
		g.addEdge(v1, v2);
	}

	int *topFive = g.scc();

    assert(topFive[0] == 434821);
    assert(topFive[1] == 968);
    assert(topFive[2] == 459);
    assert(topFive[3] == 313);
    assert(topFive[4] == 211);
}
