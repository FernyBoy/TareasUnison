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
template <typename Type, unsigned int Cap>
Stack<Type, Cap>::Stack()
{
    size = Cap;
    CreateStack();
}

template <typename Type, unsigned int Cap>
Stack<Type, Cap>::Stack(const Stack &s) : size(s.size), currentIndex(s.currentIndex)
{
    CreateStack();

    for(unsigned i = 0; i < UsedCapacity(); ++i)
    {
        elements[i] = s.elements[i];
    }
}

template<typename Type, unsigned int Cap>
Stack<Type, Cap> & Stack<Type, Cap>::operator=(const Stack<Type, Cap> &s)
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

template<typename Type, unsigned int Cap>
Stack<Type, Cap>::~Stack()
{
    ClearMemory();
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------

template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::Push(Type val)
{
    if(IsFull()) ResizeStack();

    ++currentIndex;
    elements[currentIndex] = val;
}

template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::Pop()
{
    --currentIndex;
}

template<typename Type, unsigned int Cap>
Type Stack<Type, Cap>::Top() const
{
    if(!UsedCapacity()) throw "La pila está vacía. No se puede acceder al tope.";

    return elements[currentIndex];
}

template<typename Type, unsigned int Cap>
bool Stack<Type, Cap>::IsEmpty()
{
    if(!size) throw "La pila es de tamaño 0";

    return currentIndex == -1;
}

template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::ClearStack()
{
    currentIndex = -1;
    
    ClearMemory();
    CreateStack();
}

template<typename Type, unsigned int Cap>
unsigned Stack<Type, Cap>::UsedCapacity() const
{
    return currentIndex + 1;
}

template<typename Type, unsigned int Cap>
unsigned Stack<Type, Cap>::Capacity()
{
    return size;
}

template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::PrintElements()
{
    cout << "\n|\t\t|";

    for(unsigned i = 0; i < UsedCapacity(); ++i)
    {
        cout << "\n|\t" << elements[i] << "\t|";

        cout << "\n|\t\t|";
    }
}

template<typename Type, unsigned int Cap>
Type Stack<Type, Cap>::operator[](int i) const
{
    if( i < 0 || i > currentIndex) throw "Índice inválido";

    return elements[i];
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template<typename Type, unsigned int Cap>
bool Stack<Type, Cap>::IsFull()
{
    return size == UsedCapacity();
}

template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::ResizeStack()
{
    /*
    size *= 2;

    Stack<Type, size> newStack;

    for(unsigned i = 0; i < UsedCapacity(); ++i)
    {
        newStack.elements[i] = elements[i];
    }

    *this = newStack;
    */

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
template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::CreateStack()
{
    try{
        elements = new Type[size];
    }catch(std::bad_alloc &){
        throw "Problemas de asignación de memoria.";
    }
}

template<typename Type, unsigned int Cap>
void Stack<Type, Cap>::ClearMemory()
{
    delete [] elements;
}



// --------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
template<typename Type, unsigned int Cap>
std::ostream & operator<<(std::ostream &output, Stack<Type, Cap> &s)
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
