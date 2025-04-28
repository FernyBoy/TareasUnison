/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   27/04/2025
*/

#include "../Headers/Client.hpp"
#include <cctype>
#include <cstdlib>

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

    cout << "\n\n 8. Salir";
}

// --------------------------
// --- Funciones de menus ---
// --------------------------
void Client::MainMenu()
{
    unsigned opt = 0;
    int value = 0;

    while(opt != 8)
    {
        ClearScreen();
        MainMenuTemplate();
        opt = GetOption(1, 7);
        int value;
        
        try{
            switch(opt)
            {
                case 1: // Agregar elemento
                    cout << "Ingresa el valor que deseas agregar\n - ";
                    value = CapturaSegura<>().LongitudSegura();
                    selectedHeap ? maxHeap.Add(value) : minHeap.Add(value);
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
                    if()
                    break;

                case 5: // Vaciar
                
                    break;

                case 6: // Número de elementos
                    
                    break;

                case 7: // Capacidad actual

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
    cout << (selectedHeap ? maxHeap : minHeap);

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
