#include <iostream>

#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try
    {
        Matriz m1;
        cin >> m1;

        Matriz m2;
        cin >> m2;

        cout << "\nM1: \n" << m1 << "\nM2: \n" << m2;

        cout << "\nM1 + M2: \n" << m1 + m2;
        cout << "\nM1 + M2: \n" << m1 - m2;
        cout << "\nM1 + M2: \n" << m1 * m2;
        cout << "\nM1 * 5: \n" << m1 * 5;
        cout << "\nM2 * 10: \n" << 10 * m2;
        cout << "\nM1 inversa: \n" << m1.Inversa();
        cout << "\nM2 inversa: \n" << m2.Inversa();

        Matriz m3 = (m1 + m2) * 4;
        cout << "\nM3: \n" << m3;
        cout << "\nM3 Traspuesta: \n" << m3.Traspuesta();
         

    }catch(const char *message)
    {
        cerr << "Error: " << message << endl;
    }

    return 0;
}
