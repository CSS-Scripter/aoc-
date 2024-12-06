#include "Guard.h"
#include "../util/Pair.h"
#include "../util/Optional.h"

Pair<int> Guard::peek() {
    switch (m_direction)
    {
        case up:    return { m_x, m_y-1 };
        case down:  return { m_x, m_y+1 };
        case left:  return { m_x-1, m_y };
        case right: return { m_x+1, m_y };
        default: return { m_x, m_y };
    }
}

Pair<size_t> Guard::getPosition() const {
    return { static_cast<size_t>(m_x), static_cast<size_t>(m_y) };
}

void Guard::move() {
    addToHistory();
    switch (m_direction)
    {
        case up:    m_y -= 1; break;
        case down:  m_y += 1; break;
        case left:  m_x -= 1; break;
        case right: m_x += 1; break;
        default: break;
    }
}

void Guard::turnRight() {
    addToHistory();
    m_direction = getTurnRightDirection();
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

// ! DOES NOT CHECK FOR OBSTACLES IN THE WAY
bool Guard::wouldEnterLoop() {
    Direction lookRight { getTurnRightDirection() };
    bool movingVertical { lookRight == Guard::up   || lookRight == Guard::down };
    bool movingPositive { lookRight == Guard::down || lookRight == Guard::right };

    // Static position is the one not changing when walking
    // When walking vertical, it's the x pos (first), otherwise the y pos, second
    size_t staticPos { movingVertical ? getPosition().first : getPosition().second };

    // Varying is the one that is moving
    size_t varingPos { movingVertical ? getPosition().second : getPosition().first };

    // Traverse history backwards
    for (Pair<Pair<size_t>, Direction> step : m_history) {
        // I also hate this
        if (step.second != lookRight) continue;

        size_t stepStatic { movingVertical ? step.first.first : step.first.second };
        size_t stepVaring { movingVertical ? step.first.second : step.first.first };

        if (
            stepStatic == staticPos && (
            (movingPositive && varingPos <= stepVaring) ||
            (!movingPositive && varingPos >= stepVaring))
        ) {
            return true;
        }
    }

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
