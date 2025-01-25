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
    }catch(const char *msg)
    {
        cerr << "Error: " << msg << endl; 
    }
}
