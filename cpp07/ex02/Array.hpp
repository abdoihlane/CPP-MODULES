#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include "string.h"
#include <stdexcept>
#include <cstdlib> // For rand()
#include <iostream>
#include <ctime>

template <typename S> class Array{
    private :
        S *array;
        unsigned int s;
    public :
        Array();
        Array(const Array &other);
        Array(unsigned int numbers);
        ~Array();
        Array &operator=(const Array &);
        S &operator[](unsigned int i) const;
        unsigned int size() const;
        void check_exception(unsigned int i) const;
};

template <typename S>
Array<S>::Array(): array(NULL), s(0){};

template <typename S>
Array<S>::~Array(){
    delete[] array;
}

template <typename S>
Array<S>::Array(unsigned int numbers) : array(new S[numbers]),s(numbers){};

template <typename S>
Array<S>::Array(const Array &other):  array(new S[other.s]),s(other.s){
    for(unsigned int i =0; i < other.s; i++)
        array[i] = other.array[i];

};

template <typename S>
Array<S> &Array<S>::operator=(const Array &other){
    if (this != &other)
    {
        delete[] array;
        s = other.s;
        array = new S[other.s];
        for(unsigned int i =0; i < other.s; i++)
            array[i] = other.array[i];
    }
    return *this;
};

template <typename S>
void Array<S>::check_exception(unsigned int i) const
{
    if (i >= this->s)
        throw std::out_of_range("index is out of bounds");
}

template <typename S>
S &Array<S>::operator[](unsigned int i) const
{
    check_exception(i);
    return array[i];
}

template <typename S>
unsigned int Array<S>::size() const{
    return s;
}
#endif