#include <iostream>

#include "../Headers/Pila.hpp"

Pila::Pila() : size(-1)
{
     
}

void Pila::Push(double val)
{
    if(Full()) throw "Full stack";

    ++size;
    element[size] = val;
}

void Pila::Pop()
{
    if(Empty()) throw "Empty stack";

    --size;
}

double Pila::Top() const
{
    if (Empty()) throw "Empty stack";

    return element[size];
}

bool Pila::Empty() const
{
    return size == -1;
}

bool Pila::Full() const
{
    return size == (MAX - 1);
}

void Pila::Clear()
{
    size = -1;
}

void Pila::Print() const
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << element[i] << ", ";
    }

    std::cout << "\b\b <- Top";
}
