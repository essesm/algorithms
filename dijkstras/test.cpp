#include "dijkstra.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

int main()
{
	string line;
	int v1;
	int v2;
	int weight;
	char c;

	/* TEST 1 */
	Graph g1(4);
	ifstream in1("test1.txt");

	while (getline(in1, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g1.addEdge(v1, v2, weight);
		}
	}

	int *v_ptr1 = g1.dijkstra();

//	for (int i = 1; i <= 4; i++)
//	{
//		cout << v_ptr1[i] << " ";
//	}
//	cout << endl;

	/* TEST 2 */
	Graph g2(4);
	ifstream in2("test2.txt");

	while (getline(in2, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g2.addEdge(v1, v2, weight);
		}
	}

	int *v_ptr2 = g2.dijkstra();

//	for (int i = 1; i <= 4; i++)
//	{
//		cout << v_ptr2[i] << " ";
//	}
//	cout << endl;

	/* TEST 3 */
	Graph g3(4);
	ifstream in3("test3.txt");

	while (getline(in3, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g3.addEdge(v1, v2, weight);
		}
	}

	int *v_ptr3 = g3.dijkstra();

//	for (int i = 1; i <= 4; i++)
//	{
//		cout << v_ptr3[i] << " ";
//	}
//	cout << endl;

	/* TEST 4 */
	Graph g4(4);
	ifstream in4("test4.txt");

	while (getline(in4, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g4.addEdge(v1, v2, weight);
		}
	}

	int *v_ptr4 = g4.dijkstra();

//	for (int i = 1; i <= 4; i++)
//	{
//		cout << v_ptr4[i] << " ";
//	}
//	cout << endl;

	/* TEST 5 */
	Graph g5(4);
	ifstream in5("test5.txt");

	while (getline(in5, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g5.addEdge(v1, v2, weight);
		}
	}

	int *v_ptr5 = g5.dijkstra();

//	for (int i = 1; i <= 4; i++)
//	{
//		cout << v_ptr5[i] << " ";
//	}
//	cout << endl;

	/* TEST 5 */
	Graph g6(7);
	ifstream in6("test6.txt");

	while (getline(in6, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g6.addEdge(v1, v2, weight);
		}
	}

	int *v_ptr6 = g6.dijkstra();

//	for (int i = 1; i <= 7; i++)
//	{
//		cout << v_ptr6[i] << " ";
//	}
//	cout << endl;

	/* REAL TEST */
	Graph g(200);
	ifstream infile("dijkstraData.txt");

	while (getline(infile, line))
	{
		stringstream ss;
		ss << line;
		ss >> v1;

		while (ss >> v2 >> c >> weight)
		{
			g.addEdge(v1, v2, weight);
		}
	}

	int *v = g.dijkstra();

	assert(v[7] == 2599);
	assert(v[37] == 2610);
	assert(v[59] == 2947);
	assert(v[82] == 2052);
	assert(v[99] == 2367);
	assert(v[115] == 2399);
	assert(v[133] == 2029);
	assert(v[165] == 2442);
	assert(v[188] == 2505);
	assert(v[197] == 3068);
}
