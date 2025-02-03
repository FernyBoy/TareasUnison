#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <istream>
#include <type_traits>

// template <typename Type, typename Capacity>
class Stack
{
    // static_assert(std::is_unsigned_v<Capacity>, "Tamaño de pila incorrecto");
    
    // --- Métodos externos
    friend std::ostream & operator<<(std::ostream &output, const Stack &s);
    friend std::istream & operator>>(std::istream &input, Stack &s);

    public:
        // --- Constructores
        explicit Stack(unsigned s);
        //explicit Stack();
        Stack(const Stack &s);
        Stack & operator=(const Stack &s);

        // --- Destructor
        ~Stack();

        // --- Métodos públicos
        void        Push(int val);
        void        Pop();
        int         Top();
        bool        IsEmpty();
        void        ClearStack();
        int         UsedCapacity();
        unsigned    Capacity();
        void        PrintElements();

    private:
        // --- Atributos
        unsigned    size;
        int         *elements;
        int         currentIndex = -1;

        // --- Métodos privados
        bool    IsFull();
        Stack   ResizeStack();

        // --- Métodos de utilería
        void    CreateStack();
        void    ClearMemory();
};

// #include "../Templates/Stack.tpp"

#endif // !STACK_HPP_INCLUDED
