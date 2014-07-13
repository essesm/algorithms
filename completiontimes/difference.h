#ifndef __DIFFERENCE_H__
#define __DIFFERENCE_H__

#include <algorithm>
#include <vector>

class BadScheduler
{
public:
	long minWeight();
	void addJob(int weight, int length);

private:
	class Job
	{
	public:
		Job(int weight, int length);
		int weight;
		int length;
		int score;
	};

	class JobCompare
	{
	public:
		bool operator()(const Job &i, const Job &j);
	} comp;

	std::vector<Job> jobs;
	int jobCounter;
};

void BadScheduler::addJob(int weight, int length)
{
	jobs.push_back(Job(weight, length));
}

BadScheduler::Job::Job(int weight, int length):weight(weight), length(length),
	score(weight - length)
{

}

bool BadScheduler::JobCompare::operator()(const Job &i, const Job &j)
{
	if (i.score > j.score)
	{
		return true;
	}

	if (j.score > i.score)
	{
		return false;
	}

	return i.weight > j.weight;
}

long BadScheduler::minWeight()
{
	long ans = 0;
	int time = 0;
	sort(jobs.begin(), jobs.end(), comp);

	for (unsigned int i = 0; i < jobs.size(); i++)
	{
		time += jobs[i].length;
		ans += jobs[i].weight * time;
	}

	return ans;
}

#endif /* __DIFFERENCE_H__ */
