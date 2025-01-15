#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#define MAX_DIM 10

class Vector
{
    public:
        Vector();
        Vector(int dim);
        Vector(int dim, double val);
        void Imprimir();
        void Capturar();
        Vector Sumar(Vector v);
        Vector Restar(Vector v);
        double ProductoPunto(Vector v);
        Vector ProductoPorEscalar(double escalar);
        double NormaV();

    private:
        int dimension;
        double components[10];
};

#endif // !VECTOR_HPP_INCLUDED
