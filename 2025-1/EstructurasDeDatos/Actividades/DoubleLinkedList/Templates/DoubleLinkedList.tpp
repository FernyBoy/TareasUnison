/**
*   \file   DoubleLinkedList.tpp
*   \author 
*   \date   
*/

#include "../Headers/DoubleLinkedList.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
DoubleLinkedList<Type>::DoubleLinkedList() : size(0), firstElement(nullptr), lastElement(nullptr) {}

template <typename Type>
DoubleLinkedList<Type>::DoubleLinkedList(const DoubleLinkedList &li)
{   
    *this = li;
}

// ----------------------
// ----- Destructor -----
// ----------------------
// 
template <typename Type>
DoubleLinkedList<Type>::~DoubleLinkedList()
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
DoubleLinkedList<Type> & DoubleLinkedList<Type>::operator=(const DoubleLinkedList<Type> &li)
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
Type DoubleLinkedList<Type>::operator[](unsigned int index)
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
void DoubleLinkedList<Type>::AddFirst(Type val)
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
        firstElement -> prevElement = aux;
        firstElement = aux;
    }

    ++size;
}

template <typename Type>
void DoubleLinkedList<Type>::AddLast(Type val)
{
    Element *aux = new Element(val);

    if(IsEmpty())
    {
        firstElement = aux;
        lastElement = aux;
    }
    else
    {
        aux -> prevElement = lastElement;
        lastElement -> nextElement = aux;
        lastElement = aux;
    }
    
    ++size;
}

template <typename Type>
void DoubleLinkedList<Type>::AddAt(Type val, unsigned index)
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    
    if(index == 0) 
    {
        AddFirst(val);
    }
    else if(index == size - 1)
    {
        AddLast(val);
    }
    else
    {
        Element *currentElement = firstElement;
        Element *aux = new Element(val);

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;
    
        aux -> prevElement = currentElement;
        aux -> nextElement = currentElement -> nextElement;
        currentElement -> nextElement = aux;
    }

    ++size;
}

// --- Funciones de eliminación
template <typename Type>
void DoubleLinkedList<Type>::RemoveFirst()
{
    if(IsEmpty()) throw "Lista vac\241a";
    
    Element *deleteElement = firstElement;
    firstElement -> nextElement -> prevElement = nullptr;
    firstElement = firstElement -> nextElement;
    delete deleteElement;

    --size;
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveLast()
{
    if(IsEmpty()) throw "Lista vac\241a";

    if(size == 1)
    {
        RemoveFirst();
    }
    else
    {
        Element *deleteElement = lastElement;
        lastElement -> prevElement -> nextElement = nullptr;
        lastElement = lastElement -> prevElement;
        delete deleteElement; 
    }

    --size;
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveAt(unsigned int index)
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
        Element *aux = firstElement;

        for(unsigned i = 1; i < index; ++i) aux = aux -> nextElement;

        Element *deleteElement = aux;
        aux -> prevElement -> nextElement = aux -> nextElement;
        aux -> nextElement -> prevElement = aux -> prevElement;
        delete deleteElement;
    }

    --size;
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveElement(Type val)
{
    if(IsEmpty()) throw "Lista vac\241a";
    
    if(firstElement -> value == val)
    {
        RemoveFirst();
    }
    else
    {
        Element *aux = firstElement -> nextElement;

        for(unsigned i = 1; i < size; ++i)
        {
            if(aux -> value == val)
            {
                Element *deleteElement = aux;
                aux -> prevElement -> nextElement = aux -> nextElement;
                aux -> nextElement -> prevElement = aux -> prevElement;
                delete deleteElement;

                return;
            };
        }
    }

    throw "Valor no encontrado en la lista";
}

// --- Funciones de obtención
template <typename Type>
Type DoubleLinkedList<Type>::GetFirst() const
{
    return firstElement -> value;
}

template <typename Type>
Type DoubleLinkedList<Type>::GetLast() const
{
    return lastElement -> value;
}

template <typename Type>
Type DoubleLinkedList<Type>::GetAt(unsigned index) const
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
        Element *currentElement = firstElement;

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;

        return currentElement -> value;
    }
}

template <typename Type>
unsigned DoubleLinkedList<Type>::IndexOf(Type val) const
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
unsigned DoubleLinkedList<Type>::ListSize() const
{
    return size;
}

template <typename Type>
bool DoubleLinkedList<Type>::IsEmpty() const
{
    return !size;
}

// --- Otras funciones
template <typename Type>
void DoubleLinkedList<Type>::ClearList()
{
    while(!IsEmpty()) RemoveFirst();
}

template <typename Type>
void DoubleLinkedList<Type>::PrintList()
{
    if(IsEmpty()) throw "Lista vac\241a";

    cout << "[ ";
    for(Element *aux = firstElement; aux->nextElement != nullptr; aux = aux ->nextElement)
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
bool DoubleLinkedList<Type>::IsValidIndex(unsigned index) const
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
std::ostream & operator<<(std::ostream &output, DoubleLinkedList<Type> &li)
{
    li.PrintList();

    return output;
}

template <typename Type>
std::istream & operator>>(std::istream &input, DoubleLinkedList<Type> &li)
{
    Type val;
    input >> val;

    li.AddLast(val);

    return input;
}

