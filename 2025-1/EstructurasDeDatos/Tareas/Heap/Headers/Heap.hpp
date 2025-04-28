/**
*   \file   Heap.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   26/04/2025
*/

#ifndef HEAP_HPP_INCLUDED
#define HEAP_HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::swap;

template <typename T>
bool min(const T &a, const T &b);

template <typename T>
bool max(const T &a, const T &b);

template <typename Type, bool(*Order)(const Type &, const Type &) = min>
class Heap
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const Heap<T> &h);

    public:
        // --- Constructores
        Heap();
        Heap(const Heap &h);
        Heap & operator=(const Heap &h);

        // --- Destructor
        ~Heap();

        // --- Métodos públicos
        // - Funciones de modificación
        void        Insert(Type value);
        void        Remove();
        void        Clear();

        // - Funciones de obtención
        Type        Top();
        bool        Empty();
        unsigned    Size()          const;
        unsigned    MaxCapacity()   const;

        // - Funciones de impresión
        void        Print()         const;
        


    private:
        // --- Atributos
        unsigned    _capacity;
        int         _size;
        Type*       _elements;

        // --- Métodos privados
        void    PrintTreeLinux(unsigned parentIndex, const string& prefix)  const;
        void    PrintTreeWindows(unsigned parentIndex, const string& prefix) const;
        void    Resize();
        void    MoveUp(unsigned currentIndex);
        void    MoveDown(unsigned currentIndex);
};

#include "../Templates/Heap.tpp"

#endif // !HEAP_HPP_INCLUDED
