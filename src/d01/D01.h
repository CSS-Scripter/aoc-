#ifndef D01_H
#define D01_H

#include "../util/Day.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class D01 : Day
{
private:
    const std::string m_filename { "./src/inputs/01.txt" };
    std::ifstream m_input { m_filename };

public:
    D01() : Day("01.txt") { };

    void run();

private:
    void p1(std::vector<int> l1, std::vector<int> l2);
    void p2(std::vector<int> l1, std::vector<int> l2);
    void sort(std::vector<int>& arr);
    int  countOccurances(int find, std::vector<int> arr);
};

#endif
