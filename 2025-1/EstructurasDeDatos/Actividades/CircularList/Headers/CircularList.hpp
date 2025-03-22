/**
 *   @file   CircularList.hpp
 *   @author Angel Fernando Borquez Guerrero
 *   @date   21/03/2025
 *   @brief  Implementación de una lista enlazada circular genérica.
 */

#ifndef CIRCULARLIST_HPP_INCLUDED
#define CIRCULARLIST_HPP_INCLUDED

#include <iostream>

using std::cout;

/**
 * @class CircularList
 * @brief Clase que representa una lista enlazada circular genérica.
 * @tparam T Tipo de dato almacenado en la lista.
 */
template<typename T>
class CircularList
{
    public:
        /**
         * @brief Constructor por defecto. Crea una lista vacía.
         */
        CircularList();

        /**
         * @brief Constructor de copia.
         * @param li Otra lista circular de la cual se copiarán los elementos.
         */
        CircularList(const CircularList &li);

        /**
         * @brief Sobrecarga del operador de asignación.
         * @param li Otra lista circular que se asignará a esta.
         * @return Referencia a la lista asignada.
         */
        CircularList<T>& operator=(const CircularList<T> &li);

        /**
         * @brief Destructor. Libera la memoria utilizada por la lista.
         */
        ~CircularList();

        /**
         * @brief Agrega un nuevo elemento al final de la lista.
         * @param val Valor a insertar en la lista.
         */
        void Add(T val);

        /**
         * @brief Elimina el primer elemento de la lista.
         * @throw std::runtime_error si la lista está vacía.
         */
        void RemoveHead();

        /**
         * @brief Obtiene el valor del primer elemento de la lista.
         * @return Valor almacenado en el primer nodo.
         */
        T GetHead() const;

        /**
         * @brief Verifica si un valor se encuentra en la lista.
         * @param val Valor a buscar.
         * @return true si el valor está en la lista, false en caso contrario.
         */
        bool Contains(T val) const;

        /**
         * @brief Mueve la cabeza de la lista una posición hacia adelante.
         */
        void MoveForward();

        /**
         * @brief Mueve la cabeza de la lista una posición hacia atrás.
         */
        void MoveBackward();

        /**
         * @brief Devuelve el número de elementos en la lista.
         * @return Cantidad de elementos en la lista.
         */
        unsigned Size();

        /**
         * @brief Verifica si la lista está vacía.
         * @return true si la lista está vacía, false en caso contrario.
         */
        bool Empty() const;

        /**
         * @brief Elimina todos los elementos de la lista.
         */
        void Clear();

        /**
         * @brief Imprime la lista en orden directo.
         */
        void Print() const;

        /**
         * @brief Imprime la lista en orden inverso.
         */
        void PrintReverse() const;

    private:
        unsigned size; /**< Cantidad de elementos en la lista. */

        /**
         * @struct Element
         * @brief Representa un nodo de la lista enlazada circular.
         */
        struct Element
        {
            T value;             /**< Valor almacenado en el nodo. */
            Element *prevElement; /**< Puntero al nodo anterior. */
            Element *nextElement; /**< Puntero al nodo siguiente. */
            
            /**
             * @brief Constructor del nodo.
             * @param val Valor a almacenar en el nodo.
             * @param next Puntero al siguiente nodo (por defecto nullptr).
             * @param prev Puntero al nodo previo (por defecto nullptr).
             */
            Element(T val, Element *prev = nullptr, Element *next = nullptr)
            {
                value = val;
                prevElement = prev;
                nextElement = next;
            }
        };
        
        Element *head; /**< Puntero al nodo cabeza de la lista. */
};

#include "../Templates/CircularList.tpp"

#endif // CIRCULARLIST_HPP_INCLUDED
