#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

class Vector
{
    public:
        Vector();
        Vector(int dim);
        void Imprimir();

    private:
        int dimension;
        double components[10];
};

#endif // !VECTOR_HPP_INCLUDED
