#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <vector>

using level_t = std::vector<int>;

std::ifstream& operator>>(std::ifstream& input, level_t& val);
std::ostream& operator<<(std::ostream& output, level_t& val);

level_t cloneLevel(const level_t& toClone);

#endif
