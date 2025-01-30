#include <iostream>

#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    /*
    Matriz m1(5, 5);
    m1.ImprimirMatriz();
    cout << endl;

    Matriz m2(10, 10);
    m2.ImprimirMatriz();
    cout << endl;

    Matriz m3(1, 1);
    m3.ImprimirMatriz();
    cout << endl;

    m2 = m1;
    m2.ImprimirMatriz();
    cout << endl;
    */

    //--------------------

    /*
    Matriz m4(4, 6);
    m4.ImprimirMatriz();
    cout << endl;

    Matriz m5(3, 6);
    m5.ImprimirMatriz();
    cout << endl;
    m5 = m4;
    m5.ImprimirMatriz();
    cout << endl;

    Matriz m6(2, 6);
    m6.ImprimirMatriz();
    cout << endl;
    m6 = m4 - m5;
    m6.ImprimirMatriz();
    cout << endl;

    m6 = m4 + m5;
    m6.ImprimirMatriz();
    cout << endl;

    m6 = m6 * 5;
    m6.ImprimirMatriz();
    cout << endl;
    */

    
    Matriz m1(2, 2);
    m1.ImprimirMatriz();
    cout << endl;

    Matriz m2(2, 2);
    m2.ImprimirMatriz();
    cout << endl;

    Matriz m3(2, 2);
    m3 = m1 * m2;
    m3.ImprimirMatriz();
    cout << endl;

    return 0;
}
