/**
*   \file   Stack.tpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#include "../Headers/Stack.hpp" 

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// template <typename T>
// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
//Stack::Stack(unsigned s) : size(s)
template <typename Type>
Stack<Type>::Stack() : size(0), topElement(NULL) {  }

template <typename Type>
Stack<Type>::Stack(const Stack &s) : topElement(NULL)
{
    *this = s;
}

template<typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> &s)
{
    if(this == &s) return *this;

    Stack<Type> auxStack;
    
    Element *auxElement = new Element;
    auxElement -> 

    for(int i = 0; i < s.size; ++i)
    {
        auxStack.Push(auxElement);
    }
}
// ----------------------
// ----- Destructor -----
// ----------------------

template<typename Type>
Stack<Type>::~Stack()
{
    ClearStack();
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------

template<typename Type>
void Stack<Type>::Push(Type val)
{
    Element *newElement = new Element;
    newElement -> value = val;
    newElement -> nextElement = topElement;
    topElement = newElement;

    ++size;
}

template<typename Type>
void Stack<Type>::Pop()
{
    if(IsEmpty()) throw "Pila vac\241";

    Element *deleteElement = topElement;
    topElement = topElement -> nextElement;
    delete *deleteElement;

    --size;
}

template<typename Type>
Type Stack<Type>::Top() const
{
    if(IsEmpty()) throw "Pila vac\241";


}

template<typename Type>
bool Stack<Type>::IsEmpty()
{
    if(!size) return true;
}

template<typename Type>
void Stack<Type>::ClearStack()
{
    while(!IsEmpty()) Pop();
}

template<typename Type>
unsigned Stack<Type>::UsedCapacity() const
{
    return currentIndex + 1;
}

template<typename Type>
unsigned Stack<Type>::Capacity()
{
    return size;
}

template<typename Type>
void Stack<Type>::PrintElements()
{
    cout << "\n|\t\t|";

    for(unsigned i = 0; i < UsedCapacity(); ++i)
    {
        cout << "\n|\t" << elements[i] << "\t|";

        cout << "\n|\t\t|";
    }
}

template<typename Type>
Type Stack<Type>::operator[](int i) const
{
    if( i < 0 || i > currentIndex) throw "\326ndice inv\240lido";

    return elements[i];
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template<typename Type>
void Stack<Type>::ResizeStack()
{
    unsigned int newSize = size * 2;

    Type *newElements = new Type[newSize];

    for (unsigned int i = 0; i < UsedCapacity(); ++i)
    {
        newElements[i] = elements[i];
    }

    delete[] elements;

    elements = newElements;
    size = newSize;
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
template<typename Type>
void Stack<Type>::CreateStack()
{
    try{
        elements = new Type[size];
    }catch(std::bad_alloc &){
        throw "Problemas de asignaci\242n de memoria.";
    }
}

template<typename Type>
void Stack<Type>::ClearMemory()
{
    delete [] elements;
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
template<typename Type>
std::ostream & operator<<(std::ostream &output, Stack<Type> &s)
{
    for(unsigned i = 0; i < s.UsedCapacity(); ++i)
    {
        cout << s[i] << endl;
    } 
    
    return output;
}

/*
std::istream & operator>>(std::istream &input, Stack &s)
{

}
*/
