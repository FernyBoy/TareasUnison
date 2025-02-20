/**
*   \file   LinkedList.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   18/02/2025
*/

#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED

#include "CapturaSegura.hpp"

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class LinkedList
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const LinkedList<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, LinkedList<T> &li);

    public:
        // --- Constructores
        explicit LinkedList();
        LinkedList(const LinkedList &li);
        // - Destructor
        ~LinkedList();

        // --- Operadores
        LinkedList& operator=(const LinkedList &li);
        Type        operator[](unsigned int index);

        // --- Métodos públicos
        // - Funciones de agregación
        void        AddFirst(Type val);
        void        AddLast(Type val);
        void        AddAt(Type val, unsigned int index);
        // - Funciones de eliminación
        void        RemoveFirst();
        void        RemoveLast();
        void        RemoveAt(unsigned int index);
        void        RemoveElement(Type val);
        // - Funciones de obtención
        Type        GetFirst()              const;
        Type        GetLast()               const;
        Type        GetAt(unsigned index)   const;
        unsigned    IndexOf(Type val)       const;
        unsigned    ListSize()              const;
        bool        IsEmpty()               const;
        // - Otras funciones
        void        ClearList();
        void        PrintList();


    private:
        // --- Atributos
        unsigned    size;

        struct  Element
        {
            Type value;
            Element *nextElement;
        };

        Element     *nextElement;
        Element     *firstElement;
        Element     *lastElement;

        // --- Métodos privados
        bool    IsValidIndex(unsigned index)    const;

        // --- Métodos de utilería

};

#include "../Templates/LinkedList.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
