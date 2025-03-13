/**
*   \file   OrderedList.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   12/03/2025
*/

#ifndef ORDEREDLIST_HPP_INCLUDED
#define ORDEREDLIST_HPP_INCLUDED

#include <iostream>
#include <ostream>

#include "DoubleLinkedList.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class OrderedList
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const OrderedList<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, OrderedList<T> &li);

    public:
        // --- Constructores
        explicit OrderedList();
        OrderedList(const OrderedList &li);
        OrderedList & operator=(const OrderedList &li);

        // --- Destructor
        ~OrderedList();

        // --- Métodos públicos
        void        Add(Type val);
        void        Remove(Type val);
        void        MixLists(const DoubleLinkedList<Type> &li_1, const DoubleLinkedList<Type> &li_2);
        bool        Contains(Type Val)      const;
        void        Clear();
        bool        Empty()                 const;
        unsigned    Size()                  const;
        void        Print();
        void        PrintReverse();


    private:
        // --- Atributos
        DoubleLinkedList<Type>  list;

        // --- Métodos privados
};

#include "../Templates/OrderedList.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
