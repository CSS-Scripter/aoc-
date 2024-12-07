#ifndef GUARD_H
#define GUARD_H

#include "../util/Pair.h"
#include "../util/Optional.h"

#include <vector>

class Guard {
public:
    enum Direction {
        up = 0,
        right,
        down,
        left,
        max_directions,
    };

private:
    // Vector, with pairs of coords, and direction
    std::vector<Pair<Pair<size_t>, Direction>> m_history { };

    int m_x { };
    int m_y { };
    int m_origin_x { };
    int m_origin_y { };
    Direction m_direction { };

public:
    Guard(int x, int y)
    : m_x { x }
    , m_y { y }
    , m_origin_x { x }
    , m_origin_y { y }
    { };

    void move();
    void turnRight();
    Pair<int> peek();
    Pair<size_t> getPosition() const;
    void reset();

    const std::vector<Pair<Pair<size_t>, Direction>> getHistory() const;
    bool isInLoop();

private:
    void addToHistory();
    Direction getTurnRightDirection();
};

#endif
