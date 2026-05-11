#include "easyfind.hpp"
#include "iostream"


int main()
{
    std::vector<int> container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    try{
        easyfind(container,1);
        std::cout << "value found" << std::endl;

    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 1;
}