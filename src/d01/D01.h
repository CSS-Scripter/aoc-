#ifndef D01_H
#define D01_H

#include "../util/Day.h"

#include <vector>

class D01 : Day
{
private:
    std::vector<int> l1 {};
    std::vector<int> l2 {};

public:
    D01() : Day{ "01" } { };
    inline void run() { Day::run(); };

protected:
    void initializeInput();
    void p1();
    void p2();
};

#endif