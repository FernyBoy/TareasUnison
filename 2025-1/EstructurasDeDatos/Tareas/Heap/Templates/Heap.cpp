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
Heap<Type>::Heap() {}

template <typename Type>
Heap<Type>::Heap(const Heap &h)
{
    _capacity = h._capacity;
    _size = h._size;

    for(int i = 0; i < _size; ++i)
    {
        _elements[i] = h._elements[i];
    }
}

template <typename Type>
Heap<Type> & Heap<Type>::operator=(const Heap<Type> &h)
{
    if(this == &h) return *this;

    delete[] _elements;

    _capacity = h._capacity;
    _size = h._size;
    if(_size > 0) _elements = new Type[_capacity];

    for(int i = 0; i < _size; ++i)
    {
        _elements[i] = h._elements[i];
    }

    return *this;
}

// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
Heap<Type>::~Heap()
{
    delete [] _elements;
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
    if(_size + 1 == (int)_capacity) Resize();

    _elements[_size + 1] = value;

    MoveUp(_size + 1);

    ++_size;
}

template <typename Type>
void Heap<Type>::Remove()
{
    if(_size == -1) return;
    else if(_size == 0) 
    {
        _size = -1;
        return;
    }
    else
    {
        swap(_elements[_size], _elements[0]);
        --_size;
        MoveDown(0);
    }
}

template <typename Type>
void Heap<Type>::Clear()
{
    delete[] _elements;
    _capacity = 0;
    _size = -1;
}

// ---------------------------------
// ----- Funcines de obtención -----
// ---------------------------------
template <typename Type>
Type Heap<Type>::Top()
{
    if(_size == -1)
    {
        #ifdef _WIN32
            throw "\265bol vac\241o";  // Comando para Windows
        #else
            throw "Árbol vacío";  // Comando para Linux/macOS
        #endif
    }

    return _elements[0];
}

template <typename Type>
bool Heap<Type>::Empty()
{
    return _size == -1;
}

template <typename Type>
unsigned Heap<Type>::Size() const
{
    return (unsigned)(_size + 1);
}

template <typename Type>
unsigned Heap<Type>::MaxCapacity() const
{
    return _capacity;
}


// ---------------------------------
// ----- Funcines de impresión -----
// ---------------------------------
template <typename Type>
void Heap<Type>::Print() const
{
    if(_size == -1) return;
    
    cout << _elements[0] << endl;
    #ifdef _WIN32
        PrintTreeWindows(0, ""); // Comando para Windows
    #else
        PrintTreeLinux(0, "");  // Comando para Linux/macOS
    #endif
    cout << endl;

    cout << "\n[ ";
    for(int i = 0; i <= _size; ++i)
    {
        cout << _elements[i] << ", ";
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
void Heap<Type>::PrintTreeLinux(unsigned parentIndex, const string& prefix) const
{
    bool hasLeft = ((int)(parentIndex * 2 + 1) <= _size);
    bool hasRight = ((int)(parentIndex * 2 + 2) <= _size);

    if (!hasLeft && !hasRight) return;

    cout << prefix;
    cout << ((hasLeft  && hasRight) ? "├── " : "");
    cout << ((!hasLeft && hasRight) ? "└── " : "");

    if(hasRight)
    {
        bool printStrand = (hasLeft && hasRight && ((int)((parentIndex * 2 + 2) * 2 + 2) <= _size || (int)((parentIndex * 2 + 2) * 2 + 1) <= _size));
        string newPrefix = prefix + (printStrand ? "│   " : "    ");
        cout << _elements[parentIndex * 2 + 2] << endl;
        PrintTreeLinux((parentIndex * 2 + 2), newPrefix);
    }

    if(hasLeft)
    {
        cout << (hasRight ? prefix : "") << "└── " << _elements[parentIndex * 2 + 1] << endl;
        PrintTreeLinux((parentIndex * 2 + 1), prefix + "    ");
    }
}

template <typename Type>
void Heap<Type>::PrintTreeWindows(unsigned parentIndex, const string& prefix) const
{
    bool hasLeft = ((int)(parentIndex * 2 + 1) <= _size);
    bool hasRight = ((int)(parentIndex * 2 + 2) <= _size);
    
    if (!hasLeft && !hasRight) return;

    cout << prefix;
    cout << ((hasLeft  && hasRight) ? string(1, (char)195) + string(2, (char)196) + " " : "");
    cout << ((!hasLeft && hasRight) ? string(1, (char)192) + string(2, (char)196) + " " : "");

    if(hasRight)
    {
        // bool printStrand = (hasLeft && hasRight && (parentNode -> right -> right != nullptr || parentNode -> right -> left != nullptr));
        bool printStrand = (hasLeft && hasRight && ((int)((parentIndex * 2 + 2) * 2 + 2) <= _size || (int)((parentIndex * 2 + 2) * 2 + 1) <= _size));
        string newPrefix = prefix + (printStrand ? string(1, (char)179) + "   " : "    ");
        cout << _elements[parentIndex * 2 + 2] << endl;
        PrintTreeLinux((parentIndex * 2 + 2), newPrefix);
    }

    if(hasLeft)
    {
        cout << (hasRight ? prefix : "") << string(1, (char)192) + string(2, (char)196) + " " << _elements[parentIndex * 2 + 1] << endl;
        PrintTreeLinux((parentIndex * 2 + 1), prefix + "    ");
    }
}

template <typename Type>
void Heap<Type>::Resize()
{
    if (_capacity == 0) 
    {
        _capacity = 1;
        _elements = new Type[_capacity];
        return;
    }

    unsigned newSize = _capacity * 2;
    Type* newElements = new Type[newSize];

    for (int i = 0; i <= _size; ++i)
    {
        newElements[i] = _elements[i];
    }

    delete[] _elements; // Liberamos la memoria vieja

    _elements = newElements;
    _capacity = newSize;
}

template <typename Type>
void Heap<Type>::MoveUp(unsigned currentIndex)
{
    while (currentIndex > 0)
    {
        unsigned parentIndex = (currentIndex - 1) / 2;

        if (_elements[currentIndex] > _elements[parentIndex])
        {
            swap(_elements[currentIndex], _elements[parentIndex]);
            currentIndex = parentIndex;
        }
        else break;
    }
}

template <typename Type>
void Heap<Type>::MoveDown(unsigned currentIndex)
{
    while((int)currentIndex < _size)
    {
        unsigned leftIndex = currentIndex * 2 + 1;
        unsigned rightIndex = currentIndex * 2 + 2;
        unsigned smallest = currentIndex;

        if ((int)leftIndex < _size && _elements[leftIndex] > _elements[smallest])
        {
            smallest = leftIndex;
        }

        if ((int)rightIndex < _size && _elements[rightIndex] > _elements[smallest])
        {
            smallest = rightIndex;
        }

        if (smallest == currentIndex) break;

        swap(_elements[currentIndex], _elements[smallest]);
        currentIndex = smallest;
    }
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
