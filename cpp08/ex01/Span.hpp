#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
class Span
{
    private:
        unsigned int N;
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();
        Span& operator=(const Span& other);
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        template <typename InputIt>
        void addNumbers(InputIt first, InputIt last)
        {
            if (std::distance(first, last) + vec.size() > N)
                throw std::runtime_error("Exceeding maximum capacity");
            vec.insert(vec.end(), first, last);
        }
};
#endif
