/**
*   \file   OrderedList.tpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   12/03/2025
*/

#include "../Headers/OrderedList.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
OrderedList<Type>::OrderedList() {}


template <typename Type>
OrderedList<Type>::OrderedList(const OrderedList &li)
{   
    list.Clone(li);
}

template <typename Type>
OrderedList<Type> & OrderedList<Type>::operator=(const OrderedList<Type> &li)
{
    list.Clone(li);
}
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
OrderedList<Type>::~OrderedList()
{
    list.Clear();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template <typename Type>
void OrderedList<Type>::Add(Type val)
{   
    if(list.IsEmpty()) list.AddLast(val);
    else if(val < list.GetFirst()) list.AddFirst(val);
    else if(val > list.GetLast()) list.AddLast(val);
    else
    {
        for(unsigned i = 1; i < list.Size(); ++i)
        {
            if(val < list.GetAt(i))
            {
                list.AddAt(val, i);
            }
        }
    }
}

template <typename Type>
void OrderedList<Type>::Remove(Type val)
{
    list.RemoveElement(val);
}

template <typename Type>
void OrderedList<Type>::MixLists(const DoubleLinkedList<Type> &li_1, const DoubleLinkedList<Type> &li_2)
{
    for(unsigned i = 0; i < li_1.Size(); ++i)
    {
        Add(li_1.GetAt(i));
    }

    for(unsigned i = 0; i < li_2.Size(); ++i)
    {
        Add(li_2.GetAt(i));
    }   
}

template <typename Type>
bool OrderedList<Type>::Contains(Type val) const
{
    return list.Contains(val);
}

template <typename Type>
void OrderedList<Type>::Clear()
{
    list.Clear();
}

template <typename Type>
bool OrderedList<Type>::Empty() const
{
    return list.IsEmpty();
}

template <typename Type>
unsigned OrderedList<Type>::Size() const
{
    return list.Size();
}

template <typename Type>
void OrderedList<Type>::Print()
{
    list.Print();
}

template <typename Type>
void OrderedList<Type>::PrintReverse()
{
    list.PrintReverse();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
template <typename Type>
std::ostream & operator<<(std::ostream &output, OrderedList<Type> &li)
{
    li.Print();   

    return output;
}


template <typename Type>
std::istream & operator>>(std::istream &input, OrderedList<Type> &li)
{
    li.Add(input);

    return input;
}
