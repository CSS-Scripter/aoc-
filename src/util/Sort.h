#ifndef SORT_H
#define SORT_H

#include <vector>

namespace Sort {

    template <typename T>
    inline void selectionSort(std::vector<T>& arr)
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
}

#endif
