/**
*   \file   Heap.hpp
*   \brief  Declaración de la plantilla de clase Heap.
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   26/04/2025
*/

#ifndef HEAP_HPP_INCLUDED
#define HEAP_HPP_INCLUDED

#include <iostream>
#include <ostream>

// --- Uso de espacio de nombres
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::swap;

// --- Declaración de funciones de ordenamiento externas

/**
*   \brief  Función que determina si el primer elemento es menor o igual que el segundo.
*   \tparam T Tipo de dato a comparar.
*   \param a Primer elemento.
*   \param b Segundo elemento.
*   \return `true` si a <= b, `false` en caso contrario.
*/
template <typename T>
bool min(const T &a, const T &b);

/**
*   \brief  Función que determina si el primer elemento es mayor o igual que el segundo.
*   \tparam T Tipo de dato a comparar.
*   \param a Primer elemento.
*   \param b Segundo elemento.
*   \return `true` si a >= b, `false` en caso contrario.
*/
template <typename T>
bool max(const T &a, const T &b);

// --- Declaración de la plantilla de clase Heap

/**
*   \brief  Clase plantilla que implementa un montón (heap) mínimo o máximo.
*   \tparam Type Tipo de los elementos almacenados en el montón.
*   \tparam Order Puntero a función que define el criterio de ordenamiento (mínimo o máximo).
*/
template <typename Type, bool(*Order)(const Type &, const Type &) = min>
class Heap
{
    // --- Métodos externos

    /**
    *   \brief  Sobrecarga del operador de inserción para imprimir el Heap.
    *   \tparam T Tipo de los elementos del Heap.
    *   \param output Flujo de salida.
    *   \param h Heap a imprimir.
    *   \return Referencia al flujo de salida.
    */
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const Heap<T> &h);

    public:
        // --- Constructores

        /**
        *   \brief Constructor por defecto.
        */
        Heap();

        /**
        *   \brief Constructor de copias.
        *   \param h Heap a copiar.
        */
        Heap(const Heap &h);

        /**
        *   \brief Sobrecarga del operador de asignación.
        *   \param h Heap a asignar.
        *   \return Referencia al objeto actual.
        */
        Heap& operator=(const Heap &h);

        // --- Destructor

        /**
        *   \brief Destructor de la clase Heap.
        */
        ~Heap();

        // --- Métodos públicos

        // - Funciones de modificación

        /**
        *   \brief Inserta un nuevo elemento en el Heap.
        *   \param value Elemento a insertar.
        */
        void Insert(Type value);

        /**
        *   \brief Elimina el elemento en la raíz del Heap.
        */
        void Remove();

        /**
        *   \brief Elimina todos los elementos del Heap.
        */
        void Clear();

        // - Funciones de obtención

        /**
        *   \brief Obtiene el elemento en la raíz del Heap.
        *   \return Elemento en la raíz.
        */
        Type Top();

        /**
        *   \brief Verifica si el Heap está vacío.
        *   \return `true` si está vacío, `false` en caso contrario.
        */
        bool Empty();

        /**
        *   \brief Obtiene el número de elementos en el Heap.
        *   \return Cantidad de elementos.
        */
        unsigned Size() const;

        /**
        *   \brief Obtiene la capacidad actual del Heap.
        *   \return Capacidad total del arreglo.
        */
        unsigned Capacity() const;

        // - Funciones de impresión

        /**
        *   \brief Imprime los elementos del Heap.
        */
        void Print() const;

    private:
        // --- Atributos

        unsigned    _capacity;   ///< Capacidad total del arreglo de elementos.
        int         _size;       ///< Índice del último elemento en el Heap (-1 si está vacío).
        Type*       _elements;   ///< Puntero al arreglo dinámico de elementos.

        // --- Métodos privados

        /**
        *   \brief Imprime el Heap en formato árbol para Linux.
        *   \param parentIndex Índice del nodo actual.
        *   \param prefix Prefijo usado para mostrar la estructura del árbol.
        */
        void PrintTreeLinux(unsigned parentIndex, const string& prefix) const;

        /**
        *   \brief Imprime el Heap en formato árbol para Windows.
        *   \param parentIndex Índice del nodo actual.
        *   \param prefix Prefijo usado para mostrar la estructura del árbol.
        */
        void PrintTreeWindows(unsigned parentIndex, const string& prefix) const;

        /**
        *   \brief Duplica la capacidad del arreglo dinámico cuando es necesario.
        */
        void Resize();

        /**
        *   \brief Realiza el proceso de empujar hacia arriba en el Heap.
        *   \param currentIndex Índice actual a reposicionar.
        */
        void MoveUp(unsigned currentIndex);

        /**
        *   \brief Realiza el proceso de empujar hacia abajo en el Heap.
        *   \param currentIndex Índice actual a reposicionar.
        */
        void MoveDown(unsigned currentIndex);
};

#include "../Templates/Heap.tpp"

#endif // !HEAP_HPP_INCLUDED
