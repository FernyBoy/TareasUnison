#include <iostream>


#include "../Headers/Pila.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try
    {
        Pila miPila;

        miPila.Empty()
            ? cout << "The stack is empty"
            : cout << "The stack is not empty";

        miPila.Push(3.2);
        miPila.Push(5.19);
        miPila.Push(-9.1);
        miPila.Push(31.5);
        miPila.Push(-1.4);

        miPila.Print();

        cout << "\n\n";

        miPila.Pop();
        miPila.Pop();
        miPila.Print();

        cout << "\n\n";

        miPila.Clear();
        miPila.Print();

    }catch(const char *msg)
    {
        cerr << "Error: " << msg << endl; 
    }
}
