/**
*   \file   DoubleLinkedList.tpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   04/03/2025
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
    for(Element* aux = li.firstElement; aux != nullptr; aux = aux -> nextElement)
    {
        AddLast(aux -> value);
    }
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

    if(li.size == 1) AddFirst(li.GetFirst());
    for(Element *aux = li.firstElement; aux != nullptr; aux = aux -> nextElement) 
    {
        AddLast(aux -> value);
    }

    return *this;
}

template <typename Type>
Type DoubleLinkedList<Type>::operator=(Type val)
{
    return val;
}

template <typename Type>
Type DoubleLinkedList<Type>::operator[](unsigned int index) const
{
    return GetAt(index);
}

template <typename Type>
Type* DoubleLinkedList<Type>::operator[](unsigned int index)
{
    return GetPointer(index);
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
        Element *aux = li.firstElement;
        unsigned listSize = li.size;

        for(unsigned i = 0; i < listSize; ++i)
        {
            AddLast(aux -> value);
            aux = aux -> nextElement;
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
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";

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
            aux = aux -> nextElement;
            delete deleteElement;
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveRange(unsigned startIndex, unsigned endIndex)
{
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(startIndex)) throw "\326ndice de inicio inv\240lido";
    if(!IsValidIndex(endIndex)) throw "\326ndice final inv\240lido";
    if(startIndex > endIndex) throw "\326ndices inv\240lidos";

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
            aux = aux -> nextElement;
            delete deleteElement;
            
            --size;
        }
        
        temporalLastElement -> nextElement = aux;
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
void DoubleLinkedList<Type>::RemoveDuplicates()
{
    if(IsEmpty()) return;

    if(size == 1) return;
    else if(size == 2)
    {
        if(firstElement -> value == firstElement -> nextElement -> value)
        {
            RemoveLast();
        }
    }
    else
    {
        for (Element* aux = firstElement; aux != nullptr; aux = aux -> nextElement)
        {
            Type currentValue = aux -> value;
            Element* currentElement = aux -> nextElement;

            while (currentElement != nullptr)
            {
                Element* next = currentElement -> nextElement;

                if (currentElement -> value == currentValue)
                {
                    if (currentElement -> prevElement) 
                        currentElement -> prevElement->nextElement = currentElement -> nextElement;
                    if (currentElement -> nextElement) 
                        currentElement -> nextElement->prevElement = currentElement -> prevElement;

                    if (currentElement == lastElement) 
                        lastElement = currentElement -> prevElement;

                    delete currentElement;
                    --size;
                }

                currentElement = next;
            }
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveAllElements(Type val)
{
    if(IsEmpty()) throw "Lista vac\241a";
    if(!Contains(val)) throw "Valor inv\240lido";

    Element *currentElement = firstElement;

    while(currentElement != nullptr)
    {
        Element *aux = currentElement -> nextElement;

        if(currentElement -> value == val)
        {
            RemoveAt(IndexOf(currentElement->value));
        }
        currentElement = aux;
    }
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveMatching(const DoubleLinkedList<Type> &li)
{
    if (IsEmpty() || li.IsEmpty()) throw "Lista vac\241a";

    Element *currentElement = firstElement;

    while (currentElement != nullptr) 
    {
        Element *aux = li.firstElement;

        while (aux != nullptr) 
        {
            if (aux -> value == currentElement -> value) 
            {
                this -> RemoveElement(currentElement->value);
            }
            aux = aux->nextElement;
        }

        currentElement = currentElement->nextElement;
    }
}

template <typename Type>
void DoubleLinkedList<Type>::RemoveIf(fun condition)
{
    if (IsEmpty()) throw "Lista vac\241a";

    Element* aux = firstElement;

    while (aux != nullptr)
    {
        Element* next = aux -> nextElement;

        if (condition(aux->value))
        {
            if (aux == firstElement) 
            {
                RemoveFirst();
            }
            else if (aux == lastElement) 
            {
                RemoveLast();
            }
            else 
            {
                aux->prevElement->nextElement = aux->nextElement;
                aux->nextElement->prevElement = aux->prevElement;
                delete aux;
                --size;
            }
        }

        aux = next;
    }
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
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    
    if(index == 0) firstElement -> value = val;
    else if(index == size - 1) lastElement -> value = val;
    else
    { 
        Element *aux = firstElement -> nextElement;

        for(unsigned i = 1; i < index; ++i)
        {
            aux = aux -> nextElement;
        }

        aux -> value = val;
    }
}

template <typename Type>
void DoubleLinkedList<Type>::Clone(const DoubleLinkedList<Type> &li)
{
    if(this == &li) return;

    Clear();

    if(li.size == 1) AddFirst(li.GetFirst());
    for(Element *aux = li.firstElement; aux != nullptr; aux = aux -> nextElement) 
    {
        AddLast(aux -> value);
    }
}

// ----------------------------------
// --- Funciones de transferencia ---
// ----------------------------------

template <typename Type>
void DoubleLinkedList<Type>::Swap(DoubleLinkedList<Type> &li)
{
    if(IsEmpty() && li.IsEmpty()) return;
    else if(size == 1 && li.size == 1)
    {
        Type temp = firstElement -> value;
        firstElement->value = li.firstElement -> value;
        li.firstElement -> value = temp;
    }
    else if(IsEmpty() && !li.IsEmpty())
    {
        Element* aux = li.firstElement;

        while(aux != nullptr)
        {
            Element* deleteElement = aux;
            AddLast(aux -> value);
            aux = aux -> nextElement;
            delete deleteElement;
        }
    }
    else if(!IsEmpty() && li.IsEmpty())
    {
        Element* aux = firstElement;

        while(aux != nullptr)
        {
            Element* deleteElement = aux;
            li.AddLast(aux -> value);
            aux = aux -> nextElement;
            delete deleteElement;
        }
    }
    else
    {
        unsigned secondListSize = li.size;

        while (firstElement != nullptr)
        {
            li.AddLast(firstElement->value);
            RemoveFirst();
        }
        
        for(unsigned i = 0; i < secondListSize; ++i)
        {
            AddLast(li.firstElement -> value);
            li.RemoveFirst();
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::TransferAll(DoubleLinkedList<Type> &li)
{
    if(IsEmpty()) return;
    if(this == &li) return;

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
    if(this == &li) return;
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";

    if(size == 1)
    {
        li.AddLast(firstElement -> value);
        RemoveLast();
    }
    else if(index == size - 1)
    {
        li.AddLast(lastElement -> value);
        RemoveLast();
    }
    else if(index == 0)
    {
        Element* aux = firstElement;

        while(aux != nullptr)
        {
            Element* deleteElement = aux;
            li.AddLast(aux -> value);
            aux = aux -> nextElement;
            delete deleteElement;
        }

        firstElement = nullptr;
        lastElement = nullptr;
        size = 0;
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
            li.AddLast(aux -> value);
            aux = aux -> nextElement;
            delete deleteElement;
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::TransferRange(unsigned startIndex, unsigned endIndex, DoubleLinkedList<Type> &li)
{
    if(this == &li) return;
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(startIndex)) throw "\326ndice de inicio inv\240lido";
    if(!IsValidIndex(endIndex)) throw "\326ndice final inv\240lido";
    if(startIndex > endIndex) throw "\326ndices inv\240lidos";

    if(startIndex == 0 && endIndex == 0) 
    {
        li.AddLast(firstElement -> value);
        RemoveFirst();
    }
    else if(startIndex == size - 1 && endIndex == size - 1)
    {
        li.AddLast(lastElement -> value);
        RemoveLast();
    }
    else if(startIndex == 0 && endIndex == size - 1)
    {
        TransferFrom(0, li);
        size = 0;
    }
    else if(endIndex == size - 1)
    {
        TransferFrom(startIndex, li);
    }
    else
    {
        Element* tempFirst = firstElement;
        Element* tempLast = lastElement;
        unsigned tempSize = size;

        firstElement = li.firstElement;
        lastElement = li.lastElement;
        size = li.size;

        li.firstElement = tempFirst;
        li.lastElement = tempLast;
        li.size = tempSize;
    }   
}


// ------------------------------
// --- Funciones de conjuntos ---
// ------------------------------
template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::Union(const DoubleLinkedList<Type> &li)
{
    DoubleLinkedList<Type> newList(*this);
    newList.Concat(li);

    return newList;
}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::Intersection(const DoubleLinkedList<Type> &li)
{
    DoubleLinkedList<Type> listIntersection;
    if (IsEmpty() || li.IsEmpty()) return listIntersection;

    Element *currentElement = firstElement;

    while (currentElement != nullptr) 
    {
        Element *aux = li.firstElement;

        while (aux != nullptr) 
        {
            if (aux->value == currentElement -> value) 
            {
                listIntersection.AddLast(aux -> value);
            }

            aux = aux -> nextElement;
        }

        currentElement = currentElement -> nextElement;
    }

    listIntersection.RemoveDuplicates();
    return listIntersection;
}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::Difference(const DoubleLinkedList<Type> &li)
{
    DoubleLinkedList<Type> differenceList = *this;
    differenceList.RemoveMatching(li);

    return differenceList;
}
/*
template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::SymmetricDifference(const DoubleLinkedList<Type> &li)
{

}
*/

