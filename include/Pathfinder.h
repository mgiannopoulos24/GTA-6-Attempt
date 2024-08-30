#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Map.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

struct Node {
    int x, y;
    double f, g, h;
    Node* parent;
    Node(int x, int y) : x(x), y(y), f(0), g(0), h(0), parent(nullptr) {}
};

class Pathfinder {
public:
    static std::vector<std::pair<int, int>> findPath(const Map& map, std::pair<int, int> start, std::pair<int, int> end);

private:
    static double heuristic(int x1, int y1, int x2, int y2);
    static std::vector<Node*> getNeighbors(const Map& map, Node* node);
};

#endif 
