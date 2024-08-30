#include "Map.h"

Map::Map(int width, int height)
    : _width(width), _height(height), _grid(width, std::vector<CellType>(height, CellType::Walkable)) {}

Map::~Map() {}

int Map::getWidth() const {
    return _width;
}

int Map::getHeight() const {
    return _height;
}

Map::CellType Map::getCellType(int x, int y) const {
    return _grid[x][y];
}

void Map::setCellType(int x, int y, CellType type) {
    if (x >= 0 && x < _width && y >= 0 && y < _height) {
        _grid[x][y] = type;
    }
}

bool Map::isWalkable(int x, int y) const {
    return getCellType(x, y) == CellType::Walkable;
}

bool Map::hasHealthPack(int x, int y) const {
    return getCellType(x, y) == CellType::HealthPack;
}
