#include "kosaraju.h"
#include <iostream>

int main()
{
	Graph g;
//	g.addEdge(make_pair(7, 1));
//	g.addEdge(make_pair(4, 7));
//	g.addEdge(make_pair(1, 4));
//	g.addEdge(make_pair(9, 7));
//	g.addEdge(make_pair(6, 9));
//	g.addEdge(make_pair(3, 6));
//	g.addEdge(make_pair(9, 3));
//	g.addEdge(make_pair(8, 6));
//	g.addEdge(make_pair(2, 8));
//	g.addEdge(make_pair(5, 2));
//	g.addEdge(make_pair(8, 5));
//	g.scc();

//	g.addEdge(make_pair(1, 2));
//	g.addEdge(make_pair(2, 1));
//	g.scc();

	g.addEdge(make_pair(1, 4));
	g.addEdge(make_pair(2, 8));
	g.addEdge(make_pair(3, 6));
	g.addEdge(make_pair(4, 7));
	g.addEdge(make_pair(5, 2));
	g.addEdge(make_pair(6, 9));
	g.addEdge(make_pair(7, 1));
	g.addEdge(make_pair(8, 5));
	g.addEdge(make_pair(8, 6));
	g.addEdge(make_pair(9, 7));
	g.addEdge(make_pair(9, 3));
	g.scc();
}
