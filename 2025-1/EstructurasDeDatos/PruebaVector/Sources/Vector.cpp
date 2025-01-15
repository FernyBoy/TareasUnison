#include <iostream>
#include <cmath>

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

Vector::Vector(int dim, double val)
{
    dimension = dim;
    for(int i = 0; i < dimension; ++i)
    {
        components[i] = val;
    }
}

void Vector::Imprimir()
{
    std::cout << "(";
    for(int i = 0; i < dimension; ++i)
    {
        std::cout << components[i] << ", ";
    }
    std::cout << "\b\b)";
};

void Vector::Capturar()
{
    for(int i = 0; i < dimension; ++i)
    {
        std::cout << "Componente " << i+1 << ": ";
        std::cin >> components[i];
    }
}

Vector Vector::Sumar(Vector v)
{
    if(dimension != v.dimension) throw "Vectores incompatibles para la suma";

    Vector s(dimension);

    for(int i = 0; i < s.dimension; i++)
    {
        s.components[i] = components[i] + v.components[i];
    }

    return s;
}

Vector Vector::Restar(Vector v)
{
    if(dimension != v.dimension) throw "Vectores incompatibles para la resta";

    Vector s(dimension);

    for(int i = 0; i < s.dimension; i++)
    {
        s.components[i] = components[i] - v.components[i];
    }

    return s;
}

double Vector::ProductoPunto(Vector v)
{
    if(dimension != v.dimension) throw "Vectores incompatibles para el producto punto";

    double result = 0;

    for(int i = 0; i < dimension; i++)
    {
        result += components[i] * v.components[i];
    }

    return result;
}

Vector Vector::ProductoPorEscalar(double escalar)
{
    Vector s(dimension);

    for(int i = 0; i < dimension; i++)
    {
        s.components[i] = components[i] * escalar;
    }

    return s;
}

double Vector::NormaV()
{
    double sum = 0;

    for(int i = 0; i < dimension; ++i)
    {
        sum += components[i] * components[i];
    }

    return sqrt(sum);
}
