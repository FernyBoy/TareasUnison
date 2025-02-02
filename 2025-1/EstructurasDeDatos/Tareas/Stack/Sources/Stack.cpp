#include "../Headers/Stack.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// template <typename T>

// --------------------------------
// Constructores
// --------------------------------
Stack::Stack() : size(0)
{

}

Stack::Stack(int s) : size(s) 
{
    
}

Stack::Stack(const Stack &s)
{

}

Stack & Stack::operator=(const Stack &s)
{

}

// --------------------------------
// Destructor
// --------------------------------
Stack::~Stack()
{

}


// --------------------------------------------------------------------


// --------------------------------
// Metodos publicos
// --------------------------------
void Stack::Push(int val)
{

}

void Stack::Pop()
{

}

int Stack::Top()
{

}

bool Stack::IsEmpty()
{

}

void Stack::ClearStack()
{

}

int Stack::UsedCapacity()
{

}

int Stack::Capacity()
{

}

void Stack::PrintElements()
{

}


// --------------------------------------------------------------------


// --------------------------------
// Metodos privados
// --------------------------------
bool Stack::IsFull()
{

}

Stack Stack::ResizeStack()
{

}


// --------------------------------------------------------------------


// --------------------------------
// Metodos externos
// --------------------------------
std::ostream & operator<<(std::ostream &output, const Stack &s)
{

}

std::istream & operator>>(std::istream &input, Stack &s)
{

}
