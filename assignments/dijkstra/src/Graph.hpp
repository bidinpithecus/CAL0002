#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f
#define DOT_PATH "data/graph.dot"
#define SVG_PATH "data/graph.svg"

typedef pair<int, int> iPair;
typedef pair<int, vector<iPair>> ivPair;
typedef tuple<int, int, int> iituple;

class Graph {
	int V;
	list<pair<int, int>>* adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void dot(vector<iPair> shortestPath);
	void printAdjacencies();

	ivPair shortestPath(int s, int d);
};

#endif
