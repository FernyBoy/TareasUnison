/**
*   \file   Stack.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <istream>

/**
 * @brief Clase plantilla que implementa una pila (stack) genérica.
 *
 * La clase Stack permite almacenar elementos de cualquier tipo y
 * administra la memoria dinámica para su almacenamiento. La capacidad
 * inicial se define mediante el parámetro de plantilla \a Cap.
 *
 * @tparam Type Tipo de los elementos que se almacenarán en la pila.
 * @tparam Cap Capacidad inicial de la pila.
 */
template <typename Type, unsigned int Cap = 0>
class Stack
{
    // --- Métodos externos (operadores de flujo)
    /**
     * @brief Operador de inserción en flujo.
     *
     * Permite imprimir el contenido de la pila a un flujo de salida.
     *
     * @param output Flujo de salida.
     * @param s Pila a imprimir.
     * @return std::ostream& Referencia al flujo de salida.
     */
    template<typename T, unsigned int C>
    friend std::ostream& operator<<(std::ostream& output, const Stack<T, C>& s);

    /**
     * @brief Operador de extracción en flujo.
     *
     * Permite ingresar datos a la pila desde un flujo de entrada.
     *
     * @param input Flujo de entrada.
     * @param s Pila en la que se almacenarán los datos.
     * @return std::istream& Referencia al flujo de entrada.
     */
    template<typename T, unsigned int C>
    friend std::istream& operator>>(std::istream& input, Stack<T, C>& s);

public:
    // ----- Constructores ----------------------------------------

    /**
     * @brief Constructor por defecto.
     *
     * Crea una pila vacía con una capacidad inicial definida por \a Cap.
     */
    explicit Stack();

    /**
     * @brief Constructor de copia.
     *
     * Crea una nueva pila copiando los elementos y la estructura de otra pila.
     *
     * @param s Pila de la cual se realiza la copia.
     */
    Stack(const Stack &s);

    /**
     * @brief Operador de asignación.
     *
     * Asigna el contenido de la pila \a s a la pila actual.
     *
     * @param s Pila de la cual se asignan los valores.
     * @return Stack& Referencia a la pila actual.
     */
    Stack & operator=(const Stack &s);

    // ----- Destructor -------------------------------------------

    /**
     * @brief Destructor.
     *
     * Libera la memoria asignada y realiza la limpieza necesaria.
     */
    ~Stack();

    // --- Métodos públicos ----------------------------------------

    /**
     * @brief Inserta un elemento en la pila.
     *
     * Agrega el elemento \a val al tope de la pila. Si la pila está llena,
     * se redimensiona para poder insertar el nuevo elemento.
     *
     * @param val Elemento a insertar.
     */
    void Push(Type val);

    /**
     * @brief Elimina el elemento del tope de la pila.
     *
     * Remueve el elemento que se encuentra en el tope de la pila.
     */
    void Pop();

    /**
     * @brief Retorna el elemento en el tope de la pila.
     *
     * @return Type Elemento que se encuentra en el tope.
     * @throws Lanza una excepción si la pila está vacía.
     */
    Type Top() const;

    /**
     * @brief Verifica si la pila está vacía.
     *
     * @return true Si la pila no contiene elementos.
     * @return false Si la pila tiene elementos.
     * @throws Lanza una excepción si la capacidad de la pila es 0.
     */
    bool IsEmpty();

    /**
     * @brief Elimina todos los elementos de la pila.
     *
     * Reinicia la pila, liberando la memoria asignada y recreando el espacio.
     */
    void ClearStack();

    /**
     * @brief Retorna la cantidad de elementos almacenados en la pila.
     *
     * @return unsigned Número de elementos actualmente en la pila.
     */
    unsigned UsedCapacity() const;

    /**
     * @brief Retorna la capacidad actual de la pila.
     *
     * @return unsigned Capacidad total de la pila.
     */
    unsigned Capacity();

    /**
     * @brief Imprime los elementos de la pila.
     *
     * Muestra en consola cada uno de los elementos almacenados en la pila.
     */
    void PrintElements();

    /**
     * @brief Operador de indexación.
     *
     * Permite acceder a un elemento de la pila mediante su índice.
     *
     * @param i Índice del elemento.
     * @return Type Elemento ubicado en la posición \a i.
     * @throws Lanza una excepción si el índice es inválido.
     */
    Type operator[](int i) const;

private:
    // ----- Atributos --------------------------------------------

    /**
     * @brief Capacidad actual de la pila.
     *
     * Se inicializa con el valor de \a Cap y se actualiza al redimensionar la pila.
     */
    unsigned size;

    /**
     * @brief Arreglo dinámico que almacena los elementos de la pila.
     */
    Type *elements;

    /**
     * @brief Índice del elemento tope de la pila.
     *
     * Un valor de -1 indica que la pila está vacía.
     */
    int currentIndex = -1;

    // ----- Métodos privados -------------------------------------

    /**
     * @brief Verifica si la pila está llena.
     *
     * @return true Si el número de elementos usados es igual a la capacidad.
     * @return false En caso contrario.
     */
    bool IsFull();

    /**
     * @brief Redimensiona la pila.
     *
     * Duplica la capacidad actual de la pila, asigna un nuevo arreglo,
     * copia los elementos existentes y libera la memoria del arreglo anterior.
     */
    void ResizeStack();

    // ----- Métodos de utilería ----------------------------------

    /**
     * @brief Crea el arreglo que almacenará los elementos de la pila.
     *
     * Asigna memoria dinámica para el arreglo de elementos.
     * @throws Lanza una excepción si falla la asignación de memoria.
     */
    void CreateStack();

    /**
     * @brief Libera la memoria asignada al arreglo de elementos.
     */
    void ClearMemory();
};

#include "../Templates/Stack.tpp"

#endif // STACK_HPP_INCLUDED
