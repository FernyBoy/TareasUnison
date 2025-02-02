#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <istream>

// template <typename T>
class Stack
{
    friend std::ostream & operator<<(std::ostream &output, const Stack &s);
    friend std::istream & operator>>(std::istream &input, Stack &s);

    public:
        // Constructores
        explicit Stack();
        explicit Stack(int s);
        Stack(const Stack &s);
        Stack & operator=(const Stack &s);

        // Destructor
        ~Stack();

        // Metodos
        void    Push(int val);
        void    Pop();
        int     Top();
        bool    IsEmpty();
        void    ClearStack();
        int     UsedCapacity();
        int     Capacity();
        void    PrintElements();

    private:
        // Atributos
        int     size;
        int     *elements;
        int     currentIndex = -1;

        // Metodos privados
        bool    IsFull();
        Stack   ResizeStack();
};

// #include "../Templates/Stack.tpp"

#endif // !STACK_HPP_INCLUDED
