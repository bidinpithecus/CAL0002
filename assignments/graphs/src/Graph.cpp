#include "Graph.hpp"
#include <set>

Graph::Graph(int V) {
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::printAdjacencies() {
	for (int v = 0; v < V; ++v) {
		cout << "Vertex " << v << " has the following adjacencies:\n";
		for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
			int u = it->first;
			int w = it->second;
			cout << "\t- " << u << " (weight = " << w << ")\n";
		}
	}
}

void Graph::dotDijkstra(vector<iPair> shortestPath) {
    ofstream dotFile(DOT_MINIMUM_PATH);

    dotFile << "strict graph BusStops {" << endl;
    for (int v = 0; v < V; v++) {
        dotFile << "\tnode [shape = circle, style = filled, color = \"" << "#28d1e0" << "\"]; " << v << ";" << endl;
    }

    dotFile << endl;

    set<pair<int, int>> path;
    for (long unsigned int i = 0; i < shortestPath.size(); i++) {
        int v = shortestPath[i].first;
        int u = shortestPath[i].second;
        path.insert(make_pair(v, u));

        if (i == shortestPath.size() - 1) {
            path.insert(make_pair(u, v));
        }
    }

    for (int v = 0; v < V; ++v) {
        int i = 0;
        for (auto it = adj[v].begin(); it != adj[v].end(); it++, i++) {
            int u = it->first;
            int w = it->second;

            if (path.count(make_pair(v, u)) || path.count(make_pair(u, v))) {
                dotFile << "\t" << v << " -- " << u << " [color = \"#aa0000\", label = " << w << "];" << endl;
            } else {
                dotFile << "\t" << v << " -- " << u << " [label = " << w << "];" << endl;
            }
        }
    }

    dotFile << "}" << endl;

    dotFile.close();
}

void Graph::dotDfs(vector<int> path) {
    ofstream dotFile(DOT_DFS_PATH);

    dotFile << "strict graph BusStops {" << endl;
    for (int v = 0; v < V; v++) {
        if (find(path.begin(), path.end(), v) != path.end()) {
            dotFile << "\tnode [shape = circle, style = filled, color = \"" << "#aa0000" << "\"]; " << v << ";" << endl;
        } else {
            dotFile << "\tnode [shape = circle, style = filled, color = \"" << "#28d1e0" << "\"]; " << v << ";" << endl;
        }
    }

    dotFile << endl;

    for (int v = 0; v < V; ++v) {
        int i = 0;
        for (auto it = adj[v].begin(); it != adj[v].end(); it++, i++) {
            int u = it->first;
            dotFile << "\t" << v << " -- " << u << endl;
        }
    }

    dotFile << "}" << endl;

    dotFile.close();
}


ivPair Graph::dijkstra(int src, int dest) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> priorityQueue;

    vector<int> dist(V, INF);
    vector<vector<pair<int, int>>> paths(V);

    priorityQueue.push(make_pair(0, src));
    dist[src] = 0;
    paths[src].push_back(make_pair(src, 0));

    while (!priorityQueue.empty()) {
        int u = priorityQueue.top().second;
        priorityQueue.pop();

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                priorityQueue.push(make_pair(dist[v], v));
                paths[v] = paths[u];
                paths[v].push_back(make_pair(u, v));
            }
        }
    }

    vector<pair<int, int>> path;
    for (auto p : paths[dest]) {
		if (p.first != p.second) {
			path.push_back(make_pair(p.first, p.second));
		}
    }

    return make_pair(dist[dest], path);
}

vector<int> Graph::dfsUtil(int v, bool visited[], int dest) {
    visited[v] = true;
    vector<int> path = {v};

    if (v == dest) {
        return path;
    }

    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        int u = it->first;
        if (!visited[u]) {
            vector<int> subpath = dfsUtil(u, visited, dest);
            if (!subpath.empty()) {
                path.insert(path.end(), subpath.begin(), subpath.end());
                return path;
            }
        }
    }

    return {};
}

vector<int> Graph::dfs(int src, int dest) {
	bool visited[V];
	for (int i = 0; i < V; ++i) {
		visited[i] = false;
	}
    return dfsUtil(src, visited, dest);
}
