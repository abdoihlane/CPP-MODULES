#include "Base.hpp"
#include "identify.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p)
{
    try {
        Base &snape = dynamic_cast<A&>(p);
        (void)snape;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception badcast){
    }
    try {
        Base &snape = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)snape;
        return;

    }
    catch (std::exception badcast){
    }
    try {
        Base &snape = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)snape;
        return;
    }
    catch (std::exception badcast){
    }
    std::cout << "Unknown Type" << std::endl;
}