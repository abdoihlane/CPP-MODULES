#ifndef ITER_HPP
#define ITER_HPP

template <typename H>

void iter(H *adress, int lenght , void (*f)(H  &))
{
    int i = 0;
    while(i < lenght)
        {
            f(adress[i]);
            i++;
        }
}

template <typename T>
void iter(T *array, const int length, void (*func)(const T &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}
#endif