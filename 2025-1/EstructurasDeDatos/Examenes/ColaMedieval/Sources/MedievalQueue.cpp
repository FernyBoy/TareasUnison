/**
*   \file   MedievalQueue.cpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/02/2025
*/

#include "../Headers/MedievalQueue.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
MedievalQueue::MedievalQueue() : size(0), nobleNum(0), villagerNum(0) {}
// ----------------------
// ----- Destructor -----
// ----------------------
// 
MedievalQueue::~MedievalQueue()
{
    ClearList();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
// --- Funciones de agregación
void MedievalQueue::Enqueue(string name, bool noble)
{
    noble ? AddFirst(name, noble) : AddLast(name, noble);
}

void MedievalQueue::AddFirst(string name, bool noble)
{
    Person *aux = new Person;
    aux -> name = name;
    aux -> noble = noble;

    if(IsEmpty())
    {
        frontPerson = aux;
        rearPerson = aux;
    }
    else
    {
        aux -> nextPerson = frontPerson;
        frontPerson = aux;
    }
    
    ++nobleNum;
    ++size;
}

void MedievalQueue::AddLast(string name, bool noble)
{
    Person *aux = new Person;
    aux -> name = name;
    aux -> noble = noble;

    if(IsEmpty())
    {
        frontPerson = aux;
        rearPerson = aux;
    }
    else
    {
        rearPerson -> nextPerson = aux;
        rearPerson = aux;
    }
    
    ++villagerNum;
    ++size;
}

// --- Funciones de eliminación
void MedievalQueue::Dequeue()
{
    if(IsEmpty()) throw "Lista vac\241a";
    
    frontPerson -> noble ? --nobleNum : --villagerNum;

    Person *deletePerson = frontPerson;
    frontPerson = frontPerson -> nextPerson;
    delete deletePerson;

    --size;
}

// --- Funciones de obtención
string MedievalQueue::GetFront() const
{
    return frontPerson -> name;
}

unsigned MedievalQueue::QueueSize() const
{
    return size;
}

unsigned MedievalQueue::NobleSize() const
{
    return nobleNum;
}

unsigned MedievalQueue::VillagerSize() const
{
    return villagerNum;
}

bool MedievalQueue::IsEmpty() const

{
    return !size;
}

// --- Otras funciones
void MedievalQueue::ClearList()
{
    while(!IsEmpty()) Dequeue();
}

void MedievalQueue::PrintList()
{
    if(IsEmpty()) throw "Lista vac\241a";

    Person *aux = frontPerson;

    cout << "[ ";
    for(unsigned i = 0; i < size; ++i)
    {
        cout << aux -> name << ", ";
        aux = aux -> nextPerson;
    }
    cout << "\b\b ]";
}



// ----------------------------------------------------------------------------------------
