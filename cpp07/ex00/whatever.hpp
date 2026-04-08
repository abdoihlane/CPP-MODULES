#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include "string.h"
template <typename H>

H max(H x, H y)
{
    if(x > y)
        return x;
    else 
        return y;
}
template <typename H>

H min(H x, H y)
{
    if(x < y)
        return x;
    else 
        return y;
}

template <typename H>
void swap(H &x, H &y){
    H z = x;
    x = y;
    y = z;
}
#endif