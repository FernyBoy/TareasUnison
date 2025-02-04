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
        explicit Matriz();
        explicit Matriz(int fil, int col);
        Matriz(const Matriz &m);
        Matriz & operator=(const Matriz &m);

        // Destructor
        ~Matriz();

        // Setters y getters
        void IniciarMatriz();
        void CapturarDimension();
        void CapturarMatriz();
        void ImprimirMatriz();
        void ImprimirMatriz(int fil, int col);

        // Operadores
        Matriz operator+(const Matriz &m) const;    
        Matriz operator-(const Matriz &m) const;
        Matriz operator*(const Matriz &m) const;
        Matriz operator*(const double escalar) const;
        double* operator[](int i);

        // Funciones
        Matriz Traspuesta();
        Matriz Inversa();

        // Métodos de utilería
        void Redimensionar(int fil, int col);
        static void LimpiarPantalla();
        double LongitudSegura();
        double LongitudPositiva();

    private:
        int columnas = 1;
        int filas = 1;
        double **componentes = nullptr;

        
};

#endif
