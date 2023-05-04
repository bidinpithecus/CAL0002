#include "Graph.hpp"

int main() {
    Graph g(8);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 5, 3);
    g.addEdge(2, 6, 12);
    g.addEdge(4, 7, 9);

	int src = 0;
	int dest = 7;

	ivPair result = g.shortestPath(src, dest);

    cout << "The shortest distance from " << src  << " to " << dest << " is: " << result.first << endl;

	for(iPair vertex : result.second) {
		cout << "(" << vertex.first << ", " << vertex.second << ")" << endl;
	}

	g.dot(result.second);

    return 0;
}
