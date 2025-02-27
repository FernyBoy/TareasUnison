/**
*   \file   DoubleLinkedList.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   18/02/2025
*/

#ifndef DOUBLELINKEDLIST_HPP_INCLUDED
#define DOUBLELINKEDLIST_HPP_INCLUDED

#include "CapturaSegura.hpp"

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class DoubleLinkedList
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const DoubleLinkedList<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, DoubleLinkedList<T> &li);

    public:
        // --- Constructores
        explicit DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList &li);
        // - Destructor
        ~DoubleLinkedList();

        // --- Operadores
        DoubleLinkedList& operator=(const DoubleLinkedList &li);
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
        unsigned    Size()                  const;
        bool        IsEmpty()               const;
        // - Otras funciones
        void        Clear();
        void        Print();


    private:
        // --- Atributos
        unsigned    size;

        struct  Element
        {
            Element(Type val)
            {
                value = val;
                prevElement = nullptr;
                nextElement = nullptr;
            }

            Type value;
            Element *prevElement;
            Element *nextElement;
        };

        Element     *firstElement;
        Element     *lastElement;

        // --- Métodos privados
        bool    IsValidIndex(unsigned index)    const;

        // --- Métodos de utilería

};

#include "../Templates/DoubleLinkedList.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
