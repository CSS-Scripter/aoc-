#include "D01.h"
#include "../util/ListUtil.h"

#include <iostream>
#include <vector>
#include <string>
#include <utility>


void D01::initializeInput()
{
    l1.clear();
    l2.clear();

    int i1 {};
    int i2 {};
    while (m_input >> i1 >> i2) {
        l1.push_back(i1);
        l2.push_back(i2);
    }

    ListUtil::selectionSort(l1);
    ListUtil::selectionSort(l2);
}


void D01::p1()
{
    int difference { 0 };
    for (size_t i { 0 }; i < l1.size(); ++i)
    {
        int i1 { l1.at(i) };
        int i2 { l2.at(i) };

        if (i1 > i2) difference += (i1 - i2);
        else difference += (i2 - i1);
    }

    std::cout << "Part 1: " << difference << '\n';
}


void D01::p2()
{
    int total { 0 };
    for (size_t i { 0 }; i < l1.size(); ++i)
    {
        int i1 { l1[i] };
        total += i1 * ListUtil::count<int>(l2, i1);
    }

    std::cout << "Part 2: " << total << '\n';
}
