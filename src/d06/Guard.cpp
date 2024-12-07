#include "Guard.h"
#include "../util/Pair.h"
#include "../util/Optional.h"

Pair<int> Guard::peek() {
    switch (m_direction)
    {
        case up:    return { m_x,   m_y-1 };
        case down:  return { m_x,   m_y+1 };
        case left:  return { m_x-1, m_y   };
        case right: return { m_x+1, m_y   };
        default:    return { m_x,   m_y   };
    }
}

Pair<size_t> Guard::getPosition() const {
    return { static_cast<size_t>(m_x), static_cast<size_t>(m_y) };
}

void Guard::move() {
    switch (m_direction)
    {
        case up:    m_y -= 1; break;
        case down:  m_y += 1; break;
        case left:  m_x -= 1; break;
        case right: m_x += 1; break;
        default: break;
    }
    addToHistory();
}

void Guard::turnRight() {
    m_direction = getTurnRightDirection();
    addToHistory();
}

Guard::Direction Guard::getTurnRightDirection() {
    switch (m_direction)
    {
        case up:    return right;
        case right: return down;
        case down:  return left;
        case left:  return up;
        default:    return up;
    }    
}

const std::vector<Pair<Pair<size_t>, Guard::Direction>> Guard::getHistory() const {
    return m_history;
}

bool Guard::isInLoop() {
    if (m_history.size() < 4) return false; // Can't be in a loop with less than 4 moves

    // Try and find our last move in the history
    Pair<Pair<size_t>, Direction> currentPos { getPosition(), m_direction };
    for (size_t i { m_history.size()-3 }; i --> 0 ;)
    {
        if (currentPos == m_history.at(i)) return true;
    }

    // We have not been in this exact location & direction
    // so we are not (yet) in a loop
    return false;
}

void Guard::reset() {
    m_history.clear();
    m_x = m_origin_x;
    m_y = m_origin_y;
    m_direction = up;
}

void Guard::addToHistory()
{
    m_history.push_back({ getPosition(), m_direction });
}
