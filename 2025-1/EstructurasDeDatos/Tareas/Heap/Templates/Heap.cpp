/**
*   \file   Heap.tpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   26/04/2025
*/



#include "../Headers/Heap.hpp"



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
Heap<Type>::Heap() 
{

}


template <typename Type>
Heap<Type>::Heap(const Heap &h)
{   

}

template <typename Type>
Heap<Type> & Heap<Type>::operator=(const Heap<Type> &h)
{

}
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
Heap<Type>::~Heap()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
// -------------------------------------
// ----- Funciones de modificación -----
// -------------------------------------
template <typename Type>
void Heap<Type>::Insert(Type value)
{

}

template <typename Type>
void Heap<Type>::Remove()
{

}

template <typename Type>
void Heap<Type>::Clear()
{

}

// ---------------------------------
// ----- Funcines de obtención -----
// ---------------------------------
template <typename Type>
Type Heap<Type>::Top()
{

}

template <typename Type>
bool Heap<Type>::Empty()
{

}

template <typename Type>
unsigned Heap<Type>::Size() const
{

}

template <typename Type>
unsigned Heap<Type>::MaxCapacity() const
{

}


// ---------------------------------
// ----- Funcines de impresión -----
// ---------------------------------
template <typename Type>
void Heap<Type>::Print() const
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template <typename Type>
void Heap<Type>::Resize()
{

}

template <typename Type>
void Heap<Type>::MoveUp()
{

}

template <typename Type>
void Heap<Type>::MoveDown()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
/* 
template <typename Type>
std::ostream & operator<<(std::ostream &output, Heap<Type> &h)
{
    

    return output;
}


template <typename Type>
std::istream & operator>>(std::istream &input, Heap<Type> &h)
{
    

    return input;
}
*/
