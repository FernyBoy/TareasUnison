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
Stack::Stack(unsigned s) : size(s)
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

    for(unsigned i = 0; i < size; ++i)
    {
        elements[i] = s.elements[i];
    }

    return *this;
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
    if(IsFull()) ResizeStack();

    ++currentIndex;
    elements[currentIndex] = val;
}

void Stack::Pop()
{
    --currentIndex;
}

int Stack::Top()
{
    if(!UsedCapacity()) throw "No hay elementos en la pila";

    return elements[currentIndex];
}

bool Stack::IsEmpty()
{
    if(!size) throw "La pila es de tamaño 0";

    return currentIndex == -1;
}

void Stack::ClearStack()
{
    currentIndex = -1;
    
    ClearMemory();
    CreateStack();
}

unsigned Stack::UsedCapacity()
{
    return currentIndex + 1;
}

unsigned Stack::Capacity()
{
    return size;
}

void Stack::PrintElements()
{
    cout << "\n|\t\t|";

    for(unsigned i = 0; i < UsedCapacity(); ++i)
    {
        cout << "\n|\t" << elements[i] << "\t|";

        cout << "\n|\t\t|";
    }
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

void Stack::ResizeStack()
{
    size *= 2;

    Stack newStack(size);

    for(unsigned i = 0; i < UsedCapacity(); ++i)
    {
        newStack.elements[i] = elements[i];
    }

    *this = newStack;
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
//---------------------------------------------

std::ostream & operator<<(std::ostream &output, Stack &s)
{
    for(unsigned i = 0; i < s.UsedCapacity(); ++i)
    {
        cout << s.elements[i] << endl;
    } 
    
    return output;
}

/*
std::istream & operator>>(std::istream &input, Stack &s)
{

}
*/
