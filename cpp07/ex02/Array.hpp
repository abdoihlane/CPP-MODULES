#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include "string.h"
template <typename S> class Array{
    private :
        T *array;
        unsigned int s;
    public :
        Array();
        Array(const Array &);
        Array(unsigned int numbers);
        ~Array();
        Array &operator=(const Array &);
        S &operator[](unsigned int i);
        unsigned int size() const;
};

template <typename S>
Array<S>::Array(): array(new S[n]), s(n){};


template <typename S>
Array<S>::Array();

template <typename S>
Array<S>::Array();


#endif