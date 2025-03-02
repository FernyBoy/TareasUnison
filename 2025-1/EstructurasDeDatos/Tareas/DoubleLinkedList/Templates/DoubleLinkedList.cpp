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
template <typename Type>
DoubleLinkedList<Type>::~DoubleLinkedList()
{
    Clear();
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

    Clear();

    for (Element *aux = li.firstElement; aux != nullptr; aux = aux -> nextElement) 
    {
        AddLast(aux -> value);
    }

    return *this;
}

template <typename Type>
Type DoubleLinkedList<Type>::operator[](unsigned int index) const
{
    return GetAt(index);
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
// -------------------------------
// --- Funciones de agregación ---
// -------------------------------
template <typename Type>
void DoubleLinkedList<Type>::AddFirst(Type val)
{
    Element *aux = new Element(val);

    if(IsEmpty())
    {
        firstElement = lastElement = aux;
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
        firstElement = lastElement = aux;
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
    else
    {
        Element *currentElement = firstElement;
        Element *aux = new Element(val);

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;
        
        aux -> prevElement = currentElement;
        aux -> nextElement = currentElement -> nextElement;
        currentElement -> nextElement = aux;

        ++size;
    }
}

template <typename Type>
void DoubleLinkedList<Type>::Concat(const DoubleLinkedList<Type> &li)
{
    if(li.IsEmpty()) return;

    if(li.size == 1)
    {
        AddLast(li.firstElement -> value);
    }
    else
    {
        for(Element *aux = li.firstElement; aux != nullptr; aux = aux -> nextElement)
        {
            AddLast(aux -> value);
        }
    }
}


// --------------------------------
// --- Funciones de eliminación ---
// --------------------------------
template <typename Type>
void DoubleLinkedList<Type>::RemoveFirst()
{
    if(IsEmpty()) throw "Lista vac\241a";
    
    Element *deleteElement = firstElement;

    if (size == 1) 
    {
        firstElement = lastElement = nullptr;
    }
    else 
    {
        firstElement = firstElement -> nextElement;
        firstElement -> prevElement = nullptr;
    }

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
        lastElement = lastElement -> prevElement;
        lastElement -> nextElement = nullptr;
        delete deleteElement;

        --size;
    }
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
        Element *aux = firstElement -> nextElement;

        for(unsigned i = 1; i < index; ++i) aux = aux -> nextElement;

        aux -> prevElement -> nextElement = aux -> nextElement;
        aux -> nextElement -> prevElement = aux -> prevElement;
        delete aux;

        --size;
    }
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveFrom(unsigned index)
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    if(IsEmpty()) throw "Lista vac\241a";

    if(index == 0) 
    {
        Clear();
    }
    else if(index == size - 1)
    {
        RemoveLast();
    }
    else
    {
        Element *aux = firstElement;
        
        for(unsigned i = 0; i < index; ++i)
        {
            aux = aux -> nextElement;
        }
        
        lastElement = aux -> prevElement;
        lastElement -> nextElement = nullptr;
        size = index;

        while(aux != nullptr)
        {
            Element *deleteElement = aux;
            aux = aux -> nextElementl;
            delete deleteElement;
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveRange(unsigned startIndex, unsigned endIndex)
{
    if(!IsValidIndex(startIndex)) throw "\326ndice de inicio inv\240lido";
    if(!IsValidIndex(endIndex)) throw "\326ndice final inv\240lido";
    if(startIndex > endIndex) throw "\326ndices inv\240lidos";
    if(IsEmpty()) throw "Lista vac\241a";

    if(startIndex == 0 && endIndex == 0) 
    {
        RemoveFirst();
    }
    else if(startIndex == size - 1 && endIndex == size - 1)
    {
        RemoveLast();
    }
    else if(startIndex == 0 && endIndex == size - 1)
    {
        Clear();
    }
    else if(endIndex == size - 1)
    {
        RemoveFrom(startIndex);
    }
    else
    {
        Element *aux = firstElement;
        
        for(unsigned i = 0; i < startIndex; ++i)
        {
            aux = aux -> nextElement;
        }

        Element *temporalLastElement = aux -> prevElement;

        for(unsigned i = startIndex; i <= endIndex; i++)
        {
            Element *deleteElement = aux;
            aux = aux -> nextElementl;
            delete deleteElement;
            
            --size;
        }

        aux -> prevElement = temporalLastElement;
    }   
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
        for(Element *aux = firstElement -> nextElement; aux != nullptr; aux = aux -> nextElement)
        {
            if(aux -> value == val)
            {
                if(aux -> nextElement == nullptr)
                {
                    aux -> prevElement -> nextElement = nullptr;
                }
                else
                {
                    aux -> prevElement -> nextElement = aux -> nextElement;
                    aux -> nextElement -> prevElement = aux -> prevElement;
                }

                delete aux;
                --size;
                return;
            };
        }
    }

    throw "Valor no encontrado en la lista";
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveDuplicates(Type val)
{

}

template <typename Type>
void DoubleLinkedList<Type>::RemoveAllElements(Type val)
{

}

template <typename Type>
void DoubleLinkedList<Type>::RemoveMatching(const DoubleLinkedList<Type> &li)
{

}

template <typename Type>
void DoubleLinkedList<Type>::RemoveIf(bool (*condition)(Type))
{

}

template <typename Type>
void DoubleLinkedList<Type>::Clear()
{
    while(!IsEmpty()) RemoveFirst();
}


// ---------------------------------
// --- Funciones de modificación ---
// ---------------------------------
template <typename Type>
void DoubleLinkedList<Type>::SetAt(unsigned index, Type val)
{

}

template <typename Type>
void DoubleLinkedList<Type>::Clone(const DoubleLinkedList<Type> &li)
{

}


// ----------------------------------
// --- Funciones de transferencia ---
// ----------------------------------
template <typename Type>
void DoubleLinkedList<Type>::Swap(DoubleLinkedList<Type> &li)
{

}

template <typename Type>
void DoubleLinkedList<Type>::TransferAll(DoubleLinkedList<Type> &li)
{
    if(IsEmpty()) return;

    if(size == 1)
    {
        li.AddLast(firstElement -> value);
    }
    else 
    {
        for(Element *aux = firstElement; aux != nullptr; aux = aux -> nextElement)
        {
            li.AddLast(aux -> value);
        }
    }

    Clear();
}

template <typename Type>
void DoubleLinkedList<Type>::TransferFrom(unsigned index, DoubleLinkedList<Type> &li)
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";

    if(size == 1)
    {
        li.AddLast(firstElement -> value);
        Clear();
    }
    else if(index == size - 1)
    {
        li.AddLast(lastElement -> value);
        RemoveLast();
    }
    else
    {
        Element *aux = firstElement;
        
        for(unsigned i = 0; i < index; ++i)
        {
            aux = aux -> nextElement;
            size = i;
        }

        aux -> prevElement -> nextElement = nullptr;

        while(aux != nullptr)
        {
            Element *deleteElement = aux;
            li.AddLast(aux -> value);
            aux = aux -> nextElementl;
            delete deleteElement;
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::TransferRange(unsigned startIndex, unsigned endIndex, DoubleLinkedList<Type> &li)
{

}


// ------------------------------
// --- Funciones de conjuntos ---
// ------------------------------
template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::Union(const DoubleLinkedList<Type> &li)
{

}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::Intersection(const DoubleLinkedList<Type> &li)
{

}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::Difference(const DoubleLinkedList<Type> &li)
{

}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::SymmetricDifference(const DoubleLinkedList<Type> &li)
{

}


// ---------------------------------
// --- Funciones de ordenamiento ---
// ---------------------------------
template <typename Type>
void DoubleLinkedList<Type>::Reverse()
{

}

template <typename Type>
void DoubleLinkedList<Type>::SortAscending()
{

}

template <typename Type>
void DoubleLinkedList<Type>::SortDescending()
{

}


// ------------------------------
// --- Funciones de obtención ---
// ------------------------------
template <typename Type>
Type DoubleLinkedList<Type>::GetFirst() const
{
    if(IsEmpty()) throw "Lista vaci\241a";

    return firstElement -> value;
}


template <typename Type>
Type DoubleLinkedList<Type>::GetLast() const
{
    if(IsEmpty()) throw "Lista vaci\241a";

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
        Element *currentElement = firstElement -> nextElement;

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;

        return currentElement -> value;
    }
}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::GetFrom(unsigned index) const
{

}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::GetRange(unsigned startIndex, unsigned endIndex) const
{

}

template <typename Type>
bool DoubleLinkedList<Type>::Contains(Type val) const
{

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
unsigned DoubleLinkedList<Type>::Size() const
{
    return size;
}

template <typename Type>
bool DoubleLinkedList<Type>::IsEmpty() const
{
    return !size;
}


// --------------------------------
// --- Funciones de comparación ---
// --------------------------------
template <typename Type>
bool DoubleLinkedList<Type>::IsSubsetOf(const DoubleLinkedList<Type> &li) const
{

}

template <typename Type>
bool DoubleLinkedList<Type>::IsSupersetOf(const DoubleLinkedList<Type> &li) const
{

}

template <typename Type>
bool DoubleLinkedList<Type>::IsEqual(const DoubleLinkedList<Type> &li) const
{

}


// ------------------------------
// --- Funciones de impresión ---
// ------------------------------
template <typename Type>
void DoubleLinkedList<Type>::Print()
{
    if(IsEmpty()) throw "Lista vac\241a";

    cout << "[ ";
    for(Element *aux = firstElement; aux != nullptr; aux = aux -> nextElement) 
    {
        cout << aux -> value << ", ";
    }
    cout << "\b\b ]";
}

template <typename Type>
void DoubleLinkedList<Type>::PrintReverse()
{
    if(IsEmpty()) throw "Lista vac\241a";

    cout << "[ ";
    for(Element *aux = lastElement; aux != nullptr; aux = aux -> prevElement) 
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
    return index < size;
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
template <typename Type>
std::ostream & operator<<(std::ostream &output, DoubleLinkedList<Type> &li)
{
    li.Print();

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
