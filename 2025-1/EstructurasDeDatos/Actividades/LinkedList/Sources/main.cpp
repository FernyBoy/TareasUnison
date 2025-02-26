/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <iostream>
#include "../Headers/LinkedList.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        LinkedList<int> list;

        while(true)
        {
            cout << "\n --- Opciones de agregacion ---"
            cout << "\n1. Agregar un elemento al inicio";
            cout << "\n2. Agregar un elemento al final";
            cout << "\n3. Agregar un elemento en cierta posicion"

            cout << "\n\n --- Opciones de eliminacion ---";
            cout << "\n4. Eliminar el primer elemento";
            cout << "\n5. Eliminar el ultimo elemento";
            cout << "\n6. Eliminar un elemento en cierta posicion"

            cout << "\nElige una de las opciones anteriores:";
        }

    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }
}
