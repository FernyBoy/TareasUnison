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
void MedievalQueue::Enqueue(string name, string status)
{
    status == "noble" ? AddFirst(name, status) : AddLast(name, status);
}

void MedievalQueue::AddFirst(string name, string status)
{
    Person *aux = new Person;
    aux -> name = name;
    aux -> status = status;

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

void MedievalQueue::AddLast(string name, string status)
{
    Person *aux = new Person;
    aux -> name = name;
    aux -> status = status;

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
    
    frontPerson -> status == "noble" ? --nobleNum : --villagerNum;

    Person *deletePerson = frontPerson;
    frontPerson = frontPerson -> nextPerson;
    delete deletePerson;

    --size;
}

// --- Funciones de obtención
vector<string> MedievalQueue::GetFront() const
{
    vector<string> person(2);

    if(IsEmpty())
    {
        person[0] = "Sin nombre";
        person[1] = "Desconocido";
    }

    person[0] = frontPerson -> name;
    person[1] = frontPerson -> status;

    return person;
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
    if(IsEmpty())
    {
        cout << "\n|";
        return;
    }

    Person *aux = frontPerson;

    for(unsigned i = 0; i < size; ++i)
    {
        cout << "\n|\t"<< aux -> name << " - " << aux -> status;
        aux = aux -> nextPerson;
    }
}



// ----------------------------------------------------------------------------------------
