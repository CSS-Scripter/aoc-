#ifndef MAP_H
#define MAP_H

#include "Guard.h"

#include <vector>
#include <iostream>

class Map {
private:
    enum TileType {
        empty = 0,
        visited,
        obstacle,
    };

    std::vector<std::vector<TileType>> m_map { };
    Guard m_guard {0, 0};
    Optional<Pair<size_t>> m_tmpObstacle { };

public:
    Map() = default;

    bool step();
    int countVisited();
    bool isInLoop();
    void reset();
    void resetTmpObstacle();
    void setTmpObstacle(Pair<size_t> pos);

    std::vector<Pair<size_t>> getSteps();

    friend std::istream& operator>>(std::istream& input, Map& val);
    friend std::ostream& operator<<(std::ostream& output, const Map& val);
};

#endif
