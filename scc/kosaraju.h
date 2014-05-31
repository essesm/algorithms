#ifndef __KOSARAJU_H__
#define __KOSARAJU_H__

#include <queue>
#include <utility>
#include <map>

#include <iostream>

using namespace std;

class Vertex;

class Graph
{
public:
	Graph();
	void scc();
	void addEdge(pair<int, int> edge);

private:
	int finishingTime;
	int source;
	map<int, vector<int> > backwardEdges;
	map<int, vector<int> > forwardEdges;
	map<int, Vertex> vertices;
	map<int, int> sizes;
	void dfsLoop(map<int, Vertex> vertexMap, map<int, vector<int> > edges);
	void dfs(map<int, Vertex> vertexMap, map<int, vector<int> > edges, int vertex);
	void unvisitNodes();
	map<int, vector<int> > renameNodes();
};

class Vertex
{
public:
	Vertex();
	int t;
	int s;
	bool explored;
};

Graph::Graph():finishingTime(0), source(0)
{

}

void Graph::scc()
{
	dfsLoop(vertices, backwardEdges);
	
	cout << "Printing backward edges\n";
	for (auto i = backwardEdges.begin(); i != backwardEdges.end(); i++)
	{
		cout << "Node " << i->first << ": ";
		for (unsigned int j = 0; j < i->second.size(); j++)
		{
			cout << i->second[j] << " ";
		}
		cout << endl;
	}

	forwardEdges = renameNodes();
	unvisitNodes();

	cout << "Printing relabeled forward edges\n";
	for (auto i = forwardEdges.begin(); i != forwardEdges.end(); i++)
	{
		cout << "Node " << i->first << ": ";
		for (unsigned int j = 0; j < i->second.size(); j++)
		{
			cout << i->second[j] << " ";
		}
		cout << endl;
	}

	for (map<int, vector<int> >::reverse_iterator i = forwardEdges.rbegin(); i != forwardEdges.rend(); i++)
	{
		cout << "node is " << i->first << endl;
	}

	cout << "Calling second dfs\n";
	dfsLoop(vertices, forwardEdges);

	for (auto i = vertices.begin(); i != vertices.end(); i++)
	{
		cout << i->first << ": " << vertices[i->first].s << endl;
		sizes[i->second.s]++;
	}

	for (auto i = sizes.begin(); i != sizes.end(); i++)
	{
		cout << i->second << endl;
	}
}

void Graph::addEdge(pair<int, int> edge)
{
	forwardEdges[edge.first].push_back(edge.second);
	backwardEdges[edge.second].push_back(edge.first);
	vertices[edge.first] = Vertex();
	vertices[edge.second] = Vertex();
}

void Graph::dfsLoop(map<int, Vertex> vertexMap, map<int, vector<int> > edges)
{
	for (map<int, vector<int> >::reverse_iterator i = edges.rbegin(); i != edges.rend(); i++);
	for (map<int, Vertex>::reverse_iterator i = vertexMap.rbegin(); i != vertexMap.rend(); i++)
	{
		cout << "source is " << i->first << endl;
		if (!vertices[i->first].explored)
		{
			source = i->first;
			dfs(vertices, edges, i->first);
		}
	}
}

void Graph::dfs(map<int, Vertex> vertexMap, map<int, vector<int> > edges, int vertex)
{
	vertices[vertex].explored = true;
	vertices[vertex].s = source;

	for (unsigned int i = 0; i < edges[vertex].size(); i++)
	{
		if (!vertices[edges[vertex][i]].explored)
		{
			dfs(vertices, edges, edges[vertex][i]);
		}
	}

	finishingTime++;
	vertices[vertex].t = finishingTime;
}

map<int, vector<int> > Graph::renameNodes()
{
	map<int, vector<int> > newNodes;
	for (auto i = forwardEdges.begin(); i != forwardEdges.end(); i++)
	{
		for (unsigned int j = 0; j < i->second.size(); j++)
		{
			newNodes[vertices[i->first].t].push_back(vertices[i->second[j]].t);
		}
	}

	return newNodes;
}

void Graph::unvisitNodes()
{
	for (auto i = vertices.begin(); i != vertices.end(); i++)
	{
		i->second.explored = false;
	}
}

Vertex::Vertex():t(0), s(0), explored(false)
{

}

#endif /* __KOSARAJU_H__ */
