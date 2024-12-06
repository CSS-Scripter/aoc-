#include "Map.h"
#include "../util/Pair.h"

#include <iostream>
#include <string>
#include <sstream>


bool Map::step() {
    // Will guard go out of bounds?
    Pair<int> peek { m_guard.peek() };

    if (
        peek.first  < 0 ||
        peek.second < 0 ||
        peek.second >= static_cast<int>(m_map.size()) ||
        peek.first  >= static_cast<int>(m_map.at(0).size())
    ) return false;


    // Will guard hit an obstacle ?
    if (m_map.at(static_cast<size_t>(peek.second)).at(static_cast<size_t>(peek.first)) == Map::obstacle)
    {
        m_guard.turnRight();
    } else {
        m_guard.move();
        Pair<size_t> newPos { m_guard.getPosition() };
        m_map[newPos.second][newPos.first] = Map::visited;
    }
    return true;
}

int Map::countVisited() {
    int total { 0 };
    for (auto& row : m_map)
        for (Map::TileType tile : row)
            if (tile == Map::visited) ++total;
    
    return total;
}

bool Map::wouldEnterLoop() {
    return m_guard.wouldEnterLoop();
}

void Map::reset() {
    m_guard.reset();
    for (size_t y { 0 }; y < m_map.size(); ++y)
    {
        std::vector<Map::TileType> row { m_map.at(y) };
        for (size_t x { 0 }; x < row.size(); ++x)
        {
            if (m_guard.getPosition() == Pair<size_t>{ x, y }) row[x] = Map::visited;
            else if (row.at(x) == Map::visited) row[x] = Map::empty;
        }
    }
}


std::istream& operator>>(std::istream& input, Map& val)
{
    val.m_map.clear();
    std::string line {};
    while (std::getline(input, line) && !line.empty())
    {
        std::istringstream iss(line);
        std::vector<Map::TileType> tiles { };
        char tile { };
        while (iss >> tile) {
            if (tile == '.') tiles.push_back(Map::empty);
            else if (tile == '#') tiles.push_back(Map::obstacle);
            else if (tile == '^') {
                int x { static_cast<int>(tiles.size()) };
                int y { static_cast<int>(val.m_map.size()) };
                val.m_guard = {x, y};
                tiles.push_back(Map::visited);
            }
        }
        val.m_map.push_back(tiles);
    }

    return input;
};

std::ostream& operator<<(std::ostream& output, const Map& val)
{
    output << "MAP (" << val.m_map.size() << ", " << val.m_map.at(0).size() << ")\n";

    for (size_t y { 0 }; y < val.m_map.size(); ++y)
    {
        std::vector<Map::TileType> row { val.m_map.at(y) };
        for (size_t x { 0 }; x < row.size(); ++x)
        {
            Map::TileType tile { row.at(x) };
            Pair<size_t> guard { val.m_guard.getPosition() };
            if (guard.first == x && guard.second == y) output << '^';
            else if (tile == Map::empty)               output << '.';
            else if (tile == Map::obstacle)            output << '#';
            else if (tile == Map::visited)             output << 'X';
        }
        output << '\n';
    }

    return output;
}
