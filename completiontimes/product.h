#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <algorithm>
#include <vector>

class GoodScheduler 
{
public:
	long minWeight();
	void addJob(double weight, double length);

private:
	class Job
	{
	public:
		Job(double weight, double length);
		int weight;
		int length;
		double score;
	};

	class JobCompare
	{
	public:
		bool operator()(const Job &i, const Job &j);
	} comp;

	std::vector<Job> jobs;
	int jobCounter;
};

void GoodScheduler::addJob(double weight, double length)
{
	jobs.push_back(Job(weight, length));
}

GoodScheduler::Job::Job(double weight, double length):weight(weight), length(length),
	score(weight / length)
{

}

bool GoodScheduler::JobCompare::operator()(const Job &i, const Job &j)
{
	return i.score > j.score;
}

long GoodScheduler::minWeight()
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

#endif /* __PRODUCT_H__ */
