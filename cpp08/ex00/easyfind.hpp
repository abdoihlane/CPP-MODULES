#ifndef EASYFIND_HPP    
#define EASYFIND_HPP    

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept> 

template <typename T>
void easyfind(const T& container, int value)
{
    typename T::const_iterator found =
        std::find(container.begin(), container.end(), value);

    if (found == container.end())
        throw std::runtime_error("value not found");
}

#endif