/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   23/02/2025
*/

#include "../Headers/Client.hpp"

vector<DoubleLinkedList<int>> Client::lists;
DoubleLinkedList<int> Client::*selectedList = nullptr;


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Método para comenzar la simulación ---
//
// --------------------------------------------
void Client::RunService()
{
    ClearScreen();
    
    PrintDivision();


    SystemPause();
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
void Client::MainMenuTemplate()
{
    cout << "\n1.   Crear una nueva lista";
    cout << "\n2.   Eliminar una lista";
    cout << "\n3.   Seleccionar lista";
    cout << "\n4.   Editar lista";
    
    cout << "\n\n5.   Salir";
}

void Client::EditMenuTemplate()
{
    cout << "\n1.   Agregar";
    cout << "\n2.   Eliminar";
    cout << "\n3.   Modificar";
    cout << "\n4.   Transferir elementos a otra lista";
    cout << "\n5.   Obtener elementos";
    cout << "\n6.   Ordenar la lista";
}

void Client::AddMenuTemplate()
{

}
void Client::RemoveMenuTemplate()
{

}

void Client::ModificationMenuTemplate()
{

}

void Client::TransferMenuTemplate()
{

}
void Client::SetsMenuTemplate()
{

}

void Client::SortMenuTemplate()
{

}
    
void Client::GetMenuTemplate()
{

}

void Client::CompareMenuTemplate()
{

}
        
void Client::PrintMenuTemplate()
{

}

// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
void Client::PrintSelectedList()
{
    if(lists.size() == 0)
    {
        cout << "\n\nActualmente no tienes listas creadas";
    }
    else if (selectedList == nullptr) 
    {
        cout << "\n\nActualmente no tienes una lista seleccionada";
    }
    else
    {
        cout << endl << "\n\nLista seleccionada: " << selectedList << endl;
    }
}

void Client::PrintDivision()
{
    for(int i = 0; i < 15; ++i)
    {
        cout << "-";
    }
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
