/**
*   \file   DoubleLinkedList.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   04/03/2025
*/

#ifndef DOUBLELINKEDLIST_HPP_INCLUDED
#define DOUBLELINKEDLIST_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class DoubleLinkedList
{
    // --- Métodos externos --- 
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const DoubleLinkedList<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, DoubleLinkedList<T> &li);

    public:
        typedef bool (*fun)(Type);

        // --- Constructores ---
        explicit DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList &li);
        // - Destructor
        ~DoubleLinkedList();

        // --- Operadores ---
        DoubleLinkedList & operator=(const DoubleLinkedList &li);
        Type        operator=(Type val);
        Type        operator[](unsigned int index) const;
        Type*       operator[](unsigned int index);

        // --- Métodos públicos ---
        // - Funciones de agregación
        void        AddFirst(Type val);
        void        AddLast(Type val);
        void        AddAt(Type val, unsigned int index);
        void        Concat(const DoubleLinkedList<Type> &li);

        // - Funciones de eliminación
        void        RemoveFirst();
        void        RemoveLast();
        void        RemoveAt(unsigned int index);
        void        RemoveFrom(unsigned index);
        void        RemoveRange(unsigned startIndex, unsigned endIndex);
        void        RemoveElement(Type val);
        void        RemoveDuplicates();
        void        RemoveAllElements(Type val);
        void        RemoveMatching(const DoubleLinkedList<Type> &li);
        void        RemoveIf(fun condition);
        void        Clear();

        // - Funciones de modificación
        void        SetAt(unsigned index, Type val);
        void        Clone(const DoubleLinkedList<Type> &li);
        
        // - Funciones de transferencia
        void        Swap(DoubleLinkedList<Type> &li);
        void        TransferAll(DoubleLinkedList<Type> &li);
        void        TransferFrom(unsigned index, DoubleLinkedList<Type> &li);
        void        TransferRange(unsigned startIndex, unsigned endIndex, DoubleLinkedList<Type> &li);
        
        // - Funciones de conjuntos
        DoubleLinkedList<Type>      Union(const DoubleLinkedList<Type> &li);
        DoubleLinkedList<Type>      Intersection(const DoubleLinkedList<Type> &li);
        DoubleLinkedList<Type>      Difference(const DoubleLinkedList<Type> &li);
        DoubleLinkedList<Type>      SymmetricDifference(const DoubleLinkedList<Type> &li);

        // - Funciones de ordenamiento
        void        Reverse();
        void        SortAscending();
        void        SortDescending();
    
        // - Funciones de obtención
        Type                        GetFirst()                                          const;
        Type                        GetLast()                                           const;
        Type                        GetAt(unsigned index)                               const;
        DoubleLinkedList<Type>      GetFrom(unsigned index)                             const;
        DoubleLinkedList<Type>      GetRange(unsigned startIndex, unsigned endIndex)    const;
        bool                        Contains(Type val)                                  const;
        unsigned                    IndexOf(Type val)                                   const;
        unsigned                    Size()                                              const;
        bool                        IsEmpty()                                           const;
        
        // - Funciones de comparación
        bool        IsSubsetOf(const DoubleLinkedList<Type> &li)    const;
        bool        IsSupersetOf(const DoubleLinkedList<Type> &li)  const;
        bool        IsEqual(const DoubleLinkedList<Type> &li)       const;
        
        // - Funciones de impresión
        void        Print();
        void        PrintReverse();


    private:
        // --- Atributos ---
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

        // --- Métodos privados ---
        bool    IsValidIndex(unsigned index)    const;
        Type*   GetPointer(unsigned index);
};

#include "../Templates/DoubleLinkedList.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
