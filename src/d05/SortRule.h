#ifndef SORT_RULE_H
#define SORT_RULE_H

#include <vector>
#include <fstream>

class SortRule {
private:
    std::vector<int> m_lower { };

public:
    SortRule() = default;

    // check (v in m_lower)
    bool isLower(int v) {
        for (int l : m_lower) {
            if (l == v) return true;
        }
        return false;
    }

    void add(int v) {
        m_lower.push_back(v);
    }
};

#endif
