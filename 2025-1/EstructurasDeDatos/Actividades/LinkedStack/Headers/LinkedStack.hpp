/**
*   \file   Stack.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#ifndef LINKEDSTACK_HPP_INCLUDED
#define LINKEDSTACK_HPP_INCLUDED

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
template <typename Type>
class LinkedStack
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
    template<typename T>
    friend std::ostream& operator<<(std::ostream& output, const LinkedStack<T>& s);

    /**
     * @brief Operador de extracción en flujo.
     *
     * Permite ingresar datos a la pila desde un flujo de entrada.
     *
     * @param input Flujo de entrada.
     * @param s Pila en la que se almacenarán los datos.
     * @return std::istream& Referencia al flujo de entrada.
     */
    template<typename T>
    friend std::istream& operator>>(std::istream& input, LinkedStack<T>& s);

public:
    // ----- Constructores ----------------------------------------

    /**
     * @brief Constructor por defecto.
     *
     * Crea una pila vacía con una capacidad inicial definida por \a Cap.
     */
    explicit LinkedStack();

    /**
     * @brief Constructor de copia.
     *
     * Crea una nueva pila copiando los elementos y la estructura de otra pila.
     *
     * @param s Pila de la cual se realiza la copia.
     */
    LinkedStack(const LinkedStack &s);

    /**
     * @brief Operador de asignación.
     *
     * Asigna el contenido de la pila \a s a la pila actual.
     *
     * @param s Pila de la cual se asignan los valores.
     * @return Stack& Referencia a la pila actual.
     */
    LinkedStack & operator=(const LinkedStack &s);


    // ----- Destructor -------------------------------------------

    /**
     * @brief Destructor.
     *
     * Libera la memoria asignada y realiza la limpieza necesaria.
     */
    ~LinkedStack();

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
    bool IsEmpty() const;

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
    unsigned StackSize() const;

    /**
     * @brief Imprime los elementos de la pila.
     *
     * Muestra en consola cada uno de los elementos almacenados en la pila.
     */
    void PrintElements();



private:
    // ----- Atributos --------------------------------------------

    /**
     * @brief Capacidad actual de la pila.
     *
     * Se inicializa con el valor de \a Cap y se actualiza al redimensionar la pila.
     */
    unsigned size;

    struct Element 
    {
        Type value;
        Element *nextElement;
    };

    Element *topElement;

    // ----- Métodos privados -------------------------------------

    /**
     * @brief Redimensiona la pila.
     *
     * Elimina una cantidad especifica de elementos llamando a 
     * la función Pop() un número de veces
     */
    void ResizeStack(unsigned int i);
};

#include "../Templates/LinkedStack.tpp"

#endif // STACK_HPP_INCLUDED
