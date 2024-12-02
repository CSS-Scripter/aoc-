#include "Level.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::ifstream& operator>>(std::ifstream& input, level_t& val)
{
    val.clear();
    std::string line;
    if (std::getline(input, line)) {
        std::istringstream iss(line);
        int x {};
        while (iss >> x) val.push_back(x);
    }
    return input;
};

std::ostream& operator<<(std::ostream& out, level_t& val)
{
    for (size_t i { 0 }; i < val.size(); ++i)
    {
        out << val[i];
        if (i < val.size()-1) out << ", ";
    }
    return out;
}

level_t cloneLevel(const level_t& toClone) {
    level_t clone(toClone.size());
    std::copy(toClone.begin(), toClone.end(), clone.begin());
    return clone;
}
