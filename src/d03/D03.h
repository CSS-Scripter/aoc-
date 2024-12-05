#ifndef D03_H
#define D03_H

#include "../util/Day.h"
#include "../util/Optional.h"
#include "../util/Pair.h"

#include <vector>
#include <string>

class D03 : Day
{
private:
    std::vector<std::string> m_lines {};

public:
    D03(): Day { "03" } {};
    void run() { Day::run(); };

protected:
    void p1();
    void p2();
    void initializeInput();

    bool findSubstring(std::string line, std::string substr, size_t startAt);
    Optional<Pair<int>> findMul(std::string line, size_t i);
    Optional<Pair<int>> findDigitUntilChar(std::string line, size_t i, char separator);
    int parseInt(char c);
    int constructInt(std::vector<int> buff);
};

#endif
