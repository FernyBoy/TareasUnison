/**
*   \file   SDLL.tpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   04/03/2025
*/

#include "../Headers/SDLL.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------

template <typename Type>
SDLL<Type>::SDLL() : size(0), firstElement(nullptr), lastElement(nullptr) {}

template <typename Type>
SDLL<Type>::SDLL(const SDLL &li)
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
SDLL<Type>::~SDLL()
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
SDLL<Type> & SDLL<Type>::operator=(const SDLL<Type> &li)
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
Type SDLL<Type>::operator=(Type val)
{
    return val;
}

template <typename Type>
Type SDLL<Type>::operator[](unsigned int index) const
{
    return GetAt(index);
}

template <typename Type>
Type* SDLL<Type>::operator[](unsigned int index)
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
void SDLL<Type>::Add(Type val)
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


// --------------------------------
// --- Funciones de eliminación ---
// --------------------------------
template <typename Type>
void SDLL<Type>::RemoveFirst()
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
void SDLL<Type>::RemoveLast()
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
void SDLL<Type>::RemoveFrom(unsigned index)
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
void SDLL<Type>::RemoveRange(unsigned startIndex, unsigned endIndex)
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
void SDLL<Type>::RemoveElement(Type val)
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
void SDLL<Type>::RemoveDuplicates()
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
void SDLL<Type>::RemoveAllElements(Type val)
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
void SDLL<Type>::RemoveMatching(const SDLL<Type> &li)
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
void SDLL<Type>::RemoveIf(fun condition)
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
void SDLL<Type>::Clear()
{
    while(!IsEmpty()) RemoveFirst();
}


// ---------------------------------
// --- Funciones de modificación ---
// ---------------------------------
template <typename Type>
void SDLL<Type>::SetAt(unsigned index, Type val)
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
void SDLL<Type>::Clone(const SDLL<Type> &li)
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
void SDLL<Type>::Swap(SDLL<Type> &li)
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
void SDLL<Type>::TransferAll(SDLL<Type> &li)
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
void SDLL<Type>::TransferFrom(unsigned index, SDLL<Type> &li)
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
void SDLL<Type>::TransferRange(unsigned startIndex, unsigned endIndex, SDLL<Type> &li)
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
SDLL<Type> SDLL<Type>::Union(const SDLL<Type> &li)
{
    SDLL<Type> newList(*this);
    newList.Concat(li);

    return newList;
}

template <typename Type>
SDLL<Type> SDLL<Type>::Intersection(const SDLL<Type> &li)
{
    SDLL<Type> listIntersection;
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
SDLL<Type> SDLL<Type>::Difference(const SDLL<Type> &li)
{
    SDLL<Type> differenceList = *this;
    differenceList.RemoveMatching(li);

    return differenceList;
}
/*
template <typename Type>
SDLL<Type> SDLL<Type>::SymmetricDifference(const SDLL<Type> &li)
{

}
*/

// ---------------------------------
// --- Funciones de ordenamiento ---
// ---------------------------------
template <typename Type>
void SDLL<Type>::Reverse()
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
void SDLL<Type>::SortAscending()
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
void SDLL<Type>::SortDescending()
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
Type SDLL<Type>::GetFirst() const
{
    if(IsEmpty()) throw "Lista vaci\241a";

    return firstElement -> value;
}


template <typename Type>
Type SDLL<Type>::GetLast() const
{
    if(IsEmpty()) throw "Lista vaci\241a";

    return lastElement -> value;
}

template <typename Type>
Type SDLL<Type>::GetAt(unsigned index) const
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
SDLL<Type> SDLL<Type>::GetFrom(unsigned index) const
{
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(index)) throw "\326ndice inv\240lido";

    SDLL<Type> auxList;

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
SDLL<Type> SDLL<Type>::GetRange(unsigned startIndex, unsigned endIndex) const
{
    if(IsEmpty()) throw "Lista vac\241a";
    if(!IsValidIndex(startIndex)) throw "\326ndice de inicio inv\240lido";
    if(!IsValidIndex(endIndex)) throw "\326ndice final inv\240lido";
    if(startIndex > endIndex) throw "\326ndices inv\240lidos";

    SDLL<Type> auxList;

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
bool SDLL<Type>::Contains(Type val) const
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
unsigned SDLL<Type>::IndexOf(Type val) const
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
unsigned SDLL<Type>::Size() const
{
    return size;
}

template <typename Type>
bool SDLL<Type>::IsEmpty() const
{
    return !size;
}


// ------------------------------
// --- Funciones de impresión ---
// ------------------------------
template <typename Type>
void SDLL<Type>::Print()
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
void SDLL<Type>::PrintReverse()
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
bool SDLL<Type>::IsValidIndex(unsigned index) const
{
    return index < size;
}

template <typename Type>
Type* SDLL<Type>::GetPointer(unsigned index)
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
std::ostream & operator<<(std::ostream &output, SDLL<Type> &li)
{
    li.Print();

    return output;
}

template <typename Type>
std::istream & operator>>(std::istream &input, SDLL<Type> &li)
{
    Type val;
    input >> val;

    li.AddLast(val);

    return input;
}
