#include "converter.hpp"

bool isPseudoLiteral(const std::string &word) {
    if (word.empty())
        return false;
    return (word.compare("nan") == 0) || (word.compare("nanf") == 0) ||
           (word.compare("+inf") == 0) || (word.compare("-inf") == 0) ||
           (word.compare("+inff") == 0) || (word.compare("-inff") == 0);
}

void charhandle(double value, bool special) {
    if (special || value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
}

void inthandle(double value, bool special) {
    if (special || value < -2147483648 || value > 2147483647) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(value);
    std::cout << "int: " << i << std::endl;
}

void floathandle(double value, bool special, const std::string &input) {
    std::cout << "float: ";
    if (special) {
        if (input[input.size()-1] == 'f')
            std::cout << input;
        else
            std::cout << input << "f";
    } else {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;
}

void doublehandle(double value, bool special, const std::string &input) {
    std::cout << "double: ";
    if (special) {
        if (input[input.size()-1] == 'f')
            std::cout << input.substr(0, input.size()-1);
        else
            std::cout << input;
    } else {
        std::cout << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &word) {
    bool special = isPseudoLiteral(word);
    double value = 0;

    if (!special) {
        char* endptr;
        value = strtod(word.c_str(), &endptr);
        if (*endptr != '\0' && !(*endptr == 'f' && *(endptr+1) == '\0')) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    charhandle(value, special);
    inthandle(value, special);
    floathandle(value, special, word);
    doublehandle(value, special, word);
}