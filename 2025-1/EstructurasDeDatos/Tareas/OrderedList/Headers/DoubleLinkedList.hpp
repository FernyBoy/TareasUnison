/**
 *   \file   DoubleLinkedList.hpp
 *   \brief  Definición de la clase DoubleLinkedList, una lista doblemente enlazada genérica.
 *   \author Angel Fernando Borquez Guerrero
 *   \author Javier Leonardo Miranda Sanchez
 *   \date   04/03/2025
 */

#ifndef DOUBLELINKEDLIST_HPP_INCLUDED
#define DOUBLELINKEDLIST_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 *  \class DoubleLinkedList
 *  \brief Implementación de una lista doblemente enlazada genérica.
 *  
 *  Esta clase permite almacenar elementos de cualquier tipo y proporciona
 *  métodos para manipular la lista, incluyendo adición, eliminación,
 *  concatenación y operadores sobrecargados.
 * 
 *  \tparam Type Tipo de dato almacenado en la lista.
 */
template <typename Type>
class DoubleLinkedList
{
    // --- Métodos externos --- 
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const DoubleLinkedList<T> &li);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, DoubleLinkedList<T> &li);

public:
    /**
     *  \typedef fun
     *  \brief Tipo de función utilizada como criterio de filtrado.
     */
    typedef bool (*fun)(Type);

    // --- Constructores ---
    
    /**
     *  \brief Constructor por defecto. Crea una lista vacía.
     */
    explicit DoubleLinkedList();

    /**
     *  \brief Constructor de copia.
     *  \param li Lista a copiar.
     */
    DoubleLinkedList(const DoubleLinkedList &li);

    /**
     *  \brief Destructor de la lista.
     *  
     *  Libera toda la memoria utilizada por la lista.
     */
    ~DoubleLinkedList();

    // --- Operadores ---

    /**
     *  \brief Operador de asignación.
     *  \param li Lista a asignar.
     *  \return Referencia a la lista asignada.
     */
    DoubleLinkedList & operator=(const DoubleLinkedList &li);

    /**
     *  \brief Operador de asignación de un valor a un elemento de la lista.
     *  \param val Valor a asignar.
     *  \return Valor asignado.
     */
    Type operator=(Type val);

    /**
     *  \brief Operador de acceso a elementos de la lista (modo lectura).
     *  \param index Índice del elemento a obtener.
     *  \return Valor del elemento en la posición indicada.
     */
    Type operator[](unsigned int index) const;

    /**
     *  \brief Operador de acceso a elementos de la lista (modo escritura).
     *  \param index Índice del elemento a obtener.
     *  \return Puntero al elemento en la posición indicada.
     */
    Type* operator[](unsigned int index);

    // --- Métodos públicos ---

    /**
     *  \brief Agrega un elemento al inicio de la lista.
     *  \param val Valor a agregar.
     */
    void AddFirst(Type val);

    /**
     *  \brief Agrega un elemento al final de la lista.
     *  \param val Valor a agregar.
     */
    void AddLast(Type val);

    /**
     *  \brief Agrega un elemento en una posición específica de la lista.
     *  \param val Valor a agregar.
     *  \param index Índice en el que se insertará el elemento.
     */
    void AddAt(Type val, unsigned int index);

    /**
     *  \brief Concatena otra lista al final de la actual.
     *  \param li Lista a concatenar.
     */
    void Concat(const DoubleLinkedList<Type> &li);

    // --- Funciones de eliminación ---

    /**
     *  \brief Elimina el primer elemento de la lista.
     */
    void RemoveFirst();

    /**
     *  \brief Elimina el último elemento de la lista.
     */
    void RemoveLast();

    /**
     *  \brief Elimina un elemento en una posición específica de la lista.
     *  \param index Índice del elemento a eliminar.
     */
    void RemoveAt(unsigned int index);

    /**
     *  \brief Elimina un elemento desde una posición específica hasta el final.
     *  \param index Índice desde donde se eliminarán los elementos.
     */
    void RemoveFrom(unsigned index);

    /**
     *  \brief Elimina un rango de elementos de la lista.
     *  \param startIndex Índice inicial del rango.
     *  \param endIndex Índice final del rango.
     */
    void RemoveRange(unsigned startIndex, unsigned endIndex);

    /**
     *  \brief Elimina la primera aparición de un elemento específico en la lista.
     *  \param val Valor a eliminar.
     */
    void RemoveElement(Type val);

    /**
     *  \brief Elimina los elementos duplicados de la lista.
     */
    void RemoveDuplicates();

    /**
     *  \brief Elimina todas las apariciones de un elemento específico en la lista.
     *  \param val Valor a eliminar.
     */
    void RemoveAllElements(Type val);

    /**
     *  \brief Elimina los elementos que coincidan con otra lista.
     *  \param li Lista cuyos elementos se eliminarán de la lista actual.
     */
    void RemoveMatching(const DoubleLinkedList<Type> &li);

    /**
     *  \brief Elimina los elementos que cumplen con una condición dada.
     *  \param condition Función que determina qué elementos eliminar.
     */
    void RemoveIf(fun condition);

    /**
     *  \brief Elimina todos los elementos de la lista.
     */
    void Clear();

    // --- Funciones de modificación ---

    /**
     *  \brief Modifica el valor de un elemento en una posición específica.
     *  \param index Índice del elemento a modificar.
     *  \param val Nuevo valor a asignar.
     */
    void SetAt(unsigned index, Type val);

    /**
     *  \brief Clona otra lista en la lista actual.
     *  \param li Lista a clonar.
     */
    void Clone(const DoubleLinkedList<Type> &li);

    // --- Funciones de transferencia ---

    /**
     *  \brief Intercambia el contenido de la lista con otra.
     *  \param li Lista con la que se intercambiarán los datos.
     */
    void Swap(DoubleLinkedList<Type> &li);

    /**
     *  \brief Transfiere todos los elementos de otra lista a la lista actual.
     *  \param li Lista desde la cual se transferirán los elementos.
     */
    void TransferAll(DoubleLinkedList<Type> &li);

    /**
     *  \brief Transfiere elementos desde un índice específico de otra lista.
     *  \param index Índice desde donde se transferirán los elementos.
     *  \param li Lista desde la cual se transferirán los elementos.
     */
    void TransferFrom(unsigned index, DoubleLinkedList<Type> &li);

    /**
     *  \brief Transfiere un rango de elementos de otra lista a la lista actual.
     *  \param startIndex Índice inicial del rango.
     *  \param endIndex Índice final del rango.
     *  \param li Lista desde la cual se transferirán los elementos.
     */
    void TransferRange(unsigned startIndex, unsigned endIndex, DoubleLinkedList<Type> &li);

    // --- Funciones de conjuntos ---

    /**
     *  \brief Devuelve la unión de la lista actual con otra lista.
     *  \param li Lista con la que se realizará la unión.
     *  \return Nueva lista con la unión de ambas listas.
     */
    DoubleLinkedList<Type> Union(const DoubleLinkedList<Type> &li);

    /**
     *  \brief Devuelve la intersección de la lista actual con otra lista.
     *  \param li Lista con la que se realizará la intersección.
     *  \return Nueva lista con los elementos en común.
     */
    DoubleLinkedList<Type> Intersection(const DoubleLinkedList<Type> &li);

    /**
     *  \brief Devuelve la diferencia entre la lista actual y otra lista.
     *  \param li Lista con la que se realizará la diferencia.
     *  \return Nueva lista con los elementos que están en la lista actual pero no en la otra.
     */
    DoubleLinkedList<Type> Difference(const DoubleLinkedList<Type> &li);

    /**
     *  \brief Devuelve la diferencia simétrica entre la lista actual y otra lista.
     *  \param li Lista con la que se realizará la diferencia simétrica.
     *  \return Nueva lista con los elementos que están en una de las listas pero no en ambas.
     */
    DoubleLinkedList<Type> SymmetricDifference(const DoubleLinkedList<Type> &li);

    // --- Funciones de ordenamiento ---

    /**
     *  \brief Invierte el orden de los elementos en la lista.
     */
    void Reverse();

    /**
     *  \brief Ordena la lista en orden ascendente.
     */
    void SortAscending();

    /**
     *  \brief Ordena la lista en orden descendente.
     */
    void SortDescending();

    // --- Funciones de obtención ---

    /**
     *  \brief Obtiene el primer elemento de la lista.
     *  \return Primer elemento de la lista.
     */
    Type GetFirst() const;

    /**
     *  \brief Obtiene el último elemento de la lista.
     *  \return Último elemento de la lista.
     */
    Type GetLast() const;

    /**
     *  \brief Obtiene el elemento en la posición especificada.
     *  \param index Índice del elemento a obtener.
     *  \return Valor del elemento en la posición dada.
     */
    Type GetAt(unsigned index) const;

    /**
     *  \brief Obtiene una nueva lista con los elementos desde un índice específico hasta el final.
     *  \param index Índice desde donde se obtendrán los elementos.
     *  \return Nueva lista con los elementos desde el índice especificado.
     */
    DoubleLinkedList<Type> GetFrom(unsigned index) const;

    /**
     *  \brief Obtiene un rango de elementos de la lista.
     *  \param startIndex Índice inicial del rango.
     *  \param endIndex Índice final del rango.
     *  \return Nueva lista con los elementos en el rango especificado.
     */
    DoubleLinkedList<Type> GetRange(unsigned startIndex, unsigned endIndex) const;

    /**
     *  \brief Verifica si un valor está presente en la lista.
     *  \param val Valor a buscar.
     *  \return true si el valor está en la lista, false en caso contrario.
     */
    bool Contains(Type val) const;

    /**
     *  \brief Obtiene el índice de la primera aparición de un valor en la lista.
     *  \param val Valor a buscar.
     *  \return Índice del valor si se encuentra, de lo contrario un valor fuera de rango.
     */
    unsigned IndexOf(Type val) const;

    /**
     *  \brief Obtiene el tamaño actual de la lista.
     *  \return Número de elementos en la lista.
     */
    unsigned Size() const;

    /**
     *  \brief Verifica si la lista está vacía.
     *  \return true si la lista no contiene elementos, false en caso contrario.
     */
    bool IsEmpty() const;

    // --- Funciones de comparación ---

    /**
     *  \brief Determina si la lista actual es un subconjunto de otra lista.
     *  \param li Lista con la que se comparará.
     *  \return true si la lista actual es un subconjunto, false en caso contrario.
     */
    bool IsSubsetOf(const DoubleLinkedList<Type> &li) const;

    /**
     *  \brief Determina si la lista actual es un superconjunto de otra lista.
     *  \param li Lista con la que se comparará.
     *  \return true si la lista actual es un superconjunto, false en caso contrario.
     */
    bool IsSupersetOf(const DoubleLinkedList<Type> &li) const;

    /**
     *  \brief Compara la lista actual con otra para determinar si son iguales.
     *  \param li Lista con la que se comparará.
     *  \return true si ambas listas contienen los mismos elementos en el mismo orden, false en caso contrario.
     */
    bool IsEqual(const DoubleLinkedList<Type> &li) const;

    // --- Funciones de impresión ---

    /**
     *  \brief Imprime los elementos de la lista en orden normal.
     */
    void Print();

    /**
     *  \brief Imprime los elementos de la lista en orden inverso.
     */
    void PrintReverse();