// ---------------------------------
// --- Funciones de ordenamiento ---
// ---------------------------------
template <typename Type>
void DoubleLinkedList<Type>::Reverse()
{
    if (IsEmpty()) throw "Lista vacía";

    Element* currentElement = firstElement;
    Element* aux = nullptr;

    while (currentElement != nullptr) 
    {
        aux = currentElement -> prevElement;
        currentElement -> prevElement = currentElement -> nextElement;
        currentElement -> nextElement = aux;
        currentElement = currentElement -> prevElement;
    }

    aux = firstElement;
    firstElement = lastElement;
    lastElement = aux;
}

template <typename Type>
void DoubleLinkedList<Type>::SortAscending()
{
    if (IsEmpty()) throw "Lista vacía";
    if (Size() == 1) return;

    Element *current = firstElement->nextElement;

    while (current)     
    {
        Element *aux = current;
        Element *prev = current -> prevElement;
        current = current -> nextElement;


        aux->prevElement->nextElement = aux->nextElement;
        if (aux->nextElement) aux->nextElement->prevElement = aux->prevElement;


        if constexpr (std::is_same<Type, char>::value) 
        {
            aux->value = std::tolower(aux->value);
        } else if constexpr (std::is_same<Type, std::string>::value) {
            std::transform(aux->value.begin(), aux->value.end(), aux->value.begin(), ::tolower);
        }


        while (prev && aux->value < prev->value) {
            prev = prev->prevElement;
        }


        if (!prev) {
            aux->nextElement = firstElement;
            aux->prevElement = nullptr;
            firstElement->prevElement = aux;
            firstElement = aux;
        } else {
            aux->nextElement = prev->nextElement;
            aux->prevElement = prev;
            if (prev->nextElement) prev->nextElement->prevElement = aux;
            prev->nextElement = aux;
        }
    }
}

