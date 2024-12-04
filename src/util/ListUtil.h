#ifndef LIST_UTIL_H
#define LIST_UTIL_H

#include <vector>

namespace ListUtil {
    template <typename T>
    inline int count(std::vector<T> arr, T el)
    {
        int count { 0 };
        for (size_t i { 0 }; i < arr.size(); ++i)
        {
            if (arr[i] == el) ++count;
        }
        
        return count;
    }


    template <typename T>
    inline void selectionSort(std::vector<T> arr)
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
