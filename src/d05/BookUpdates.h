#ifndef BOOK_UPDATES_H
#define BOOK_UPDATES_H

#include "SortRule.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <map>

class BookUpdates {
private:
    std::vector<int> m_updates {};

public:
    BookUpdates() = default;

    void sort(const std::map<int, SortRule>& rules);
    bool isSorted(const std::map<int, SortRule>& rules);
    int getMiddlePage();

    inline bool isEmpty() { return m_updates.size() == 0; };

    friend std::istream& operator>>(std::istream& input, BookUpdates& val);
};

inline std::istream& operator>>(std::istream& input, BookUpdates& val)
{
    val.m_updates.clear();
    std::string line;
    if (std::getline(input, line)) {
        std::istringstream iss(line);
        int x {};
        char c {};
        while (iss >> x) {
            val.m_updates.push_back(x);
            iss >> c;
        }
    }

    return input;
}

#endif
