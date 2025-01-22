#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <istream>
#include <ostream>

#define MAX_DIM 10

class Vector
{
    friend Vector operator*(double escalar, const Vector v);
    friend std::ostream & operator<<(std::ostream &salida, const Vector v);
    friend std::istream & operator>>(std::istream &entrada, Vector &v);

    public:
        // Un constructor de un solo parametro es un operador de conversion del tipo de parametro al tipo de la clase
        explicit Vector(int dim = MAX_DIM, double val = 0);
        
        int ObtenerDimension() const;
        void Imprimir() const;
        void Capturar();

        Vector operator+(const Vector v) const;
        Vector operator-(const Vector v) const;
        double operator*(const Vector v) const;
        Vector operator*(const double escalar) const;
        double operator[](int i) const;
        double & operator[](int i);
        double NormaV() const;

    private:
        int dimension;
        double components[10];
        
        // Metodos de utileria
        void EstablecerDim(int dim);
};

#endif // !VECTOR_HPP_INCLUDED
