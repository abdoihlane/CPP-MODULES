#ifndef EASYFIND_HPP    
#define EASYFIND_HPP    


#include <algorithm>
#include <vector>

template <typename T>
void easyfind(const T container, int value)
{
    std::vector<int>::const_iterator found = std::find(container.begin(),containter.end(),value);
    if(found == container.end())
        throw std::__throw_runtime_error("value not found");
}
#endif