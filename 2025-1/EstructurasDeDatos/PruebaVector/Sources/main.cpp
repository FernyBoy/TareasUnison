#include <iostream>
#include <ostream>

#include "../Headers/Vector.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    /*
    const Vector v(3, 1.5);
    Vector w(3);
    cout << "Capturando un vector" << endl;
    w.Capturar();
    
    Vector z;
    z = v + w; // Llamada implicita
    z = v.operator+(w); // Llamada explicita

    cout << "Suma: ";
    z.Imprimir();
    */

    
    int n; 
    
    cout << "Programa que suma dos vectores" << endl;
    
    try
    {

        do
        {
            cout << "Dimensi\242n [1," << MAX_DIM << "]: ";
            cin >> n;
        } while(n < 1 || n > MAX_DIM);

        Vector v(n), w(n), z(n);

        cout << "\n\nCapturando el primer vector" << endl;
        v.Capturar();

        cout << "\n\nCapturando el segundo vector" << endl;
        w.Capturar();

        cout << endl << endl;
        z = v + w;

        v.Imprimir();
        cout << " + ";
        w.Imprimir();
        cout << " = ";
        z.Imprimir();


        cout << endl << endl;
        z = v - w;

        v.Imprimir();
        cout << " - ";
        w.Imprimir();
        cout << " = ";
        z.Imprimir();


        cout << endl << endl;
        v.Imprimir();
        cout << " * ";
        w.Imprimir();
        cout << " = ";
        cout << v * w;


        cout << endl << endl;
        double escalar;
        cout << "Ingresa el escalar: ";
        cin >> escalar;
        z = escalar * v;
        v.Imprimir();
        cout << " * " << escalar << " = ";
        z.Imprimir();

    
        cout << endl << endl;
        cout << "Norma de ";
        v.Imprimir();
        cout << " = "; 
        cout << v.NormaV();

    }catch(const char *message)
    {
        cerr << "Error: " << message << endl;
    }
    

    return 0;
}
