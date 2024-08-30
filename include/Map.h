#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility>

class Map {
public:
    enum class CellType { Walkable, Obstacle, HealthPack };

private:
    std::vector<std::vector<CellType>> _grid;
    int _width;
    int _height;

public:
    Map(int width, int height);
    ~Map();

    int getWidth() const;
    int getHeight() const;
    CellType getCellType(int x, int y) const;

    void setCellType(int x, int y, CellType type);
    bool isWalkable(int x, int y) const;
    bool hasHealthPack(int x, int y) const;
};

#endif
