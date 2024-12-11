#include "D07.h"
#include "Equation.h"

void D07::initializeInput() {
    Equation e { };
    while (m_input >> e)
        m_equations.push_back(e);
};

int D07::p1() {
    // 12'506'062'871'850 is too low

    uint64_t total { };
    for (auto e : m_equations) {
        if (e.hasSolution())
            total += e.getResult();
    }
    std::cout << '\n' << total << '\n';
    return static_cast<int>(total);
};

int D07::p2() {
    return 0;
};
