#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 0x3f3f3f3f
#define DOT_MINIMUM_PATH "data/dijkstra.dot"
#define DOT_DFS_PATH "data/dfs.dot"

typedef pair<int, int> iPair;
typedef pair<int, vector<iPair>> ivPair;
typedef tuple<int, int, int> iituple;

class Graph {
	int V;
	list<pair<int, int>>* adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void dotDijkstra(vector<iPair> shortestPath);
	void dotDfs(vector<int> path);
	void printAdjacencies();

	ivPair dijkstra(int s, int d);
	vector<int> dfs(int s, int d);
	vector<int> dfsUtil(int v, bool visited[], int dest);
};

#endif
