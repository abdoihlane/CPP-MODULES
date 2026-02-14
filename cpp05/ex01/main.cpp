#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat b1("CROCO", 2);
        std::cout << b1 << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("DEER", 1);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}