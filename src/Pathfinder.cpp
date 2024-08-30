#include "Pathfinder.h"
#include <algorithm>

double Pathfinder::heuristic(int x1, int y1, int x2, int y2) {
    // Using Euclidean distance as the heuristic
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

std::vector<Node*> Pathfinder::getNeighbors(const Map& map, Node* node) {
    std::vector<Node*> neighbors;
    int x = node->x;
    int y = node->y;

    const std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W

    for (const auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 0 && nx < map.getWidth() && ny >= 0 && ny < map.getHeight() && map.isWalkable(nx, ny)) {
            neighbors.push_back(new Node(nx, ny));
        }
    }

    return neighbors;
}

std::vector<std::pair<int, int>> Pathfinder::findPath(const Map& map, std::pair<int, int> start, std::pair<int, int> end) {
    std::vector<std::pair<int, int>> path;
    std::priority_queue<Node*, std::vector<Node*>, [](Node* a, Node* b) { return a->f > b->f; }> openList;
    std::unordered_map<int, std::unordered_map<int, bool>> closedList;

    Node* startNode = new Node(start.first, start.second);
    Node* endNode = new Node(end.first, end.second);
    openList.push(startNode);

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();
        
        closedList[current->x][current->y] = true;

        if (current->x == endNode->x && current->y == endNode->y) {
            // Reconstruct path
            Node* pathNode = current;
            while (pathNode != nullptr) {
                path.emplace_back(pathNode->x, pathNode->y);
                pathNode = pathNode->parent;
            }
            std::reverse(path.begin(), path.end());
            break;
        }

        for (Node* neighbor : getNeighbors(map, current)) {
            if (closedList[neighbor->x][neighbor->y]) {
                delete neighbor;
                continue;
            }

            double tentative_g = current->g + heuristic(current->x, current->y, neighbor->x, neighbor->y);

            bool inOpenList = std::find_if(openList.c.begin(), openList.c.end(), [neighbor](Node* n) { return n->x == neighbor->x && n->y == neighbor->y; }) != openList.c.end();

            if (!inOpenList || tentative_g < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = tentative_g;
                neighbor->h = heuristic(neighbor->x, neighbor->y, endNode->x, endNode->y);
                neighbor->f = neighbor->g + neighbor->h;

                if (!inOpenList) {
                    openList.push(neighbor);
                }
            } else {
                delete neighbor;
            }
        }
    }

    delete startNode;
    delete endNode;

    return path;
}
