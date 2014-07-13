#include "prims.h"
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
	ifstream infile("edges.txt");
	int n;
	int m;
	int v1;
	int v2;
	int weight;

	infile >> n >> m;
	Prim p(n, m);

	for (int i = 0; i < m; i++)
	{
		infile >> v1 >> v2 >> weight;
		p.addEdge(v1, v2, weight);
	}

	assert(p.mst() == -3612829);
}
