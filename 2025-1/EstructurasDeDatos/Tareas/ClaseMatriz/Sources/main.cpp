#include <iostream>

#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::endl;

Matriz::Matriz(int fil, int col)
{
    Redimensionar(filas, columnas);

    try
    {
        componentes = new double *[fil];

        for(int i = 0; i < col; ++i)
        {
            componentes[i] = new double[col]; 
        }
        

    }catch(std::bad_alloc &)
    {
        throw "Problemas de asginación de memoria";
    }
}

/*
Matriz::Matriz(const Matriz &m)
{

}
*/

Matriz & Matriz::operator=(const Matriz &m)
{
    if(this == &m) return *this;

    for(int i = 0; i < filas; ++i) 
    {
        delete[] componentes[i];
    }

    delete[] componentes;

    filas = m.filas;
    columnas = m.columnas;
   
    try 
    {
        componentes = new double *[filas];

        for(int i = 0; i < filas; ++i)
        {
            componentes[i] = new double[columnas];

            for(int j = 0; j < columnas; ++j)
            {
                componentes[i][j] = m.componentes[i][j];
            }
        }
    }catch (std::bad_alloc &) 
    {
        throw "Problemas de asignación de memoria";
    }
}

Matriz::~Matriz()
{
    for(int i = 0; i < filas; ++i) 
    {
        delete[] componentes[i];
    }

    delete[] componentes;
}

/*
double Matriz::ObtenerValor(int fil, int col)
{
    
}
*/

void Matriz::ImprimirMatriz()
{
    for(int i = 0; i < filas; ++i) 
    {
        for(int j = 0; j < columnas; ++j)
        {
            cout << componentes[i][j] << ", ";
        }
        cout << "\b\b\n";
    }
}

/*
Matriz Matriz::operator+(const Matriz m) const
{

}

Matriz Matriz::operator-(const Matriz m) const
{

}

Matriz Matriz::operator*(const Matriz m) const
{

}

Matriz Matriz::operator*(const double escalar) const
{

}

Matriz Matriz::Inversa()
{

}

double Matriz::Determinante()
{

}
*/

// ***********************************
//      Metodos de utileria
// ***********************************
void Matriz::Redimensionar(int fil, int col)
{
    if(fil < 1 || col < 1) throw "Dimensión inválida";

    filas = fil;
    columnas = col;
}


// ***********************************
//      Metodos externos
// ***********************************

/*
std::ostream & operator << (std::ostream &salida, const Matriz m)
{

}

std::istream & operator >> (std::istream &entrada, const Matriz &m)
{

}
*/
