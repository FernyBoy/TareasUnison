#include <iostream>

#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::endl;

Matriz::Matriz(int fil, int col)
{
//    Redimensionar(fil, col);

    try
    {
        componentes = new double *[filas];

        for(int i = 0; i < filas; ++i)
        {
            componentes[i] = new double[columnas]; 

            for(int j = 0; j < columnas; ++j)
                componentes[i][j] = i+j;
        }
        

    }catch(std::bad_alloc &)
    {
        throw "Problemas de asginación de memoria";
    }
}

Matriz::Matriz(const Matriz &m)
{
    *this = m;
}

Matriz & Matriz::operator=(const Matriz &m)
{
    if(this == &m) return *this;

    if(componentes)
    {
        for(int i = 0; i < filas; ++i) 
        {
            delete[] componentes[i];
        }

        delete[] componentes;
    }

    Redimensionar(m.filas, m.columnas);
   
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

    return *this;
}

Matriz::~Matriz()
{
    if(componentes)
    {
        for(int i = 0; i < filas; ++i) 
        {
            delete[] componentes[i];
        }

        delete[] componentes;
    }
}

/*
double Matriz::ObtenerValor(int fil, int col)
{
   return *(*(componentes + i) + j); 
}
*/

void Matriz::ImprimirMatriz()
{
    for(int i = 0; i < filas; ++i) 
    {
        cout << "|\t";
        for(int j = 0; j < columnas; ++j)
        {
            cout << componentes[i][j] << "\t";
        }
        cout << "| \n";
    }
}

Matriz Matriz::operator+(const Matriz &m) const
{
    if(filas != m.filas || columnas != m.columnas) throw "No es posible realizar la operación, las matrices no tienen las mismas dimensiones.";

    Matriz n(filas, columnas);

    for(int i = 0; i < filas; ++i)
    {
        for(int j = 0; j < columnas; ++j)
        {
            n.componentes[i][j] = componentes[i][j] + m.componentes[i][j];
        }
    }

    return n;
}

Matriz Matriz::operator-(const Matriz &m) const
{
    if(filas != m.filas || columnas != m.columnas) throw "No es posible realizar la operación, las matrices no tienen las mismas dimensiones.";

    Matriz n(filas, columnas);

    for(int i = 0; i < filas; ++i)
    {
        for(int j = 0; j < columnas; ++j)
        {
            n.componentes[i][j] = componentes[i][j] - m.componentes[i][j];
        }
    }

    return n;
}

Matriz Matriz::operator*(const double escalar) const
{
    Matriz n(filas, columnas);

    for(int i = 0; i < filas; ++i)
    {
        for(int j = 0; j < columnas; ++j)
        {
            n.componentes[i][j] = componentes[i][j] * escalar;
        }
    }

    return n;
}


Matriz Matriz::operator*(const Matriz &m) const
{
    if(columnas != m.filas) throw "No es posible realizar la operación, dimensiones incompatibles.";

    Matriz n(filas, m.columnas);

    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < m.columnas; ++j)
        {
            n.componentes[i][j] = 0;  // Inicializar a 0 antes de sumar

            for (int k = 0; k < columnas; ++k)  // Multiplicación y suma acumulativa
            {
                n.componentes[i][j] += componentes[i][k] * m.componentes[k][j];
            }
        }
    }

    return n;  
}


Matriz Matriz::Traspuesta()
{
    Matriz n(columnas, filas);

    try 
    {
        for(int i = 0; i < filas; ++i)
        {
            for(int j = 0; j < columnas; ++j)
            {
                n.componentes[j][i] = componentes[i][j];
            }
        }
    }catch (std::bad_alloc &) 
    {
        throw "Problemas de asignación de memoria";
    } 

    return n;
}

/*
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
    // bool truncate = fil * col < filas * columnas;
    
    filas = fil;
    columnas = col;
    /*
        Matriz aux(fil,col);

    if(truncate){
        for(int i = 0; i < fil; ++i){
            for(int j = 0; j < col; ++j){
                aux[i][j] = (*this).[i][j];
            }
        }

        *this = aux;
    }else{

    }
    */
}

// ***********************************
//      Metodos externos
// ***********************************
std::ostream & operator<<(std::ostream &salida, const Matriz &m)
{
    for(int i = 0; i < m.filas; ++i) 
    {
         salida << "|";
        for(int j = -1; j < m.columnas; ++j)
        {
            salida << "\t";
        }
        salida << "|\n";

        salida << "|\t";
        for(int j = 0; j < m.columnas; ++j)
        {
            salida << m.componentes[i][j] << "\t";
        }
        salida << "| \n";
        
        salida << "|";
        for(int j = -1; j < m.columnas; ++j)
        {
            salida << "\t";
        }
        salida << "|\n";
    }

    return salida;
}
/*
std::istream & operator >> (std::istream &entrada, const Matriz &m)
{

}
*/

Matriz operator*(double escalar, const Matriz &m)
{
    Matriz n(m.filas, m.columnas);

    for(int i = 0; i < m.filas; ++i)
    {
        for(int j = 0; j < m.columnas; ++j)
        {
            n.componentes[i][j] = m.componentes[i][j] * escalar;
        }
    }

    return n;
}
