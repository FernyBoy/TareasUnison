#include <iostream>

#include "../Headers/Pila.hpp"

template <typename Type>
Pila<Type>::Pila() : size(-1) {}

template <typename Type>
void Pila<Type>::Push(Type val)
{
    if(Full()) throw "Full stack";

    ++size;
    element[size] = val;
}

template <typename Type>
void Pila<Type>::Pop()
{
    if(Empty()) throw "Empty stack";

    --size;
}

template <typename Type>
Type Pila<Type>::Top() const
{
    if (Empty()) throw "Empty stack";

    return element[size];
}

template <typename Type>
bool Pila<Type>::Empty() const
{
    return size == -1;
}

template <typename Type>
bool Pila<Type>::Full() const
{
    return size == (MAX - 1);
}

template <typename Type>
void Pila<Type>::Clear()
{
    size = -1;
}

template <typename Type>
void Pila<Type>::Print() const
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << element[i] << ", ";
    }

    std::cout << "\b\b <- Top";
}
