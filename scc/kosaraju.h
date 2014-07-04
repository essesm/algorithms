#ifndef __KOSARAJU_H__
#define __KOSARAJU_H__

#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

class Vertex
{
public:
	bool visited;
	int leader;
	int finish;
	vector<int> linkedVertices;
	vector<int> rLinkedVertices;
};

class Graph
{
public:
	Graph(int N);
	~Graph();
	void addEdge(int v1, int v2);
	int* scc();

private:
	int t;
	int s;
	int N;
    int topFive[5];
	Vertex *G;
	Vertex *newG;

	void dfs(Vertex G[], int i, bool reverse);
	void dfsLoop(Vertex G[], bool reverse);
	void prepareSecondPass();
};

Graph::Graph(int N):N(N)
{
	G = new Vertex[N + 1];
	newG = new Vertex[N + 1];
}

Graph::~Graph()
{
	delete[] G;
	delete[] newG;
}

void Graph::dfs(Vertex G[], int i, bool reverse)
{
	G[i].visited = true;
	G[i].leader = s;

	vector<int> next;

	if (reverse)
	{
		next = G[i].rLinkedVertices;
	}
	else
	{
		next = G[i].linkedVertices;
	}

	for (unsigned int j = 0; j < next.size(); j++)
	{
		if (!G[next[j]].visited)
		{
			dfs(G, next[j], reverse);
		}
	}

	t++;
	G[i].finish = t;
}

void Graph::dfsLoop(Vertex G[], bool reverse)
{
	t = 0;
	s = 0;

	for (int i = N; i > 0; i--)
	{
		if (!G[i].visited)
		{
			s = i;
			dfs(G, i, reverse);
		}
	}
}

void Graph::addEdge(int v1, int v2)
{
	G[v1].linkedVertices.push_back(v2);
	G[v2].rLinkedVertices.push_back(v1);
}

void Graph::prepareSecondPass()
{
	for (int i = 1; i <= N; i++)
	{
		newG[i].visited = false;
		newG[i].finish = 0;
		newG[i].leader = 0;
		vector<int> temp;

		for (unsigned int j = 0; j < G[i].linkedVertices.size(); j++)
		{
			temp.push_back(G[G[i].linkedVertices[j]].finish);
		}

		newG[G[i].finish].linkedVertices = temp;
	}
}

int* Graph::scc()
{
	dfsLoop(G, true);
	prepareSecondPass();
	dfsLoop(newG, false);

	map<int, int> sccSizes;
	priority_queue<int> top;

	for (int i =  1; i <= N; i++)
	{
		sccSizes[newG[i].leader]++;
	}

	for (auto i = sccSizes.begin(); i != sccSizes.end(); i++)
	{
		top.push(i->second);
	}

	int size = 0;
	for (int i = 0; i < 5; i++)
	{
		if (top.empty())
		{
			size = 0;
		}
		else
		{
			size = top.top();
			top.pop();
		}

        topFive[i] = size;
	}

    return topFive;
}

#endif /* __KOSARAJU_H__ */
