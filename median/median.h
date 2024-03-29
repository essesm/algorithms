#ifndef __MEDIAN_H__
#define __MEDIAN_H__

#include <queue>
#include <vector>

class Median
{
public:
	void insert(int val);
	int get();

private:
	std::priority_queue<int, std::vector<int>, std::less<int> > maxes;
	std::priority_queue<int, std::vector<int>, std::greater<int> > mins;
};

void Median::insert(int val)
{
	if (!maxes.empty() && val < maxes.top())
	{
		maxes.push(val);
	}
	else
	{
		mins.push(val);
	}

	if (maxes.size() > mins.size() + 1)
	{
		mins.push(maxes.top());
		maxes.pop();
	}
	else if (mins.size() > maxes.size() + 1)
	{
		maxes.push(mins.top());
		mins.pop();
	}
}

int Median::get()
{
	if (mins.size() > maxes.size())
	{
		return mins.top();
	}

	return maxes.top();
}

#endif /* __MEDIAN_H__ */
