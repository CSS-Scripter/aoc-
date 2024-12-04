#ifndef LIST_UTIL_H
#define LIST_UTIL_H

#include <vector>

namespace ListUtil {
    template <typename T>
    inline int count(std::vector<T> arr, T el) {
        int count { 0 };
        for (size_t i { 0 }; i < arr.size(); ++i)
        {
            if (arr[i] == el) ++count;
        }
        
        return count;
    }
}

#endif
