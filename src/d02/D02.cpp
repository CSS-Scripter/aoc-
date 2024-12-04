#include "D02.h"
#include "Level.h"


void D02::initializeInput() {
    m_levels.clear();

    Level level { };
    while (m_input >> level) {
        m_levels.push_back(level);
    }
}

void D02::p1() {
    int safeCount { 0 };
    for (Level level : m_levels) {
        if (level.isSafe()) ++safeCount;
    }

    std::cout << "Part 1: " << safeCount << '\n';
}

void D02::p2() {
    int safeCount { 0 };
    for (Level level : m_levels)
    {
        if (level.isSafeWithDampener()) safeCount++;
    }

    std::cout << "Part 2: " << safeCount << '\n';
}

