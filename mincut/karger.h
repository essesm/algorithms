#ifndef __KARGER_H__
#define __KARGER_H__

#include <vector>
#include <set>
#include <utility>
#include <random>

using namespace std;

class KargerGraph
{
public:
	int minCut();
	void addEdge(pair<int, int> edge);

private:
	int minCutTrial();
	set<int> vertices;
	vector<pair<int, int> > edges;
	void collapseEdge(pair<int, int> edge, vector<pair<int, int> > &e, set<int> &v);
};

int KargerGraph::minCut()
{
	int ans = minCutTrial();
	int temp;

	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		temp = minCutTrial();

		if (temp < ans)
		{
			ans = temp;
		}
	}

	return ans;
}

int KargerGraph::minCutTrial()
{
	set<int> v = vertices;
	vector<pair<int, int> > e = edges;

	while (v.size() > 2)
	{
		collapseEdge(e[rand() % e.size()], e, v);
	}

	return e.size();
}

void KargerGraph::addEdge(pair<int, int> edge)
{
	vertices.insert(edge.first);
	vertices.insert(edge.second);
	edges.push_back(edge);
}

void KargerGraph::collapseEdge(pair<int, int> edge, vector<pair<int, int> > &e, set<int> &v)
{
	int highNode = max(edge.first, edge.second);
	int lowNode = min(edge.first, edge.second);

	v.erase(highNode);
	
	unsigned int i = 0;
	while (i < e.size())
	{
		if (e[i].first == highNode)
		{
			e[i].first = lowNode;
		}

		if (e[i].second == highNode)
		{
			e[i].second = lowNode;
		}

		if (e[i].first == e[i].second)
		{
			e.erase(e.begin() + i);
			continue;
		}

		i++;
	}
}

#endif /* __KARGER_H__ */
