#include "D02.h"
#include "Level.h"


void D02::run() {
    std::vector<level_t> levels { parseInput() };

    std::cout << "== Day 2 =====\n";
    p1(levels);
    p2(levels);
    std::cout << "\n\n";
}


std::vector<level_t> D02::parseInput() {
    std::vector<level_t> levels { };
    std::vector<int> level { };
    while (m_input >> level) {
        levels.push_back(level);
    }

    return levels;
}


void D02::p1(std::vector<level_t> levels) {
    int safeCount { 0 };
    for (size_t i { 0 }; i < levels.size(); ++i)
    {
        if (isLevelSafe(levels.at(i))) ++safeCount;
    }

    std::cout << "Part 1: " << safeCount << '\n';
}

bool D02::isLevelSafe(level_t level) {
    if (level.at(0) == level.at(1)) return false;

    bool isIncreasing { level.at(0) < level.at(1) };

    for (size_t i { 0 }; i < level.size()-1; ++i) {
        int i1 { level.at(i)   };
        int i2 { level.at(i+1) };

        if (!isStepSafe(i1, i2, isIncreasing)) return false;
    }

    return true;
}

bool D02::isStepSafe(int x, int y, bool increasing) {
    int diff { increasing ? y - x : x - y };
    if (diff <= 0 || diff > 3) return false;
    return true;
}


void D02::p2(std::vector<level_t> levels) {
    int safeCount { 0 };
    for (size_t i { 0 }; i < levels.size(); ++i)
    {
        level_t level { levels[i] };
        if (isLevelSafeWithDampener(level)) safeCount++;
    }

    std::cout << "Part 2: " << safeCount << '\n';
}

bool D02::isLevelSafeWithDampener(level_t level) {
    for (size_t j { 0 }; j < level.size(); ++j) {
        level_t clone { cloneLevel(level) };
        clone.erase(clone.begin() + static_cast<int>(j));
        if (isLevelSafe(clone)) return true;
    }
    return false;
}
