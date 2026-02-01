#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        // Bureaucrat b2("Bob", 151); 
        // std::cout << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 0);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}