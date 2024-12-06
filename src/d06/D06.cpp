#include "D06.h"

void D06::initializeInput() {
    m_input >> m_map;
};

int D06::p1() {
    while (m_map.step()) { };
    return m_map.countVisited();
};

int D06::p2() {
    m_map.reset(); // Reset map

    int total { 0 };
    while (m_map.step()) {
        if (m_map.wouldEnterLoop()) ++total;
    };
    return total;
};
