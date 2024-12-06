#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template<typename T>
struct Pair {
    T first {};
    T second {};
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

#endif
