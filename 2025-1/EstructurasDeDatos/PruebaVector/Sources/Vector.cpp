#include <cmath>

#include "../Headers/Vector.hpp"

Vector::Vector(int dim /* = MAX_DIM */, double val /* = 0 */)
{
    EstablecerDim(dim);
    for(int i = 0; i < dimension; ++i)
    {
        components[i] = val;
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
//     Metodos externos
//*********************************************
void Vector::EstablecerDim(int dim)
{
    if(dim < 1 || dim > MAX_DIM) throw "Dimension invalida";
    
    dimension = dim;
}

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
