#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX 100

class Pila
{
    public:
        Pila();
        void Push(double valor);
        void Pop();
        double Top() const;
        bool Empty() const;
        bool Full() const;
        void Print() const;

    private:
        int size;
        double element[MAX];
};

#endif // PILA_HPP_INCLUDED
