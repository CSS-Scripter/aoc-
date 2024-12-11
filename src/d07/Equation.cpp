#include "Equation.h"

#include "../util/ListUtil.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>


bool Equation::hasSolution()
{
    // Lowest possible number is sum
    uint64_t lower { getLowerBound() };
    if (lower >= m_result) return lower == m_result;

    // Higher possible number is product
    uint64_t upper { getUpperBound() };
    if (upper <= m_result) return upper == m_result;

    if (m_values.size() == 2) return false; // should have been found at this point

    std::vector<std::string> operations {
        ListUtil::createCombinations(std::vector<char>{'+', '*'}, m_values.size()-1)
    };

    std::cout << '\n' << *this << '\n';
    for (auto operators : operations)
    {
        std::cout << "trying " << operators;
        uint64_t total { m_values.at(0) };
        for (size_t i { 0 }; i < m_values.size()-1; ++i)
        {
            char op { operators.at(i) };
            if (op == '+')
                total += m_values.at(i+1);
            else if (op == '*')
                total *= m_values.at(i+1);
            else
                std::cerr << "unknown operator found: " << op << '\n';
        }

        std::cout << " (= " << total << ")\n";
        if (total == m_result) {
            return true;
        }
    }

    std::cout << '\n' << *this;
    return false;
}


uint64_t Equation::getLowerBound()
{
    uint64_t total { 0 };
    for (uint64_t v : m_values) total += v;

    return total;
}

uint64_t Equation::getUpperBound()
{
    uint64_t total { 1 };
    for (uint64_t v : m_values) total *= v;

    return total;
}


std::ostream& operator<<(std::ostream& out, Equation val)
{
    out << val.m_result << ": ";
    for (auto v : val.m_values)
        out << v << " ";

    return out;
}


std::istream& operator>>(std::istream& in, Equation& val)
{
    val.m_values.clear();

    std::string line { };
    if (std::getline(in, line)) {
        std::istringstream iss(line);
        
        char s { }; // separator (:)
        iss >> val.m_result >> s;

        uint64_t x { };
        while (iss >> x) val.m_values.push_back(x);
    }

    return in;
}
