/**
*   \file   SDLL.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   05/03/2025
*/

#ifndef SDLL_HPP_INCLUDED
#define SDLL_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class SDLL
{
    // --- Métodos externos --- 
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const SDLL<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, SDLL<T> &li);

    public:
        typedef bool (*fun)(Type);

        // --- Constructores ---
        explicit SDLL();
        SDLL(const SDLL &li);
        // - Destructor
        ~SDLL();

        // --- Operadores ---
        SDLL&       operator=(const SDLL &li);
        Type        operator=(Type val);
        Type        operator[](unsigned int index) const;
        Type*       operator[](unsigned int index);

        // --- Métodos públicos ---
        // - Funciones de agregación
        void        Add(Type val);

        // - Funciones de eliminación
        void        RemoveFrom(unsigned index);
        void        RemoveRange(unsigned startIndex, unsigned endIndex);
        void        RemoveElement(Type val);
        void        RemoveDuplicates();
        void        RemoveAllElements(Type val);
        void        RemoveMatching(const SDLL<Type> &li);
        void        RemoveIf(fun condition);
        void        Clear();

        // - Funciones de modificación
        void        SetAt(unsigned index, Type val);
        void        Clone(const SDLL<Type> &li);
        
        // - Funciones de transferencia
        void        Swap(SDLL<Type> &li);
        void        TransferAll(SDLL<Type> &li);
        void        TransferFrom(unsigned index, SDLL<Type> &li);
        void        TransferRange(unsigned startIndex, unsigned endIndex, SDLL<Type> &li);
        
        // - Funciones de ordenamiento
        void        Reverse();
        void        SortAscending();
        void        SortDescending();
    
        // - Funciones de obtención
        Type                        GetFirst()                                          const;
        Type                        GetLast()                                           const;
        Type                        GetAt(unsigned index)                               const;
        SDLL<Type>                  GetFrom(unsigned index)                             const;
        SDLL<Type>                  GetRange(unsigned startIndex, unsigned endIndex)    const;
        bool                        Contains(Type val)                                  const;
        unsigned                    IndexOf(Type val)                                   const;
        unsigned                    Size()                                              const;
        bool                        IsEmpty()                                           const;
        
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

#include "../Templates/SDLL.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
