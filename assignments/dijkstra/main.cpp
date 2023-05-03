#include "Graph.hpp"

int main() {
    // Create a transportation system graph with 6 bus stops
    Graph g(6);

    // Add bus routes between bus stops with their travel times
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 5, 3);

    // Find the shortest path between stop 0 and stop 5
    int src = 0;
    g.shortestPath(src);

    return 0;
}
