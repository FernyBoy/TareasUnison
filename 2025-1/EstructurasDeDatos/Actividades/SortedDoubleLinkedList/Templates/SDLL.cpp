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
    if(li.IsEmpty()) return *this;
    for(Element* aux = li.firstElement; aux != nullptr; aux = aux -> nextElement)
    {
        Add(aux -> value);
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

    if(li.IsEmpty()) return *this;
    for(Element* aux = li.firstElement; aux != nullptr; aux = aux -> nextElement)
    {
        Add(aux -> value);
    }

    return *this;
}

template <typename Type>
Type SDLL<Type>::operator[](unsigned int index) const
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
void SDLL<Type>::Add(Type val)
{
    Element *aux = new Element(val);

    if(size == 0)
    {
        firstElement = lastElement = aux;
    }
    else if(val < firstElement -> value)
    {
        aux -> nextElement = firstElement;
        firstElement -> prevElement = aux;
        firstElement = aux;
    }
    else if(val > lastElement -> value)
    {
        aux -> prevElement = lastElement;
        lastElement -> nextElement = aux;
        lastElement = aux;
    }
    else
    {
        for(Element* currentElement = firstElement; currentElement != nullptr; currentElement = currentElement -> nextElement)
        {
            if(val > currentElement -> value)
            {
                currentElement -> nextElement -> prevElement = aux;
                currentElement -> nextElement = aux;
                aux -> prevElement = currentElement;
            }
        }
    }

    ++size;
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

// --------------------------------
// --- Funciones de eliminación ---
// --------------------------------
template <typename Type>
void SDLL<Type>::Remove(Type val)
{
    if(IsEmpty()) throw "Lista vac\241a";
    
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
void SDLL<Type>::Clear()
{
    Element* aux = firstElement;

    while(aux != nullptr)
    {
        Element* deleteElement = aux;
        aux = aux -> nextElement;
        delete deleteElement;
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
        auxList.Add(firstElement -> value);
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
            auxList.Add(aux -> value);
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
        auxList.Add(firstElement -> value);
    }
    else if(startIndex == size - 1 && endIndex == size - 1)
    {
        auxList.Add(lastElement -> value);
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
            auxList.Add(aux -> value);
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
