/**
 *  \file   Client.hpp
 *  \author Angel Fernando Borquez Guerrero
 *  \author Javier Leonardo Miranda Sanchez
 *  \date   02/03/2025
 */

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <iostream>
#include <vector>

#include "./DoubleLinkedList.hpp"
#include "./CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Client
{
    public:
        static void RunService();

    private:
        // --- Atributos ---
        static vector<DoubleLinkedList<int>> lists;
        static DoubleLinkedList<int> *selectedList;
        

        // --- Métodos privados ---
        static void MainMenuTemplate();
        
        static void EditMenuTemplate();

        static void AddMenuTemplate();
        static void RemoveMenuTemplate();
        static void ModificationMenuTemplate();
        static void TransferMenuTemplate();
        static void SetsMenuTemplate();
        static void SortMenuTemplate();
        static void GetMenuTemplate();
        static void CompareMenuTemplate();
        static void PrintMenuTemplate();
    
    
        static void PrintSelectedList();
        static void PrintDivision();

        /**
         *  \brief Limpia la pantalla de la consola.
         */
        static void ClearScreen();

        /**
         *  \brief Hace una pausa al final de la ejecución para que no se cierre la termina.
         */
        static void SystemPause();
};

#endif // CLIENT_HPP_INCLUDED
