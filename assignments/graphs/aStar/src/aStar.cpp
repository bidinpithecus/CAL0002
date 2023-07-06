#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct Node {
    std::pair<int, int> coordinate;
    Node* parent;
    double g;
    double h;
    double f;

    Node(std::pair<int, int> coord, Node* par = nullptr, double gVal = 0, double hVal = 0)
        : coordinate(coord), parent(par), g(gVal), h(hVal), f(gVal + hVal) {}

    bool operator==(const Node& other) const {
        return coordinate == other.coordinate;
    }
};

namespace std {
    template<> struct hash<Node> {
        size_t operator()(const Node& n) const {
            return hash<int>()(n.coordinate.first) ^ hash<int>()(n.coordinate.second);
        }
    };
}

void printMaze(const std::vector<std::vector<int>>& maze, const std::vector<std::pair<int, int>>& path) {
    std::vector<std::string> mazeStrings;
    for (const auto& row : maze) {
        std::string rowString;
        for (int cell : row) {
            rowString += (cell == 1) ? "  " : "|";
        }
        mazeStrings.push_back(rowString);
    }

    for (const auto& coordinate : path) {
        mazeStrings[coordinate.first][2 * coordinate.second] = 'P';
    }

    for (const auto& rowString : mazeStrings) {
        std::cout << rowString << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& coord) {
    os << "(" << coord.first << ", " << coord.second << ")";
    return os;
}

std::vector<Node*> getNeighbors(const std::vector<std::vector<int>>& maze, const Node* node) {
    std::vector<Node*> neighborhood;
    int x = node->coordinate.first;
    int y = node->coordinate.second;
    std::vector<std::pair<int, int>> offsets = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

    for (const auto& offset : offsets) {
        int newX = x - offset.first;
        int newY = y - offset.second;

        if (newX >= 0 && newX < static_cast<int>(maze.size()) && newY >= 0 && newY < static_cast<int>(maze[0].size()) && maze[newX][newY] == 1) {
            neighborhood.push_back(new Node({ newX, newY }, const_cast<Node*>(node)));
        }
    }

    return neighborhood;
}

double manhattan(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    int w = a.first;
    int x = a.second;
    int y = b.first;
    int z = b.second;
    return std::abs(w - y) + std::abs(x - z);
}

bool isDiagonal(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    int xA = a.first;
    int yA = a.second;
    int xB = b.first;
    int yB = b.second;
    return std::abs(xA - xB) == 1 && std::abs(yA - yB) == 1;
}

std::vector<std::pair<int, int>> astar(const std::vector<std::vector<int>>& maze, const std::pair<int, int>& start, const std::pair<int, int>& goal, double (*heuristic)(const std::pair<int, int>&, const std::pair<int, int>&)) {
    std::vector<Node*> frontier;
    std::unordered_set<Node*> interior;

    frontier.push_back(new Node(start));
    interior.insert(frontier[0]);

    while (!frontier.empty()) {
        std::sort(frontier.begin(), frontier.end(), [](const Node* a, const Node* b) {
            return a->f > b->f;
        });

        Node* current = frontier.back();
        frontier.pop_back();

        if (current->coordinate == goal) {
            std::vector<std::pair<int, int>> path;
            while (current) {
                path.push_back(current->coordinate);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        std::vector<Node*> neighbors = getNeighbors(maze, current);
        for (Node* neighbor : neighbors) {
            if (interior.find(neighbor) != interior.end()) {
                continue;
            }

            neighbor->g = current->g + (isDiagonal(neighbor->coordinate, current->coordinate) ? 1.4 : 1);
            neighbor->h = heuristic(neighbor->coordinate, goal);
            neighbor->f = neighbor->g + neighbor->h;

            if (std::find(frontier.begin(), frontier.end(), neighbor) == frontier.end()) {
                frontier.push_back(neighbor);
                interior.insert(neighbor);
            }
            else {
                auto it = std::find(frontier.begin(), frontier.end(), neighbor);
                if (neighbor->g < (*it)->g) {
                    *it = neighbor;
                }
            }
        }
    }

    return std::vector<std::pair<int, int>>();
}

int main() {
    std::vector<std::vector<int>> maze = {
        { 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1 }
    };
    std::pair<int, int> start = { 2, 1 };
    std::pair<int, int> goal = { 2, 5 };

    std::vector<std::pair<int, int>> path = astar(maze, start, goal, manhattan);
    for (const auto& coordinate : path) {
        std::cout << coordinate << " ";
    }
    std::cout << std::endl;
    printMaze(maze, path);
    return 0;
}
