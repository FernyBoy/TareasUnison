#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#define MAX_DIM 10

class Vector
{
    friend Vector operator*(double escalar, const Vector v);

    public:
        Vector();
        Vector(int dim);
        Vector(int dim, double val);
        
        int ObtenerDimension() const;
        void Imprimir() const;
        void Capturar();

        Vector operator+(const Vector v) const;
        Vector operator-(const Vector v) const;
        double operator*(const Vector v) const;
        Vector operator*(const double escalar) const;
        double NormaV() const;

    private:
        int dimension;
        double components[10];
        
        // Metodos de utileria
        void EstablecerDim(int dim);
};

#endif // !VECTOR_HPP_INCLUDED
