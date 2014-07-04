#ifndef __KARGER_H__
#define __KARGER_H__

#include <vector>
#include <set>
#include <utility>
#include <random>

class KargerGraph
{
public:
	int minCut();
	void addEdge(int e1, int e2);

private:
	int minCutTrial();
	std::set<int> vertices;
	std::vector<std::pair<int, int> > edges;
	void collapseEdge(std::pair<int, int> edge, std::vector<std::pair<int, int> > &e, std::set<int> &v);
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
	std::set<int> v = vertices;
	std::vector<std::pair<int, int> > e = edges;

	while (v.size() > 2)
	{
		collapseEdge(e[rand() % e.size()], e, v);
	}

	return e.size();
}

void KargerGraph::addEdge(int e1, int e2)
{
    if (e1 < e2)
    {
    	vertices.insert(e1);
    	vertices.insert(e2);
    	edges.push_back(std::make_pair(e1, e2));
    }
}

void KargerGraph::collapseEdge(std::pair<int, int> edge, std::vector<std::pair<int, int> > &e, std::set<int> &v)
{
	int highNode = std::max(edge.first, edge.second);
	int lowNode = std::min(edge.first, edge.second);

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
