#include <iostream>

#include "../Headers/Vector.hpp"

Vector::Vector()
{
    dimension = 7;
    for(int i = 0; i < dimension; ++i)
    {
        components[i] = 0;
    }
}

Vector::Vector(int dim)
{
    dimension = dim;
    for(int i = 0; i < dimension; ++i)
    {
        components[i] = 0;
    }
}

void Vector::Imprimir()
{
    std::cout << "(";
    for(int i = 0; i < dimension; ++i)
    {
        std::cout << components[i] << ", ";
    }
    std::cout << "\b\b)" << std::endl;
};
