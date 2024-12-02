#include "D01.h"

#include <iostream>
#include <vector>
#include <string>
#include <utility>

void D01::run()
{
    std::vector<int> l1 {};
    std::vector<int> l2 {};
    
    int i1 {};
    int i2 {};
    while (m_input >> i1 >> i2) {
        l1.push_back(i1);
        l2.push_back(i2);
    }

    sort(l1);
    sort(l2);

    std::cout << "== Day 1 =====\n";
    p1(l1, l2);
    p2(l1, l2);
    std::cout << "\n\n";
}


void D01::p1(std::vector<int> l1, std::vector<int> l2)
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


void D01::p2(std::vector<int> l1, std::vector<int> l2)
{
    int total { 0 };
    for (size_t i { 0 }; i < l1.size(); ++i)
    {
        int i1 { l1[i] };
        total += i1 * countOccurances(i1, l2);
    }

    std::cout << "Part 2: " << total << '\n';
}

// Selection sort (not fast, but easy)
void D01::sort(std::vector<int>& arr)
{
    for (size_t i{ 0 }; i < arr.size(); ++i)
    {
        size_t smallestIndex { i };
        for (size_t j { i+1 }; j < arr.size(); ++j)
        {
            if (arr[j] < arr[smallestIndex]) smallestIndex = j;
        }

        std::swap(arr[i], arr[smallestIndex]);
    }
}

// Assumes arr is sorted low to high
int D01::countOccurances(int find, std::vector<int> arr)
{
    int occurances { 0 };
    for (size_t i { 0 }; i < arr.size(); ++i)
    {
        if (arr[i] == find) occurances += 1;

        // assume the array is sorted lth
        // return when we are past the find, we will never find it
        if (arr[i] > find) return occurances;
    }
    return occurances;
}
