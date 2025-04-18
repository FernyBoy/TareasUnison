/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   17/04/2025
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "../Headers/AvlTree.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;


void PressEnter();
void ClearScreen(); 

int main()
{
    try{
        AvlTree<int> tree;

        for(int i = 0; i < 10; ++i)
        {
            tree.Add(pow(-1, i) * (i + 1));   
        }
        
        int option;
        while(option != 0)
        {
            ClearScreen();
            cout << tree;
            cout << "\n\n0. Salir";
            cout << "\n1. Agregar";
            cout << "\n2. Eliminar";
            cout << "\n3. Vaciar el \240rbol";
            cout << "\n4. Buscar un n\243mero";
            cout << "\n5. N\243mero de nodos";
            cout << "\n6. Altura del \240rbol";
            cout << "\n7. Imprimir de forma ascendente";
            cout << "\n8. Imprimir de forma descendente";
            cout << "\n9. Imprimir por niveles";
            cout << "\n10. Imprimir forma de \240rbol";
            cout << "\n\n - ";
            
            option = CapturaSegura<>().LongitudCerrada(0, 10);
            ClearScreen();
            switch (option) 
            {
                case 1:
                    cout << "\nIngresa el valor que deseas agregar\n - ";
                    tree.Add(CapturaSegura<>().LongitudSegura());
                    break;

                case 2:
                    cout << "\nIngresa el valor que deseas eliminar\n - ";
                    tree.Remove(CapturaSegura<>().LongitudSegura());
                    break;

                case 3:
                    tree.Clear();
                    break;

                case 4:
                    cout << "\nIngresa el valor que deseas buscar\n - ";
                    tree.Contains(CapturaSegura<>().LongitudSegura())
                        ? cout << "El valor SI se encuentra en el \240rbol"
                        : cout << "El valor NO se encuentra en el \240rbol";
                    PressEnter();
                    break;

                case 5:
                    cout << "\nN\243mero de nodos: " << tree.Size();
                    PressEnter();
                    break;

                case 6:
                    cout << "\nAltura del \240rbol: " << tree.Height();
                    PressEnter();
                    break;

                case 7:
                    tree.PrintAscendent();
                    PressEnter();
                    break;

                case 8:
                    tree.PrintDescendent();
                    PressEnter();
                    break;

                case 9:
                    tree.PrintByLevels();
                    PressEnter();
                    break;                   
                
                case 10:
                    cout << tree;
                    PressEnter();
                    break;
            }
        }
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}

void PressEnter()
{
    cout << "\n\nPresiona enter para continuar";
    cin.ignore();
    cin.get();
}

void ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}
