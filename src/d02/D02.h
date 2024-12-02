#ifndef D02_H
#define D02_H

#include "Level.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class D02
{
private:
    const std::string m_filename { "./src/inputs/02.txt" };
    std::ifstream m_input { m_filename };

public:
    D02() {
        if (!m_input) std::cerr << "failed to open file " << m_filename;
    };

    ~D02() {
        if (m_input) m_input.close();
    };

    void run();

private:
    std::vector<level_t> parseInput();

    void p1(std::vector<level_t> levels);
    void p2(std::vector<level_t> levels);

    bool isLevelSafe(level_t level);
    bool isStepSafe(int x, int y, bool increasing);
    bool isLevelSafeWithDampener(level_t level);
};

#endif
