/**
*   \file   CircularList.tpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/03/2025
*/

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename T>
CircularList<T>::CircularList(): size(0), head(nullptr){}

template <typename T>
CircularList<T>::CircularList(const CircularList &li)
{
    *this = li;
}

template <typename T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T> &li)
{
    if (this == &li) return *this;
    
    Clear();
    
    Element *aux = li.head;
    
    Add(aux -> value);

    aux = aux -> nextElement;
    
    while(aux -> nextElement != head)
    {
        Add(aux -> value);
        aux = aux -> nextElement;
    }

    return *this;
}

// ----------------------
// ----- Destructor -----
// ----------------------
template <typename T>
CircularList<T>::~CircularList()
{
    Clear();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template <typename T>
void CircularList<T>::Add(T value)
{
    if(size == 0)
    {
        Element * aux = new Element (value);
        head = aux;
        head -> nextElement = aux;
        head -> prevElement = aux;
    }
    else
    {
        Element * aux = new Element (value, head -> prevElement, head);
        head -> prevElement -> nextElement = aux;
        head -> prevElement = aux;
        head = aux;
    }

    ++size;
}

template <typename T>
void CircularList<T>::RemoveHead()
{
    if (Empty()) throw "La lista está vacía";

    Element* deleteElement = head;

    if (size == 1)
    {
        head = nullptr;
    }
    else
    {
        head -> prevElement -> nextElement = head -> nextElement;
        head -> nextElement -> prevElement = head -> prevElement;
        head = head -> nextElement;
    }

    delete deleteElement;
    --size;
}

template <typename T>
T CircularList<T>::GetHead() const
{
    return head -> value;
}

template <typename T>
bool CircularList<T>::Contains(T value) const
{
    Element * aux = head;

    if(value == aux -> value ) 
    {
        return true;
    }
    
    do
    {
        aux = aux -> nextElement;
    }while(aux -> nextElement != head && aux->value != value);

    if(aux -> nextElement != head )
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template <typename T>
void CircularList<T>::MoveForward()
{
    head = head -> nextElement;
}

template <typename T>
void CircularList<T>::MoveBackward()
{
    head = head -> prevElement;
}

template <typename T>
unsigned CircularList<T>::Size()
{
    return size;
}

template <typename T>
bool CircularList<T>::Empty() const 
{
    return size == 0;
}

template <typename T>
void CircularList<T>::Clear()
{
    while(!Empty()) RemoveHead();
}

template <typename T>
void CircularList<T>::Print() const
{
    if(Empty()) throw "Lista vac\241a";

    Element *aux = head;

    cout << "[ ";
    for(unsigned i = 0; i < size; ++i)
    {
        std::cout << aux -> value << ", ";
        aux = aux -> nextElement;
    }
    cout << "\b\b ]";
}

template <typename T>
void CircularList<T>::PrintReverse() const
{
    if(Empty()) throw "Lista vac\241a";

    Element *aux = head -> prevElement;

    cout << "[ ";
    for(unsigned i = 0; i < size; ++i)
    {
        std::cout << aux -> value << ", ";
        aux = aux -> prevElement;
    }
    cout << "\b\b ]";
}
