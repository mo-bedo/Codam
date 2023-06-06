#ifndef ITER_HPP
#define ITER_HPP

#include <cstdio>

template <typename T, typename TFunction>
void    iter (T * array, int length, void (*func)(TFunction &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

#endif			// ITER_HPP
