#pragma once

template <typename T, typename F>
void iter(T* array, const size_t len, F func)
{
    for (std::size_t i = 0; i < len; i++)
        func(array[i]);
}