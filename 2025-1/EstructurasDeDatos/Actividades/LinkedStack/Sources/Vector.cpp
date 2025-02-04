/**
*   \file   Stack.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#include <cmath>
#include <new>

#include "../Headers/Vector.hpp"

// El metodo destructor no tiene tipo de valor devuelto, se llama igual que la clase pero con una tilde al final de la clase,
// se invoca automaticamente al temrinar el ambito del objeto
// no recive parametros, por lo tanto, no pueden ser sobrecargagos
// y sirve para reestrablecer los recursos que se hayan solicitado con el constructor
//
// Todo metodo no estatico de una clase tiene acceso a un puntero de autoreferencia al objeto que la llame
//
// Los constructores son los unicos que aceptan inicializadores

Vector::Vector(const Vector &v) : components(NULL)
{
    *this = v;
}

Vector::~Vector()
{
    delete [] components; 
}

Vector & Vector::operator=(const Vector &v)
{
    if(this == &v) return *this;

    delete [] components;
    dimension = v.dimension;

    try 
    {
        components = new double[dimension];

        for(int i = 0; i < dimension; ++i)
        {
            components[i] = v[i];
        }
    }catch(std::bad_alloc &) 
    {
        throw "Problemas de asignaci\242n de memoria";
    }

    return *this;
}

Vector::Vector(int dim /* = MAX_DIM */, double val /* = 0 */)
{
    EstablecerDim(dim);

    try 
    {
        components = new double[dim];

        for(int i = 0; i < dimension; ++i)
        {
            components[i] = val;
        }
    }catch(std::bad_alloc &) 
    {
        throw "Problemas de asignaci\242n de memoria";
    }
}

int Vector::ObtenerDimension() const
{
    return dimension;
}

void Vector::Imprimir() const
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

Vector Vector::operator+(const Vector v) const
{
    if(dimension != v.dimension) throw "Vectores incompatibles para la suma";

    Vector s(dimension);

    for(int i = 0; i < s.dimension; i++)
    {
        s.components[i] = components[i] + v.components[i];
    }

    return s;
}

Vector Vector::operator-(const Vector v) const
{
    if(dimension != v.dimension) throw "Vectores incompatibles para la resta";

    Vector s(dimension);

    for(int i = 0; i < s.dimension; i++)
    {
        s.components[i] = components[i] - v.components[i];
    }

    return s;
}

double Vector::operator*(const Vector v) const
{
    if(dimension != v.dimension) throw "Vectores incompatibles para el producto punto";

    double result = 0;

    for(int i = 0; i < dimension; i++)
    {
        result += components[i] * v.components[i];
    }

    return result;
}

Vector Vector::operator*(const double escalar) const
{
    Vector s(dimension);

    for(int i = 0; i < dimension; i++)
    {
        s.components[i] = components[i] * escalar;
    }

    return s;
}

double Vector::operator[](int i) const
{
    if (i < 0 || i >= dimension) throw "\326ndice invalido";

    return components[i]; 
}

double Vector::NormaV() const
{
    double sum = 0;

    for(int i = 0; i < dimension; ++i)
    {
        sum += components[i] * components[i];
    }

    return sqrt(sum);
}

//*********************************************
//     Metodos externos
//*********************************************

std::ostream & operator<<(std::ostream &salida, const Vector v)
{
    salida << "(";
    for(int i = 0; i < v.dimension; ++i)
    {
        salida << v.components[i] << ", ";
    }
    salida << "\b\b)";
    
    return salida;
}

std::istream & operator>>(std::istream &entrada, Vector &v)
{
    for(int i = 0; i < v.dimension; ++i)
    {
        std::cout << "Componente " << i+1 << ": ";
        entrada >> v.components[i];
    }

    return entrada;
}

Vector operator*(double escalar, const Vector v)
{
    Vector r(v.dimension);

    for(int i = 0; i < v.dimension; ++i)
    {
        r.components[i] = v.components[i] * escalar;
    }

    return r;
}



//*********************************************
//     Metodos de utilería
//*********************************************
void Vector::EstablecerDim(int dim)
{
    if(dim < 1) throw "Dimension invalida";
    
    dimension = dim;
}
