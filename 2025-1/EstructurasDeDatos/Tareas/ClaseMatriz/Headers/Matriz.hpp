#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <istream>

class Matriz
{
    friend std::ostream & operator<<(std::ostream &salida, const Matriz &m);
    friend std::istream & operator>>(std::istream &entrada, Matriz &m);

    friend Matriz operator*(double escalar, const Matriz &m);

    public:
        // Constructores
        explicit Matriz(int fil = 1, int col = 1);
        Matriz(const Matriz &m);
        Matriz & operator=(const Matriz &m);

        // Destructor
        ~Matriz();

        // Setters y getters
        double ObtenerValor(int fil, int col);
        void CapturarDimension();
        void CapturarMatriz();
        void ImprimirMatriz();
        void ImprimirMatriz(int fil, int col);

        // Operadores
        Matriz operator+(const Matriz &m) const;    
        Matriz operator-(const Matriz &m) const;
        Matriz operator*(const Matriz &m) const;
        Matriz operator*(const double escalar) const;

        // Funciones
        Matriz Traspuesta();
        double Determinante();
        Matriz Inversa();

        // Métodos de utilería
        void Redimensionar(int fil, int col);
        void LimpiarPantalla();

    private:
        int columnas;
        int filas;
        double **componentes;

        
};

#endif
