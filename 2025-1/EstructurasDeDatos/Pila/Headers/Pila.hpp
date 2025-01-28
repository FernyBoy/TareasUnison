#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX 100

template <typename Type>
class Pila
{
    public:
        Pila();
        void Push(Type valor);
        void Pop();
        Type Top() const;
        bool Empty() const;
        bool Full() const;
        void Clear();
        void Print() const;

    private:
        int size;
        Type element[MAX];
};

#include "../Templates/Pila.tpp"

#endif // PILA_HPP_INCLUDED
