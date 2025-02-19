/**
*   \file   LinkedList.tpp
*   \author 
*   \date   
*/

#include "../Headers/LinkedList.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
LinkedList<Type>::LinkedList() : size(0), nextElement(NULL) {}

/*
template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList &li)
{   

}


// ----------------------
// ----- Destructor -----
// ----------------------
// 
template <typename Type>
LinkedList<Type>::~LinkedList()
{

}
*/


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Operadores ---------------------------
//
// --------------------------------------------
/*
template <typename Type>
LinkedList<Type> & LinkedList<Type>::operator=(const LinkedList<Type> &li)
{

}

template <typename Type>
Type LinkedList<Type>::operator[](unsigned int i)
{

}
*/


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
// --- Funciones de agregación
template <typename Type>
void LinkedList<Type>::AddFirst(Type val)
{
    Element *aux = new Element;
    aux -> value = val;

    if(IsEmpty())
    {
        firstElement = aux;
        lastElement = aux;
    }
    else
    {
        aux -> nextElement = firstElement;
        firstElement = aux;
    }

    ++size;
}

template <typename Type>
void LinkedList<Type>::AddLast(Type val)
{
    Element *aux = new Element;
    aux -> value = val;

    if(IsEmpty())
    {
        firstElement = aux;
        lastElement = aux;
    }
    else
    {
        lastElement -> nextElement = aux;
        lastElement = aux;
    }
    
    ++size;
}
/*
template <typename Type>
void LinkedList<Type>::AddAt(Type val, unsigned int i)
{

}
*/
// --- Funciones de eliminación
template <typename Type>
void LinkedList<Type>::RemoveFirst()
{
    if(IsEmpty()) throw "Lista vac\241a";
}

template <typename Type>
void LinkedList<Type>::RemoveLast()
{
    if(IsEmpty()) throw "Lista vac\241a";
}

template <typename Type>
void LinkedList<Type>::RemoveAt(unsigned int i)
{
    if(IsEmpty()) throw "Lista vac\241a";
}

template <typename Type>
void LinkedList<Type>::Remove(Type val)
{
    if(IsEmpty()) throw "Lista vac\241a";
}

// --- Funciones de obtención
template <typename Type>
Type LinkedList<Type>::GetFirst() const
{
    return firstElement -> value;
}

template <typename Type>
Type LinkedList<Type>::GetLast() const
{
    return lastElement -> value;
}
/*
template <typename Type>
Type LinkedList<Type>::GetAt(unsigned int i) const
{

}

template <typename Type>
unsigned LinkedList<Type>::IndexOf(Type val) const
{

}
*/
template <typename Type>
unsigned LinkedList<Type>::ListSize() const
{
    return size;
}

template <typename Type>
bool LinkedList<Type>::IsEmpty()
{
    return !size;
}
/*
// --- Otras funciones
template <typename Type>
void LinkedList<Type>::ClearList()
{

}
*/
template <typename Type>
void LinkedList<Type>::PrintList()
{
    Element *aux = firstElement;

    for(unsigned i = 0; i < size; ++i)
    {
        cout << "\n| " << aux -> value << " |";
        aux = aux -> nextElement;
    }
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
/* 
template <typename Type>
std::ostream & operator<<(std::ostream &output, LinkedList<Type> &li)
{
    

    return output;
}


template <typename Type>
std::istream & operator>>(std::istream &input, LinkedList<Type> &li)
{
    

    return input;
}
*/
