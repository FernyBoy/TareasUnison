/**
 *  \file   Client.hpp
 *  \author Angel Fernando Borquez Guerrero
 *  \author Javier Leonardo Miranda Sanchez
 *  \date   27/04/2025
 */

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <iostream>
#include <vector>

#include "./Heap.hpp"
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
        static Heap<int, min> minHeap;
        static Heap<int, max> maxHeap;
        static bool selectedHeap;
        

        // --- Métodos privados ---
        // - Templates
        static void     MainMenuTemplate();

        // - Seleccion de opciones
        static void     MainMenu();
    
        static unsigned GetOption(unsigned start, unsigned end);
        
        static void     PrintSelectedHeap();
        static void     PrintDivision();

        static void     PressEnter();

        static void     ClearScreen();

        static void     SystemPause();
};

#endif // CLIENT_HPP_INCLUDED
