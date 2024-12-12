#ifndef D11_H
#define D11_H

#include "../util/Day.h"

#include <map>

class D11 : Day<uint64_t>
{
private:
    std::map<uint64_t, uint64_t> m_stones { };

public:
    D11() : Day{ "11" } { };
    void run() { Day::run(); };

protected:
    void initializeInput();
    uint64_t p1();
    uint64_t p2();

private:
    void blink();
    uint64_t findNumCount(uint64_t x);
    uint64_t countStones();
};

#endif
