/**
*   \file   OrderedList.hpp
*   \brief  Definición de la clase plantilla OrderedList, que representa una lista doblemente enlazada ordenada.
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   12/03/2025
*/

#ifndef ORDEREDLIST_HPP_INCLUDED
#define ORDEREDLIST_HPP_INCLUDED

#include <iostream>
#include <ostream>

#include "DoubleLinkedList.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 *  \class OrderedList
 *  \brief Clase plantilla que implementa una lista doblemente enlazada ordenada.
 *  
 *  La lista mantiene sus elementos en orden ascendente al momento de insertarlos.
 *  Se basa en una lista doblemente enlazada (`DoubleLinkedList<Type>`).
 *  
 *  \tparam Type Tipo de dato almacenado en la lista ordenada.
 */
template <typename Type>
class OrderedList
{
    // --- Métodos externos
    /**
     * \brief Sobrecarga del operador de salida para imprimir la lista ordenada.
     * \param output Flujo de salida donde se imprimirá la lista.
     * \param li Lista ordenada a imprimir.
     * \return Referencia al flujo de salida.
     */
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const OrderedList<T> &li);

    /**
     * \brief Sobrecarga del operador de entrada para leer valores en la lista ordenada.
     * \param input Flujo de entrada desde el cual se leerán los valores.
     * \param li Lista ordenada en la que se insertarán los valores leídos.
     * \return Referencia al flujo de entrada.
     */
    template <typename T>
    friend std::istream& operator>>(std::istream& input, OrderedList<T> &li);

public:
    // --- Constructores
    /**
     * \brief Constructor por defecto. Inicializa una lista ordenada vacía.
     */
    explicit OrderedList();

    /**
     * \brief Constructor de copia. Crea una nueva lista ordenada a partir de otra existente.
     * \param li Lista ordenada a copiar.
     */
    OrderedList(const OrderedList &li);

    /**
     * \brief Sobrecarga del operador de asignación.
     * \param li Lista ordenada a asignar.
     * \return Referencia a la lista actual después de la asignación.
     */
    OrderedList & operator=(const OrderedList &li);

    // --- Destructor
    /**
     * \brief Destructor de la lista ordenada. Libera la memoria utilizada.
     */
    ~OrderedList();

    // --- Métodos públicos
    /**
     * \brief Agrega un elemento a la lista en orden ascendente.
     * \param val Valor a insertar.
     */
    void Add(Type val);

    /**
     * \brief Elimina la primera ocurrencia de un elemento en la lista.
     * \param val Valor a eliminar.
     */
    void Remove(Type val);

    /**
     * \brief Mezcla dos listas doblemente enlazadas y las almacena en la lista actual en orden ascendente.
     * \param li_1 Primera lista a mezclar.
     * \param li_2 Segunda lista a mezclar.
     */
    void MixLists(const DoubleLinkedList<Type> &li_1, const DoubleLinkedList<Type> &li_2);

    /**
     * \brief Verifica si un elemento está en la lista.
     * \param Val Valor a buscar.
     * \return `true` si el valor está en la lista, `false` en caso contrario.
     */
    bool Contains(Type Val) const;

    /**
     * \brief Vacía la lista eliminando todos sus elementos.
     */
    void Clear();

    /**
     * \brief Verifica si la lista está vacía.
     * \return `true` si la lista no tiene elementos, `false` en caso contrario.
     */
    bool Empty() const;

    /**
     * \brief Retorna el número de elementos en la lista.
     * \return Cantidad de elementos en la lista.
     */
    unsigned Size() const;

    /**
     * \brief Imprime la lista en orden ascendente.
     */
    void Print();

    /**
     * \brief Imprime la lista en orden descendente.
     */
    void PrintReverse();

private:
    // --- Atributos
    /**
     * \brief Lista doblemente enlazada utilizada como base para almacenar los elementos en orden.
     */
    DoubleLinkedList<Type> list;
};

#include "../Templates/OrderedList.tpp"

#endif // ORDEREDLIST_HPP_INCLUDED
