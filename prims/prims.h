#ifndef __PRIM_H__
#define __PRIM_H__

#include <algorithm>
#include <vector>
#include <set>

class Prim
{
public:
	Prim(int N, int M);
	~Prim();
	void addEdge(int v1, int v2, int weight);
	int mst();

private:
	unsigned int numNodes;
	unsigned int numEdges;

	class Vertex
	{
	public:
		Vertex(int id, int key);
		int id;
		int key;
	};

	class Comp
	{
	public:
		bool operator()(const Vertex *v1, const Vertex *v2);
	} comp;
	
	std::vector<Vertex*> *adjacencyList;
};

Prim::Prim(int N, int M):numNodes(N), numEdges(M)
{
	adjacencyList = new std::vector<Vertex*>[N + 1];
}

Prim::~Prim()
{
	for (unsigned int i = 0; i <= numNodes; i++)
	{
		for (unsigned int j = 0; j < adjacencyList[i].size(); j++)
		{
			delete adjacencyList[i][j];
		}
	}

	delete[] adjacencyList;
	adjacencyList = 0;
}

void Prim::addEdge(int v1, int v2, int weight)
{
	adjacencyList[v1].push_back(new Vertex(v2, weight));
	adjacencyList[v2].push_back(new Vertex(v1, weight));
}

int Prim::mst()
{
	int ans = 0;
	std::set<int> verticesInMST;
	verticesInMST.insert(1);
	std::vector<Vertex*> priorityQueue;

	for (unsigned int i = 0; i < adjacencyList[1].size(); i++)
	{
		priorityQueue.push_back(adjacencyList[1][i]);
	}

	std::make_heap(priorityQueue.begin(), priorityQueue.end(), comp);
	int newVertex;

	while (verticesInMST.size() < numNodes)
	{
		newVertex = priorityQueue.front()->id;
		if (verticesInMST.find(newVertex) == verticesInMST.end())
		{
			ans += priorityQueue.front()->key;
		}

		std::pop_heap(priorityQueue.begin(), priorityQueue.end(), comp);
		priorityQueue.pop_back();
		verticesInMST.insert(newVertex);

		for (unsigned int i = 0; i < adjacencyList[newVertex].size(); i++)
		{
			if (verticesInMST.find(adjacencyList[newVertex][i]->id) == verticesInMST.end())
			{
				priorityQueue.push_back(adjacencyList[newVertex][i]);
			}
		}

		std::make_heap(priorityQueue.begin(), priorityQueue.end(), comp);
	}

	return ans;
}

Prim::Vertex::Vertex(int id, int key):id(id), key(key)
{

}

bool Prim::Comp::operator()(const Vertex *v1, const Vertex *v2)
{
	return v1->key > v2->key;
}

#endif /* __PRIM_H__ */
