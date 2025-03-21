/**
*   \file   CircularList.tpp
*   \author Angel Fernando Borquez Guerrero
*   \date   11/03/2025
*/

#include "../Headers/CircularList.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
CircularList<Type>::CircularList() : size(0), head(nullptr) {}

/*
template <typename Type>
CircularList<Type>::CircularList(const CircularList &li)
{   

}

template <typename Type>
CircularList<Type> & CircularList<Type>::operator=(const CircularList<Type> &li)
{

}
*/
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
CircularList<Type>::~CircularList()
{
    Clear();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template <typename Type>
void CircularList<Type>::Add(Type val)
{
    Element *aux = new Element(val);
    
    if(Empty())
    {

        aux -> prevElement = aux;
        aux -> nextElement = aux;
        head = aux;
    }
    else
    {
        aux -> nextElement = head;
        aux -> prevElement = head -> prevElement;
        
        head -> prevElement -> nextElement = aux;
        head -> prevElement = aux;

        head = aux;
    }

    ++size;
}

template <typename Type>
void CircularList<Type>::RemoveHead()
{
    if(Empty()) throw "Lista vac\241a";

    if(size == 1)
    {
        delete head;
        head = nullptr;
        size = 0;
    }
    else
    {
        Element* deleteElement = head;
        head -> prevElement -> nextElement = head -> nextElement;
        head -> nextElement -> prevElement = head -> prevElement;
        delete deleteElement;
    }

    --size;
}
/*
template <typename Type>
bool CircularList<Type>::Contains(Type val)
{
    
}
*/
template <typename Type>
void CircularList<Type>::MoveForward()
{
    if(Empty()) throw "Lista vac\241a";
    
    if(size == 1) return;
    else head = head -> nextElement;
}

template <typename Type>
void CircularList<Type>::MoveBackward()
{
    if(Empty()) throw "Lista vac\241a";
    
    if(size == 1) return;
    else head = head -> prevElement;
}

template <typename Type>
Type CircularList<Type>::GetHead()
{
    return head -> value;
}

template <typename Type>
unsigned CircularList<Type>::Size()
{
    return size;
}

template <typename Type>
bool CircularList<Type>::Empty()
{
    return size == 0;
}

template <typename Type>
void CircularList<Type>::Clear()
{
    while(!Empty()) RemoveHead();
}

template <typename Type>
void CircularList<Type>::Print()
{
    if(Empty()) throw "Lista vac\241a";

    Element* aux = head;

    cout << "[ ";
    for(unsigned i  = 0; i < size; ++i)
    {
        cout << aux -> value << ", ";
        aux = aux -> nextElement;
    }
    cout << "\b\b ]";
}
/*
template <typename Type>
void CircularList<Type>::PrintReverse()
{

}
*/


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template <typename Type>
bool CircularList<Type>::IsValidIndex(unsigned index) const
{
    return index < size;
}



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
std::ostream & operator<<(std::ostream &output, CircularList<Type> &li)
{
    

    return output;
}


template <typename Type>
std::istream & operator>>(std::istream &input, CircularList<Type> &li)
{
    

    return input;
}
*/
