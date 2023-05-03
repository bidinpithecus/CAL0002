#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
	int V;
	list<pair<int, int> >* adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);

	void shortestPath(int s);
};

#endif
