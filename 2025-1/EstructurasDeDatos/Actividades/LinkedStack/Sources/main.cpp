/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#include <iostream>
#include <cstdlib>

#include "../Headers/Stack.hpp"
#include "../Headers/CapturaSegura.hpp"
#include "../Headers/Vector.hpp"

int Menu();
void LimpiarPantalla();

template <typename Type, unsigned int Cap>
void Pruebas(Stack<Type, Cap> &stack);

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    int respuesta = 0;
    Stack<std::string, 5> stack1;
    Stack<int, 5> stack2;
    Stack<Vector, 3> stack3;

    while(respuesta != 4)
    {
        try{
            int respuesta = Menu();
                
            switch (respuesta) 
            {
                case 1:
                    cout << "Est\240 vac\241a: " << (stack1.IsEmpty() ? "Si" : "No");
                    cout << "\nCapacidad usada: " << stack1.UsedCapacity();
                    cout << "\nCapacidad actual: " << stack1.Capacity() << "\n\n";
                    cout << "\n\npila:\n";
                    cout << stack1;
                     
                    stack1.Push("Fernando");
                    stack1.Push("V\241ctor");
                    stack1.Push("Angel");
                    stack1.Push("Sara");
                    stack1.Push("El\241as");
                    stack1.Push("Ivanna");
                    stack1.Push("Javier");

                    Pruebas(stack1);

                    break;

                case 2:
                    cout << "Est\240 vac\241a: " << (stack1.IsEmpty() ? "Si" : "No");
                    cout << "\nCapacidad usada: " << stack1.UsedCapacity();
                    cout << "\nCapacidad actual: " << stack1.Capacity() << "\n\n";
                    cout << "\n\npila:\n";
                    cout << stack2;

                    for(int i = 0; i < 11; ++i)
                    {
                        stack2.Push(i);
                    }

                    Pruebas(stack2);

                    break;

                case 3:
                    cout << "Est\240 vac\241a: " << (stack1.IsEmpty() ? "Si" : "No");
                    cout << "\nCapacidad usada: " << stack1.UsedCapacity();
                    cout << "\nCapacidad actual: " << stack1.Capacity() << "\n\n";
                    cout << "\n\npila:\n";
                    cout << stack3;

                    for(int i = 0; i < 5; ++i)
                    {
                        stack3.Push(Vector((i+1), (i * 5)));
                    }

                    Pruebas(stack3);

                    break;

                case 4:
                    exit(0);
                    break;
            }
        }catch(const char *err)
        {
            cerr << "Error: " << err << endl;
        }

        cout << "\n\nContinuar...";
        cin.ignore();  
        cin.get();
    }

    return 0;
}

void LimpiarPantalla()
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

template <typename Type, unsigned int Cap>
void Pruebas(Stack<Type, Cap> &stack)
{
    cout << "\nEst\240 vac\241a: " << (stack.IsEmpty() ? "Si" : "N0");
    cout << "\nCapacidad usada: " << stack.UsedCapacity();
    cout << "\nCapacidad actual: " << stack.Capacity();
    cout << "\nTope: \n" << stack.Top();
    cout << "\n\npila:\n";
    cout << stack;

    stack.Pop();
    cout << "\n\n\351ltimo elemento borrado.";
    cout << "\nCapacidad usada: " << stack.UsedCapacity();
    cout << "\nCapacidad actual: " << stack.Capacity();
    cout << "\nTope: \n" << stack.Top();
    cout << "\n\nPila: \n"; 
    cout << stack;

    stack.ClearStack();
    cout << "\n\nPila borrada.";
    cout << "\nEst\240 vac\241a: " << (stack.IsEmpty() ? "Si" : "No");
    cout << "\nCapacidad usada: " << stack.UsedCapacity();
    cout << "\nCapacidad actual: " << stack.Capacity();
    cout << "\nTope: " << stack.Top();
    cout << "\n\nPila: \n";
    cout << stack;
}

int Menu() {
    LimpiarPantalla();
    int respuesta;

    cout << "Ingrese una opci\242n:" << endl;
    cout << "1. Probar con cadenas (String)" << endl;
    cout << "2. Probar con valores enteros (int)" << endl;
    cout << "3. Probar con vectores (Vector)" << endl;
    cout << "4. Salir del programa";
    cout << "\n - ";
    respuesta = CapturaSegura<int>().LongitudCerrada(1, 4);
    
    return respuesta;
}
