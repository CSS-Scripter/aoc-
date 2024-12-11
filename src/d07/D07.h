#ifndef D07_H
#define D07_H

#include "../util/Day.h"
#include "../util/Pair.h"

#include "Equation.h"

#include <vector>

class D07 : Day
{
private:
    std::vector<Equation> m_equations { };

public:
    D07(): Day { "07" } { };
    void run() { Day::run(); };

protected:
    void initializeInput();
    int p1();
    int p2();
};

#endif