private:
    // --- Atributos ---

    /**
     *  \brief Número de elementos en la lista.
     */
    unsigned size;

    /**
     *  \brief Estructura interna que representa un nodo de la lista doblemente enlazada.
     */
    struct Element
    {
        /**
         *  \brief Constructor del nodo.
         *  \param val Valor a almacenar en el nodo.
         */
        Element(Type val)
        {
            value = val;
            prevElement = nullptr;
            nextElement = nullptr;
        }

        Type value;                ///< Valor almacenado en el nodo.
        Element *prevElement;      ///< Puntero al nodo anterior.
        Element *nextElement;      ///< Puntero al nodo siguiente.
    };

    Element *firstElement; ///< Puntero al primer nodo de la lista.
    Element *lastElement;  ///< Puntero al último nodo de la lista.

    // --- Métodos privados ---

    /**
     *  \brief Verifica si un índice es válido dentro de la lista.
     *  \param index Índice a verificar.
     *  \return true si el índice es válido, false en caso contrario.
     */
    bool IsValidIndex(unsigned index) const;

    /**
     *  \brief Obtiene un puntero al nodo en la posición especificada.
     *  \param index Índice del nodo a obtener.
     *  \return Puntero al nodo en la posición dada.
     */
    Type* GetPointer(unsigned index);
};

#include "../Templates/DoubleLinkedList.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
