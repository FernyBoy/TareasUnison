#include <iostream>
#include <ostream>

#include "../Headers/Vector.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n; 
    
    cout << "Programa que suma dos vectores" << endl;

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
    z = v.Sumar(w);

    v.Imprimir();
    cout << " + ";
    w.Imprimir();
    cout << " = ";
    z.Imprimir();


    cout << endl << endl;
    z = v.Restar(w);

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
    cout << v.ProductoPunto(w);


    cout << endl << endl;
    double escalar;
    cout << "Ingresa el escalar: ";
    cin >> escalar;
    z = v.ProductoPorEscalar(escalar);
    v.Imprimir();
    cout << " * " << escalar << " = ";
    z.Imprimir();

    
    cout << endl << endl;
    cout << "Norma de ";
    v.Imprimir();
    cout << " = "; 
    cout << v.NormaV();

    return 0;
}
