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
        cin >> v;

        cout << "\n\nCapturando el segundo vector" << endl;
        cin >> w;

        cout << endl << endl;
        z = v + w;

        cout << v << " + " << w << " = " << z;


        cout << endl << endl;
        z = v - w;

        cout << v << " - " << w << " = " << z;


        cout << endl << endl;
        cout << v << " * " << w << " = " << v * w;


        cout << endl << endl;
        double escalar;
        cout << "Ingresa el escalar: ";
        cin >> escalar;
        z = escalar * v;
        cout << v << " * " << escalar << " = " << z;

    
        cout << endl << endl;
        cout << "Norma de ";
        cout << v << " = " << v.NormaV();

    }catch(const char *message)
    {
        cerr << "Error: " << message << endl;
    }
    

    return 0;
}