template <typename Type>
void DoubleLinkedList<Type>::SortDescending()
{
    if (IsEmpty()) throw "Lista vacía";
    if (Size() == 1) return;

    Element *current = firstElement->nextElement;

    while (current) {
        Element *aux = current;
        Element *prev = current->prevElement;

        current = current->nextElement;

        aux->prevElement->nextElement = aux->nextElement;
        if (aux->nextElement) aux->nextElement->prevElement = aux->prevElement;

        if constexpr (std::is_same<Type, char>::value) {
            aux->value = std::tolower(aux->value);
        } else if constexpr (std::is_same<Type, std::string>::value) {
            std::transform(aux->value.begin(), aux->value.end(), aux->value.begin(), ::tolower);
        }

        while (prev && aux->value > prev->value) {
            prev = prev->prevElement;
        }

        if (!prev) {
            aux->nextElement = firstElement;
            aux->prevElement = nullptr;
            firstElement->prevElement = aux;
            firstElement = aux;
        } else {
            aux->nextElement = prev->nextElement;
            aux->prevElement = prev;
            if (prev->nextElement) prev->nextElement->prevElement = aux;
            prev->nextElement = aux;
        }
    }
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
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";

    DoubleLinkedList<Type> auxList;

    if(index == 0) 
    {
        auxList.AddLast(firstElement -> value);
    }
    else if(index == size - 1)
    {
        auxList.Clone(*this);
    }
    else
    {
        Element *aux = firstElement;
        
        for(unsigned i = 0; i < index; ++i)
        {
            aux = aux -> nextElement;
        }

        for(unsigned i = index; i < size; i++)
        {
            auxList.AddLast(aux -> value);
            aux = aux -> nextElement;
        }
    }

    return auxList;
}

template <typename Type>
DoubleLinkedList<Type> DoubleLinkedList<Type>::GetRange(unsigned startIndex, unsigned endIndex) const
{
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(startIndex)) throw "\326ndice de inicio inv\240lido";
    if(!IsValidIndex(endIndex)) throw "\326ndice final inv\240lido";
    if(startIndex > endIndex) throw "\326ndices inv\240lidos";

    DoubleLinkedList<Type> auxList;

    if(startIndex == 0 && endIndex == 0) 
    {
        auxList.AddLast(firstElement -> value);
    }
    else if(startIndex == size - 1 && endIndex == size - 1)
    {
        auxList.AddLast(lastElement -> value);
    }
    else if(startIndex == 0 && endIndex == size - 1)
    {
        auxList.Clone(*this);
    }
    else if(endIndex == size - 1)
    {
        auxList = GetFrom(startIndex);
    }
    else
    {
        Element *aux = firstElement;
        
        for(unsigned i = 0; i < startIndex; ++i)
        {
            aux = aux -> nextElement;
        }
        
        for(unsigned i = startIndex; i <= endIndex; ++i)
        {
            auxList.AddLast(aux -> value);
            aux = aux -> nextElement;
        }
    }  

    return auxList;
}

template <typename Type>
bool DoubleLinkedList<Type>::Contains(Type val) const
{
    if(IsEmpty()) throw "Lista vac\241a";

    if(firstElement -> value == val) return true;
    else if(lastElement -> value == val) return true;
    else
    {
        for(Element *aux = firstElement -> nextElement; aux != nullptr; aux = aux -> nextElement)
        {
            if(aux -> value == val) return true;
        }
    }

    return false;
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
/*
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
*/

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

template <typename Type>
Type* DoubleLinkedList<Type>::GetPointer(unsigned index)
{
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";
    if(IsEmpty()) throw "Lista vac\241a";

    if(index == 0) 
    {
        return &(firstElement -> value);
    }
    else if(index == size - 1)
    {
        return &(lastElement -> value);
    }
    else
    {
        Element *currentElement = firstElement -> nextElement;

        for(unsigned i = 1; i < index; ++i) currentElement = currentElement -> nextElement;

        return &(currentElement -> value);
    }
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
