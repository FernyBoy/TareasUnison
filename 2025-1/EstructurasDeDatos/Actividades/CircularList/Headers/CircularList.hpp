/**
*   \file   CircularList.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   11/03/2025
*/

#ifndef CIRCULARLIST_HPP_INCLUDED
#define CIRCULARLIST_HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class CircularList
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const CircularList<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, CircularList<T> &li);

    public:
        // --- Constructores
        explicit CircularList();
        CircularList(const CircularList &li);
        CircularList & operator=(const CircularList &li);

        // --- Destructor
        ~CircularList();

        // --- Métodos públicos
        void        Add(Type val);
        void        RemoveHead();
        bool        Contains(Type val);
        void        MoveForward();
        void        MoveBackward();
        Type        GetHead();
        unsigned    Size();
        bool        Empty();
        void        Clear();
        void        Print();
        void        PrintReverse();


    private:
        // --- Atributos
        unsigned size;

        struct Element
        {
            Element(Type val) : value(val), prevElement(nullptr), nextElement(nullptr) {}

            Type value;
            Element* prevElement;
            Element* nextElement;
        };

        Element* head;


        // --- Métodos privados
        bool    IsValidIndex(unsigned index)    const;
};

#include "../Templates/CircularList.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
