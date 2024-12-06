#ifndef D04_H
#define D04_H

#include "../util/Day.h"
#include "../util/Pair.h"

#include <vector>
#include <string>

class D04 : Day
{
private:
    std::vector<std::string> m_grid {};

public:
    D04(): Day { "04" } {};
    void run() { Day::run(); };

protected:
    void initializeInput();
    void p1();
    void p2();

private:
    bool checkXMAS(Pair<size_t> from, Pair<int> direction);
    bool checkX_MAS(Pair<size_t> from);
};

#endif