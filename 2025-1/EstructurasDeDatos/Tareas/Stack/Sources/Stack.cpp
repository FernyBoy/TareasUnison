#include "../Headers/Stack.hpp"
#include <new>

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
Stack::Stack(unsigned s)
// template<typename Type, typename Capacity>
// Stack::Stack<Type, Capacity>() : size(Capacity)
{
    CreateStack();
}

Stack::Stack(const Stack &s)
{
    *this = s;
}

Stack & Stack::operator=(const Stack &s)
{
    ClearMemory();

    size = s.size;
    CreateStack();

    for(int i = 0; i < size; ++i)
    {
        elements[i] = s.elements[i];
    }
}
// ----------------------
// ----- Destructor -----
// ----------------------
Stack::~Stack()
{
    ClearMemory();
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
void Stack::Push(int val)
{

}

void Stack::Pop()
{
    --currentIndex;
}

int Stack::Top()
{
    return elements[currentIndex];
}

bool Stack::IsEmpty()
{
    if(!size) throw "La pila es de tamaño 0";

    return currentIndex == -1;
}

void Stack::ClearStack()
{
    ClearMemory();
    CreateStack();
}

int Stack::UsedCapacity()
{
    return currentIndex + 1;
}

unsigned Stack::Capacity()
{
    return size;
}

void Stack::PrintElements()
{
    for(int i = 0; i < currentIndex; ++i) cout << "\n|\t" << elements[i] << "\t |";
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
bool Stack::IsFull()
{
    return size == UsedCapacity();
}

Stack Stack::ResizeStack()
{

}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
void Stack::CreateStack()
{
    try{
        elements = new int[size];

        for(int i = 0; i < size; ++i)
        {
            elements[i] = NULL;
        }
    }catch(std::bad_alloc &){
        throw "Problemas de asignación de memoria.";
    }
}

void Stack::ClearMemory()
{
    delete [] elements;
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
std::ostream & operator<<(std::ostream &output, const Stack &s)
{

}

std::istream & operator>>(std::istream &input, Stack &s)
{

}
