#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <string>
class ScalarConverter {
private:
    ScalarConverter(); 
    ~ScalarConverter();
public:
    static void convert(const std::string &word);
};
#endif