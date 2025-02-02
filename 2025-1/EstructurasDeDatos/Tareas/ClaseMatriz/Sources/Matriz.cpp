#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::endl;

Matriz::Matriz() : filas(1), columnas(1)
{
    CapturarDimension();
    IniciarMatriz();
}

Matriz::Matriz(int fil, int col) : filas(fil), columnas(col)
{
    if(fil < 1 || col < 1) throw "Dimensiones inválidas";

    IniciarMatriz();
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
        for(int i = 0; i < filas; ++i) delete[] componentes[i];

        delete[] componentes;
    }

    filas = m.filas;
    columnas = m.columnas;

    if(m.componentes)
    {
        try 
        {
            componentes = new double *[filas];

            for(int i = 0; i < filas; ++i)
            {
                componentes[i] = new double[columnas];

                for(int j = 0; j < columnas; ++j) componentes[i][j] = m.componentes[i][j];
            }
        }catch (std::bad_alloc &) 
        {
            throw "Problemas de asignación de memoria";
        }
    }
    else 
    {
        componentes = nullptr;
    }

    return *this;
}

Matriz::~Matriz()
{
    if(componentes)
    {
        for(int i = 0; i < filas; ++i) delete[] componentes[i];

        delete[] componentes;
    }
}

void Matriz::IniciarMatriz()
{
    try
    {
        componentes = new double *[filas];

        for(int i = 0; i < filas; ++i)
        {
            componentes[i] = new double[columnas]; 

            for(int j = 0; j < columnas; ++j) componentes[i][j] = 0; // i+j;
        }

    }catch(std::bad_alloc &)
    {
        throw "Problemas de asginación de memoria";
    }
}

void Matriz::CapturarDimension()
{
    LimpiarPantalla();
    ImprimirMatriz(1, 1);
    cout << "--- Matriz: 1x1 ---";
    
    cout << "\nIngresa la cantidad de filas\n - ";
    filas = LongitudSegura();

    LimpiarPantalla();
    ImprimirMatriz(filas, 1);
    cout << "--- Matriz: " << filas << "x1 ---";

    cout << "\nIngresa la cantidad de columnas\n - ";
    columnas = LongitudSegura();

    LimpiarPantalla();
    ImprimirMatriz(filas, columnas);
    cout << "--- Matriz: " << filas << "x" << columnas << " ---";

    cout << "\n\nContinuar...";
    cin.ignore();  
    cin.get();
    LimpiarPantalla();
}

void Matriz::CapturarMatriz()
{
    for(int i = 0; i < filas; ++i)
    {
        for(int j = 0; j < columnas; j++)
        {
            LimpiarPantalla();

            ImprimirMatriz();

            cout << endl;

            cout << "Ingresa el valor [" << i + 1 << "][" << j + 1 << "]\n - ";
            cin >> componentes[i][j];
        }
    }
   
    LimpiarPantalla();
    ImprimirMatriz();
    cout << "\nContinuar...";
    cin.ignore();  
    cin.get();
    LimpiarPantalla();
}

void Matriz::ImprimirMatriz()
{
    cout << "|";
    for(int j = -1; j < columnas; ++j)
    {
        cout << "\t";
    }
    cout << "|\n";
    
    for(int i = 0; i < filas; ++i) 
    {
        cout << "|\t";
        for(int j = 0; j < columnas; ++j) cout << componentes[i][j] << "\t";
        cout << "| \n";

        cout << "|";
        for(int j = -1; j < columnas; ++j)
        {
            cout << "\t";
        }
        cout << "|\n";
    }
}

void Matriz::ImprimirMatriz(int fil, int col)
{
    cout << "|";
    for(int j = -1; j < col; ++j)
    {
        cout << "\t";
    }
    cout << "|\n";
    
    for(int i = 0; i < fil; ++i) 
    {
        cout << "|\t";
        for(int j = 0; j < col; ++j) cout << 0 << "\t";
        cout << "| \n";

        cout << "|";
        for(int j = -1; j < col; ++j)
        {
            cout << "\t";
        }
        cout << "|\n";
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

double* Matriz::operator[](int i)
{
    if (i < 0 || i >= filas || !componentes) throw "Índice inválido o matriz no inicializada";
    
    return componentes[i];
}



Matriz Matriz::Traspuesta()
{
    Matriz n(columnas, filas);

    try 
    {
        for(int i = 0; i < filas; ++i)
        {
            for(int j = 0; j < columnas; ++j) n.componentes[j][i] = componentes[i][j];
        }
    }catch (std::bad_alloc &) 
    {
        throw "Problemas de asignación de memoria";
    } 

    return n;
}

Matriz Matriz::Inversa()
{
    if(filas != columnas) throw "No es matriz cuadrada";
    double pivote, aux;

    Matriz identidad(filas, columnas);

    //Inicializacion de la matriz identidad
    for(int i = 0; i < filas; ++i)
    {
        for(int j = 0; j < columnas; ++j)
        {
            if(i==j)
            {
                identidad[i][j] = 1;
            }
            else
            {
                identidad[i][j] = 0;
            }
        }

    }

    //Reduccion por renglones
    for(int i = 0; i < filas; ++i)
    {
        pivote = componentes[i][i];

        for(int k = 0; k < filas; ++k)
        {
            componentes[i][k] = componentes[i][k] / pivote;

            identidad[i][k] = identidad[i][k] / pivote;
        }

        for(int j = 0; j < filas; ++j)
        {
            if(i != j)
            {
                aux = componentes[j][i];

                for(int k = 0; k < filas; ++k)
                {
                    componentes[j][k] = componentes[j][k] - aux * componentes[i][k];

                    identidad[j][k] = identidad[j][k] - aux * identidad[i][k];
                }
            }
        }
    }

    if(std::isinf(identidad[0][0]) || (-1)*std::isinf(identidad[0][0]) ) throw "No tiene inversa";

    return identidad;
}

// ***********************************
//      Metodos de utileria
// ***********************************

void Matriz::LimpiarPantalla() {
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

double Matriz::LongitudSegura()
{
    double longitud;
    cin >> longitud;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nIngresa un valor v\240lido.\n - ";
        cin >> longitud;
    }

    return longitud;
}

double Matriz::LongitudPositiva()
{
    double longitud;
    cin >> longitud;

    while(cin.fail() || longitud < 1)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nIngresa un valor v\240lido mayor a 0.\n - ";
        cin >> longitud;
    }

    return longitud;
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

std::istream & operator>>(std::istream &entrada, Matriz &m)
{
    for(int i = 0; i < m.filas; ++i)
    {
        for(int j = 0; j < m.columnas; j++)
        {
            m.LimpiarPantalla();

            m.ImprimirMatriz();

            cout << endl;

            cout << "Ingresa el valor [" << i + 1 << "][" << j + 1 << "]\n - ";
            m.componentes[i][j] = m.LongitudSegura();
        }
    }
   
    m.LimpiarPantalla();
    m.ImprimirMatriz();
    cout << "\nContinuar...";
    entrada.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    entrada.get();
    m.LimpiarPantalla();

    return entrada;
}

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
