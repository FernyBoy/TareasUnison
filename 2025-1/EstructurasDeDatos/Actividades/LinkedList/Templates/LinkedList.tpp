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
LinkedList<Type>::LinkedList() : size(0), firstElement(nullptr), lastElement(nullptr) {}

template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList &li)
{   
    *this = li;
}

// ----------------------
// ----- Destructor -----
// ----------------------
// 
template <typename Type>
LinkedList<Type>::~LinkedList()
{
    ClearList();
}


 
// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Operadores ---------------------------
//
// --------------------------------------------
template <typename Type>
LinkedList<Type> & LinkedList<Type>::operator=(const LinkedList<Type> &li)
{
    if (this == &li) return *this;

    ClearList();

    for (Element *aux = li.firstElement; aux!= nullptr; aux = aux -> nextElement) 
    {
        AddLast(aux -> value);
    }

    return *this;
}

template <typename Type>
Type LinkedList<Type>::operator[](unsigned int index)
{
    return GetAt(index);
}



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
    Element *aux = new Element(val);

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
    Element *aux = new Element(val);

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

template <typename Type>
void LinkedList<Type>::AddAt(Type val, unsigned index)
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    
    if(index == 0) 
    {
        AddFirst(val);
    }
    else
    {
        Element *currentElement = firstElement;
        Element *aux = new Element(val);

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;

        aux -> nextElement = currentElement -> nextElement;
        currentElement -> nextElement = aux;

        ++size;
    }
}

// --- Funciones de eliminación
template <typename Type>
void LinkedList<Type>::RemoveFirst()
{
    if(IsEmpty()) throw "Lista vac\241a";
    
    Element *deleteElement = firstElement;
    firstElement = firstElement -> nextElement;
    delete deleteElement;

    --size;
}

template <typename Type>
void LinkedList<Type>::RemoveLast()
{
    if(IsEmpty()) throw "Lista vac\241a";

    if(size == 1)
    {
        RemoveFirst();
    }
    else
    {
        Element *aux = firstElement;

        for(unsigned i = 1; i < size - 1; ++i) aux = aux -> nextElement;

        delete lastElement;
        lastElement = aux;
        lastElement -> nextElement = NULL;
    }

    --size;
}

template <typename Type>
void LinkedList<Type>::RemoveAt(unsigned int index)
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    if(IsEmpty()) throw "Lista vac\241a";

    if(index == 0) 
    {
        RemoveFirst();
    }
    else if(index == size - 1)
    {
        RemoveLast();
    }
    else
    {
        Element *aux = firstElement -> nextElement;

        for(unsigned i = 2; i < index; ++i) aux = aux -> nextElement;

        Element *deleteElement = aux -> nextElement;
        aux -> nextElement = aux -> nextElement -> nextElement;
        delete deleteElement;

        --size;
    }

}

template <typename Type>
void LinkedList<Type>::RemoveElement(Type val)
{
    if(IsEmpty()) throw "Lista vac\241a";
    
    if(firstElement -> value == val)
    {
        RemoveFirst();
    }
    else
    {
        Element *previous = firstElement;
        Element *aux = firstElement -> nextElement;

        for(unsigned i = 1; i < size; ++i)
        {
            if(aux -> value == val)
            {
                previous -> nextElement = aux -> nextElement;
                delete aux;
                --size;
                return;
            };
            previous = aux;
            aux = aux -> nextElement;
        }
    }

    throw "Valor no encontrado en la lista";
}

// --- Funciones de obtención
template <typename Type>
Type LinkedList<Type>::GetFirst() const
{
    if(IsEmpty()) throw "Lista vaci\241a";

    return firstElement -> value;
}

template <typename Type>
Type LinkedList<Type>::GetLast() const
{
    if(IsEmpty()) throw "Lista vaci\241a";

    return lastElement -> value;
}

template <typename Type>
Type LinkedList<Type>::GetAt(unsigned index) const
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    if(IsEmpty()) throw "Lista vac\241a";

    if(index == 0) 
    {
        return GetFirst();
    }
    else if(index == size - 1)
    {
        return GetLast();
    }
    else
    {
        Element *currentElement = firstElement -> nextElement;

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;

        return currentElement -> value;
    }
}

template <typename Type>
unsigned LinkedList<Type>::IndexOf(Type val) const
{
    if(IsEmpty()) throw "Lista vac\241a";

    if(firstElement -> value == val) return 0;

    Element *aux = firstElement -> nextElement;

    for(unsigned i = 1; i < size; ++i)
    {
        if(aux -> value == val) return i;
        aux = aux -> nextElement;
    }

    throw "Valor no encontrado en la lista";
}

template <typename Type>
unsigned LinkedList<Type>::ListSize() const
{
    return size;
}

template <typename Type>
bool LinkedList<Type>::IsEmpty() const
{
    return !size;
}

// --- Otras funciones
template <typename Type>
void LinkedList<Type>::ClearList()
{
    while(!IsEmpty()) RemoveFirst();
}

template <typename Type>
void LinkedList<Type>::PrintList()
{
    if(IsEmpty()) throw "Lista vac\241a";

    cout << "[ ";
    for(Element *aux = firstElement; aux != nullptr; aux = aux -> nextElement) 
    {
        cout << aux -> value << ", ";
    }
    cout << "\b\b ]";
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template <typename Type>
bool LinkedList<Type>::IsValidIndex(unsigned index) const
{
    return index <= size - 1;
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
template <typename Type>
std::ostream & operator<<(std::ostream &output, LinkedList<Type> &li)
{
    li.PrintList();

    return output;
}

template <typename Type>
std::istream & operator>>(std::istream &input, LinkedList<Type> &li)
{
    Type val;
    input >> val;

    li.AddLast(val);

    return input;
}

