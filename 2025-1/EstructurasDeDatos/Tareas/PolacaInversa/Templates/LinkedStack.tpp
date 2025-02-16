/**
*   \file   LinkedLinkedStack.tpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   15/02/2025
*/

#include "../Headers/LinkedStack.hpp" 
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// template <typename T>
// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
LinkedStack<Type>::LinkedStack() : size(0), topElement(NULL) {  }

template <typename Type>
LinkedStack<Type>::LinkedStack(const LinkedStack &s) : size(0), topElement(NULL)
{
    *this = s;
}

template<typename Type>
LinkedStack<Type> & LinkedStack<Type>::operator=(const LinkedStack<Type> &s)
{
    if(this == &s) return *this;

    ClearStack();
     
    if(!s.IsEmpty())
    {
        Push(s.Top());

        Element *aux = topElement;
        Element *aux2 = s.topElement -> nextElement;

        while (aux2 != nullptr) 
        {
            aux -> nextElement = new Element;
            aux -> nextElement -> value = aux2 -> value;
            aux = aux -> nextElement;
            aux2 = aux2 -> nextElement;
        }
    }

    size = s.size;
    return *this;
}
// ----------------------
// ----- Destructor -----
// ----------------------

template<typename Type>
LinkedStack<Type>::~LinkedStack()
{
    ClearStack();
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------

template<typename Type>
void LinkedStack<Type>::Push(Type val)
{
    Element *newElement = new Element;
    newElement -> value = val;
    newElement -> nextElement = topElement;
    topElement = newElement;

    ++size;
}

template<typename Type>
void LinkedStack<Type>::Pop()
{
    if(IsEmpty()) throw "Pila vac\241";

    Element *deleteElement = topElement;
    topElement = topElement -> nextElement;
    delete deleteElement;

    --size;
}

template<typename Type>
Type LinkedStack<Type>::Top() const
{
    if(IsEmpty()) throw "Pila vac\241a";

    return topElement -> value;
}

template<typename Type>
bool LinkedStack<Type>::IsEmpty() const
{
    return !size;
}

template<typename Type>
void LinkedStack<Type>::ClearStack()
{
    while(!IsEmpty()) Pop();
}

template<typename Type>
unsigned LinkedStack<Type>::StackSize() const
{
    return size;
}

template<typename Type>
void LinkedStack<Type>::PrintElements()
{
    Element *auxElement = topElement;

    cout << "\n|\t\t|";

    for(unsigned i = 0; i < size; ++i)
    {
        cout << "\n|\t" << auxElement -> value << "\t|";

        cout << "\n|\t\t|";

        auxElement = auxElement -> nextElement;
    }
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template<typename Type>
void LinkedStack<Type>::ResizeStack(unsigned int i)
{
    for(int j = 0; j < i; ++j)
    {
        Pop();
    }
}


// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// ------------------------------------------




// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
template<typename Type>
std::ostream & operator<<(std::ostream &output, LinkedStack<Type> &s)
{
    for(unsigned i = 0; i < s.UsedCapacity(); ++i)
    {
        cout << s[i] << endl;
    } 
    
    return output;
}

/*
std::istream & operator>>(std::istream &input, LinkedStack &s)
{

}
*/
