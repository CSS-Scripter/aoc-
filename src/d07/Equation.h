#ifndef EQUATION_H
#define EQUATION_H

#include <cstdint>
#include <vector>
#include <iostream>

class Equation
{
private:
    uint64_t m_result { };
    std::vector<uint64_t> m_values { };

public:
    Equation() = default;

    bool hasSolution();

    inline uint64_t getResult() { return m_result; };

private:
    uint64_t getLowerBound();
    uint64_t getUpperBound();

public:
    friend std::ostream& operator<<(std::ostream& out, Equation val);
    friend std::istream& operator>>(std::istream& in, Equation& val);
};

#endif
