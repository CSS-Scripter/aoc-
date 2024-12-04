#include "Day.h"

void Day::run() {
    std::cout << "=== Day " << m_day << " =======\n";
    initializeInput();
    p1();
    p2();
    std::cout << "\n";
}
