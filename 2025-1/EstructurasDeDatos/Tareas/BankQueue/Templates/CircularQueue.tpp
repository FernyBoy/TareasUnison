/**
*   \file   CircularQueue.tpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   23/02/2025
*/

#include "../Headers/CircularQueue.hpp" 
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
CircularQueue<Type>::CircularQueue() : size(0), rearElement(NULL) {  }

template <typename Type>
CircularQueue<Type>::CircularQueue(const CircularQueue &s) : size(0), rearElement(NULL)
{
    *this = s;
}

template<typename Type>
CircularQueue<Type> & CircularQueue<Type>::operator=(const CircularQueue<Type> &s)
{
    if(this == &s) return *this;

    ClearQueue();
     
    if(!s.IsEmpty())
    {
        Enqueue(s.Front());

        Element *aux = rearElement -> nextElement;
        Element *aux2 = s.rearElement -> nextElement -> nextElement;

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
CircularQueue<Type>::~CircularQueue()
{
    ClearQueue();
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template<typename Type>
void CircularQueue<Type>::Enqueue(Type val)
{
    Element *newElement = new Element;
    newElement -> value = val;
    
    if(IsEmpty())
    {
        rearElement = newElement;
        rearElement -> nextElement = rearElement;
    }
    else 
    {
        newElement -> nextElement = rearElement -> nextElement;
        rearElement -> nextElement = newElement;
        rearElement = newElement;
    }

    ++size;
}

template<typename Type>
void CircularQueue<Type>::Dequeue()
{
    if(IsEmpty()) throw "Fila vac\241";

    Element *deleteElement = rearElement -> nextElement;

    if(rearElement == rearElement -> nextElement)
    {
        rearElement = NULL;   
    }
    else 
    {
        rearElement -> nextElement = deleteElement -> nextElement;
    }
   
    delete deleteElement;
    --size;
}

template<typename Type>
Type CircularQueue<Type>::Front() const
{
    if(IsEmpty()) throw "Fila vac\241a";

    return rearElement -> nextElement -> value;
}

template<typename Type>
Type CircularQueue<Type>::Rear() const
{
    if(IsEmpty()) throw "Fila vac\241a";

    return rearElement -> value;
}

template<typename Type>
bool CircularQueue<Type>::IsEmpty() const
{
    return !size;
}

template<typename Type>
void CircularQueue<Type>::ClearQueue()
{
    while(!IsEmpty()) Dequeue();
}

template<typename Type>
unsigned CircularQueue<Type>::QueueSize() const
{
    return size;
}

template<typename Type>
void CircularQueue<Type>::PrintElements()
{
    if(IsEmpty()) 
    {
        cout << "\n|";
        return;
    }

    Element *auxElement = rearElement -> nextElement;

    for(unsigned i = 0; i < size; ++i)
    {
        cout << "\n|\t" << auxElement -> value;

        auxElement = auxElement -> nextElement;
    }
}
