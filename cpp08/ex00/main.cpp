#include "easyfind.hpp"
int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    try
    {
        easyfind(vec, 5);
        std::cout << "Value found!" << std::endl;
        easyfind(vec, 15);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
