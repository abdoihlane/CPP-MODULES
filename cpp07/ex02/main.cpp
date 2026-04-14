#include <iostream>
#include "Array.hpp"


int main()
{
    try
    {
        std::cout << "===== EMPTY ARRAY TEST =====" << std::endl;
        Array<int> a;
        std::cout << "Size: " << a.size() << std::endl;

        try {
            a[0]; // should throw
        } catch (std::exception &e) {
            std::cout << "Empty access: " << e.what() << std::endl;
        }

        std::cout << "\n===== BASIC INIT =====" << std::endl;
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i * 2;

        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;
        Array<int> c(b);
        b[0] = 100;

        std::cout << "Original: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Copy: ";
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;

        std::cout << "\n===== ASSIGNMENT =====" << std::endl;
        Array<int> d;
        d = b;

        b[1] = 200;

        std::cout << "Assigned: ";
        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << d[i] << " ";
        std::cout << std::endl;

        std::cout << "\n===== SELF ASSIGNMENT =====" << std::endl;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "\n===== CONST ARRAY TEST =====" << std::endl;
        const Array<int> e(b);
        std::cout << "Const access: ";
        for (unsigned int i = 0; i < e.size(); i++)
            std::cout << e[i] << " ";
        std::cout << std::endl;

        std::cout << "\n===== OUT OF BOUNDS TEST =====" << std::endl;
        try {
            std::cout << b[999] << std::endl;
        } catch (std::exception &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }

        std::cout << "\n===== NEGATIVE INDEX (IMPLICIT) =====" << std::endl;
        try {
            std::cout << b[(unsigned int)-1] << std::endl;
        } catch (std::exception &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }

        std::cout << "\n===== CHAINING ACCESS =====" << std::endl;
        b[2] = b[1] + b[3];
        std::cout << "b[2] = " << b[2] << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << "Fatal: " << e.what() << std::endl;
    }

    return 0;
}
