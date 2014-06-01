#include "kosaraju.h"
#include <fstream>

int main()
{
//	Graph g(9);
//	g.addEdge(7, 1);
//	g.addEdge(4, 7);
//	g.addEdge(1, 4);
//	g.addEdge(9, 7);
//	g.addEdge(6, 9);
//	g.addEdge(3, 6);
//	g.addEdge(9, 3);
//	g.addEdge(8, 6);
//	g.addEdge(2, 8);
//	g.addEdge(5, 2);
//	g.addEdge(8, 5);
//	g.scc();

//	Graph g(2);
//	g.addEdge(1, 2);
//	g.addEdge(2, 1);
//	g.scc();

//	Graph g(9);
//	g.addEdge(1, 4);
//	g.addEdge(2, 8);
//	g.addEdge(3, 6);
//	g.addEdge(4, 7);
//	g.addEdge(5, 2);
//	g.addEdge(6, 9);
//	g.addEdge(7, 1);
//	g.addEdge(8, 5);
//	g.addEdge(8, 6);
//	g.addEdge(9, 7);
//	g.addEdge(9, 3);
//	g.scc();

	ifstream infile("SCC.txt");
	Graph g(875714);
	int v1;
	int v2;

	while (infile >> v1 >> v2)
	{
		g.addEdge(v1, v2);
	}

	g.scc();
}
