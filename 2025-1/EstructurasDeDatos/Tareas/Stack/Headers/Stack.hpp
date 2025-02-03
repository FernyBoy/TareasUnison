#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <istream>
#include <type_traits>

template <typename Type, unsigned int Cap = 0>
class Stack
{
    // --- Métodos externos
    friend std::ostream& operator<<(std::ostream& output, const Stack<Type, Cap>& s);
    friend std::istream& operator>>(std::istream& input, Stack<Type, Cap>& s);

    public:
        // --- Constructores
        //explicit Stack(unsigned s);
        explicit Stack();
        Stack(const Stack &s);
        Stack & operator=(const Stack &s);

        // --- Destructor
        ~Stack();

        // --- Métodos públicos
        void        Push(Type val);
        void        Pop(); 
        Type        Top() const;
        bool        IsEmpty();
        void        ClearStack();
        unsigned    UsedCapacity() const;
        unsigned    Capacity();
        void        PrintElements();
        Type        operator[](int i) const;

    private:
        // --- Atributos
        unsigned    size = Cap;
        Type        *elements;
        int         currentIndex = -1;

        // --- Métodos privados
        bool    IsFull();
        void    ResizeStack();

        // --- Métodos de utilería
        void    CreateStack();
        void    ClearMemory();
};

#include "../Templates/Stack.tpp"

#endif // !STACK_HPP_INCLUDED
