/**
 *  @file   MedievalQueue.hpp
 *  @author Angel Fernando Borquez Guerrero
 *  @date   21/02/2025
 *  @brief  Implementación de una cola medieval donde se gestionan nobles y plebeyos.
 *
 *  Esta clase representa una cola de espera en un castillo medieval donde los nobles tienen prioridad
 *  sobre los plebeyos. Permite encolar, desencolar y obtener información sobre los elementos de la cola.
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

/**
 *  @class MedievalQueue
 *  @brief Representa una cola medieval con prioridad para los nobles.
 *
 *  La cola mantiene un orden en el que los nobles pueden adelantarse en la fila,
 *  mientras que los plebeyos esperan su turno.
 */
class MedievalQueue
{
    public:
        /** @brief Constructor por defecto. Inicializa una cola vacía. */
        explicit MedievalQueue();

        /** @brief Destructor. Libera la memoria de los nodos de la lista. */
        ~MedievalQueue();

        // --- Métodos públicos ---

        /**
         * @brief Agrega una persona a la cola según su estatus.
         * 
         * Si es noble, se inserta al frente de la cola. Si es plebeyo, se inserta al final.
         * 
         * @param name Nombre de la persona.
         * @param status Estatus de la persona ("noble" o "plebeyo").
         */
        void EnqueueByStatus(string name, string status);

        /**
         * @brief Agrega una persona a la cola en orden de llegada.
         * 
         * Los nobles y plebeyos se agregan al final de la cola sin prioridad.
         * 
         * @param name Nombre de la persona.
         * @param status Estatus de la persona ("noble" o "plebeyo").
         */
        void EnqueueByArrive(string name, string status);

        /**
         * @brief Inserta una persona al inicio de la cola (prioridad alta).
         * 
         * @param name Nombre de la persona.
         * @param status Estatus de la persona.
         */
        void AddFirst(string name, string status);

        /**
         * @brief Inserta una persona al final de la cola.
         * 
         * @param name Nombre de la persona.
         * @param status Estatus de la persona.
         */
        void AddLast(string name, string status);

        /**
         * @brief Elimina a la persona en el frente de la cola.
         * 
         * Si la cola está vacía, lanza una excepción.
         * 
         * @throws std::runtime_error si la cola está vacía.
         */
        void Dequeue();

        /**
         * @brief Obtiene el primer elemento de la cola.
         * 
         * Si la cola está vacía, devuelve un vector con valores predeterminados.
         * 
         * @return Un vector con el nombre y estatus de la persona en el frente de la cola.
         */
        vector<string> GetFront() const;

        /**
         * @brief Obtiene el tamaño total de la cola.
         * @return Número de elementos en la cola.
         */
        unsigned QueueSize() const;

        /**
         * @brief Obtiene la cantidad de nobles en la cola.
         * @return Número de nobles en la cola.
         */
        unsigned NobleSize() const;

        /**
         * @brief Obtiene la cantidad de plebeyos en la cola.
         * @return Número de plebeyos en la cola.
         */
        unsigned VillagerSize() const;

        /**
         * @brief Verifica si la cola está vacía.
         * @return `true` si la cola está vacía, `false` en caso contrario.
         */
        bool IsEmpty() const;

        /**
         * @brief Elimina todos los elementos de la cola.
         * 
         * Libera la memoria de todos los nodos de la lista.
         */
        void ClearList();

        /**
         * @brief Imprime la lista de espera en la terminal.
         * 
         * Muestra a todas las personas en la cola junto con su estatus.
         */
        void PrintList();

    private:
        // --- Atributos ---

        unsigned size;       /**< Cantidad total de personas en la cola. */
        unsigned nobleNum;   /**< Número de nobles en la cola. */
        unsigned villagerNum; /**< Número de plebeyos en la cola. */

        vector<string> firstNamesList; /**< Lista de nombres posibles. */
        vector<string> lastNamesList;  /**< Lista de apellidos posibles. */

        /**
         * @struct Person
         * @brief Representa a una persona en la cola.
         *
         * Cada persona tiene un nombre, un estatus y un puntero al siguiente en la cola.
         */
        struct Person
        {
            string name;       /**< Nombre de la persona. */
            string status;     /**< Estatus de la persona (noble o plebeyo). */
            Person *nextPerson; /**< Puntero al siguiente en la cola. */
        };

        Person *frontPerson; /**< Puntero a la primera persona en la cola. */
        Person *rearPerson;  /**< Puntero a la última persona en la cola. */
};

#endif // MEDIEVALQUEUE_HPP_INCLUDED
