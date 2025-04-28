/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   27/04/2025
*/

#include "../Headers/Client.hpp"
#include <cctype>
#include <cstdlib>

Heap<int, min> Client::minHeap;
Heap<int, max> Client::maxHeap;

bool Client::selectedHeap = false;



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Método para comenzar la simulación ---
//
// --------------------------------------------
void Client::RunService()
{
    ClearScreen();

    MainMenu();

    SystemPause();
    ClearScreen();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de modificación de atributos--
//
// --------------------------------------------


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de impresión -----------------
//
// --------------------------------------------
// ------------------------------
// --- Funciones de templates ---
// ------------------------------
void Client::MainMenuTemplate()
{
    PrintSelectedHeap();
    cout << "\n\n";
    cout << "\n1.   Agregar un elemento";
    cout << "\n2.   Eliminar la ra\241z";
    cout << "\n3.   Obtener la ra\241z";
    cout << "\n4.   Conocer si el Heap est\240 vaci\241";
    cout << "\n5.   Vaciar el Heap";
    cout << "\n6.   Conocer el n\243mero de elementos";
    cout << "\n7.   Conocer la capacidad actual";

    cout << "\n\n8.     Salir\n";
}

// --------------------------
// --- Funciones de menus ---
// --------------------------
void Client::MainMenu()
{
    unsigned opt = 0;

    cout << "\n0. Utilizar Heap m\241nimo";
    cout << "\n1. Utilizar Heap m\240ximo";

    selectedHeap = GetOption(0, 1);

    while(opt != 8)
    {
        ClearScreen();
        MainMenuTemplate();
        opt = GetOption(1, 8);
        int value;
        
        try{
            switch(opt)
            {
                case 1: // Agregar elemento
                    PrintDivision();
                    cout << "\n\nIngresa el valor que deseas agregar\n - ";
                    value = CapturaSegura<>().LongitudSegura();
                    selectedHeap ? maxHeap.Insert(value) : minHeap.Insert(value);
                    break;

                case 2: // Eliminar elemento
                    selectedHeap ? maxHeap.Remove() : minHeap.Remove();
                    break;

                case 3: // Obtener raíz
                    ClearScreen();
                    cout << "Ra\241z: " << (selectedHeap ? maxHeap.Top() : minHeap.Top());
                    PressEnter();
                    break;

                case 4: // Saber si está vacío
                    ClearScreen();
                    cout << "Heap " << (selectedHeap ? (maxHeap.Empty() ? "vac\241o" : "no vac\241o") : (minHeap.Empty() ? "vac\241o" : "no vac\241o"));
                    PressEnter();
                    break;

                case 5: // Vaciar
                    selectedHeap ? maxHeap.Clear() : minHeap.Clear();
                    break;

                case 6: // Número de elementos
                    ClearScreen();
                    cout << "N\243mero de elementos: " << (selectedHeap ? maxHeap.Size() : minHeap.Size());
                    PressEnter();
                    break;

                case 7: // Capacidad actual
                    ClearScreen();
                    cout << "Capacidad actual: " << (selectedHeap ? maxHeap.Capacity() : minHeap.Capacity());
                    PressEnter();
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
unsigned Client::GetOption(unsigned start, unsigned end)
{
    PrintDivision();

    unsigned opt;

    cout << "\nIngresa una de las opciones anteriores\n - ";
    opt = CapturaSegura<unsigned>().LongitudCerrada(start, end);

    return opt;
}


void Client::PrintDivision()
{
    cout << "\n\n";
    for(int i = 0; i < 60; ++i)
    {
        cout << "-";
    }
}

void Client::PrintSelectedHeap()
{
    selectedHeap ? maxHeap.Print() : minHeap.Print();

    PrintDivision();
}

void Client::PressEnter()
{
    cout << "\n\nPresiona enter para continuar";
    cin.ignore();
    cin.get();
}

void Client::ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

void Client::SystemPause()
{
    #ifdef _WIN32
        system("pause");
    #endif
}
