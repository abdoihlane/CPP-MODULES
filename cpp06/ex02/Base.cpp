#include "Base.hpp"
#include <cstdlib> // For rand()
#include <iostream>
#include <ctime>
#include <cstdlib>

Base::~Base(){

};

Base * generate(void)
{
        std::srand(std::time(0));
        int randomNum = std::rand();
        std::cout << randomNum << std::endl;
        if(randomNum % 4 == 0)
            return new A;
        else if(randomNum % 4 == 1)
            return new B;
        else
            return new C;
    
}
