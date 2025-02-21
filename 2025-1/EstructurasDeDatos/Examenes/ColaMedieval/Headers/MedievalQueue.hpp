/**
*   \file   MedievalQueue.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/02/2025
*/

#ifndef MEDIEVALQUEUE_HPP_INCLUDED
#define MEDIEVALQUEUE_HPP_INCLUDED

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class MedievalQueue
{
    public:
        // --- Constructores
        explicit MedievalQueue();
        // - Destructor
        ~MedievalQueue();

        // --- Métodos públicos
        // - Funciones de agregación
        void        Enqueue(string name, string status);
        void        AddFirst(string name, string status);
        void        AddLast(string name, string status);
        // - Funciones de eliminación
        void        Dequeue();
        // - Funciones de obtención
        vector<string>  GetFront()      const;
        unsigned        QueueSize()     const;
        unsigned        NobleSize()     const;
        unsigned        VillagerSize()  const;
        bool            IsEmpty()       const;
        // - Otras funciones
        void        ClearList();
        void        PrintList();


    private:
        // --- Atributos
        unsigned    size;
        unsigned    nobleNum;
        unsigned    villagerNum;

        vector<string>  firstNamesList;
        vector<string>  lastNamesList;

        struct Person
        {
            string  name;
            string  status;
            Person  *nextPerson;
        };

        Person  *frontPerson;
        Person  *rearPerson;
};
#endif // !EXPRESSION_HPP_INCLUDED
