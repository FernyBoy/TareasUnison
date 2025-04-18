/**
* @file AvlTree.hpp
* @brief Implementación de un árbol AVL (árbol binario de búsqueda balanceado)
* @author Angel Fernando Bórquez Guerrero
* @author Javier Leonardo Miranda Sanchez
* @date 17/04/2025
*/

#ifndef AVLTREE_HPP_INCLUDED
#define AVLTREE_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <string>

#include "./Queue.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
* @brief Plantilla de clase para un árbol AVL
* @tparam Type Tipo de dato que almacenará el árbol
*/
template <typename Type>
class AvlTree
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const AvlTree<T> &t);

public:
    // --- Constructores
    
    /**
    * @brief Constructor por defecto que crea un árbol AVL vacío
    */
    AvlTree();
    
    /**
    * @brief Constructor de copia
    * @param t Árbol AVL a copiar
    */
    AvlTree(const AvlTree &t);
    
    /**
    * @brief Operador de asignación
    * @param t Árbol AVL a copiar
    * @return Referencia al árbol actual
    */
    AvlTree & operator=(const AvlTree &t);

    // --- Destructor
    
    /**
    * @brief Destructor que libera toda la memoria del árbol
    */
    ~AvlTree();

    // --- Métodos públicos
    
    /**
    * @brief Inserta un nuevo valor en el árbol
    * @param val Valor a insertar
    */
    void Add(Type val);
    
    /**
    * @brief Elimina un valor del árbol
    * @param val Valor a eliminar
    */
    void Remove(Type val);
    
    /**
    * @brief Vacía por completo el árbol
    */
    void Clear();

    // - Métodos de obtención
    
    /**
    * @brief Verifica si un valor existe en el árbol
    * @param val Valor a buscar
    * @return true si el valor existe, false en caso contrario
    */
    bool Contains(Type val) const;
    
    /**
    * @brief Obtiene el número de nodos en el árbol
    * @return Número de nodos en el árbol
    */
    unsigned Size() const;
    
    /**
    * @brief Obtiene la altura del árbol
    * @return Altura del árbol
    */
    unsigned Height() const;
    
    // - Métodos de impresión
    
    /**
    * @brief Imprime los valores del árbol en orden ascendente
    */
    void PrintAscendent() const;
    
    /**
    * @brief Imprime los valores del árbol en orden descendente
    */
    void PrintDescendent() const;
    
    /**
    * @brief Imprime los valores del árbol por niveles (BFS)
    */
    void PrintByLevels() const;
    
    /**
    * @brief Imprime el árbol en formato de árbol visual
    */
    void PrintTree() const;

private:
    // --- Atributos
    unsigned _nodes; ///< Contador de nodos en el árbol
    
    /**
    * @brief Estructura interna para los nodos del árbol
    */
    struct Node
    {
        Type value;     ///< Valor almacenado en el nodo
        Node *left;     ///< Puntero al hijo izquierdo
        Node *right;    ///< Puntero al hijo derecho

        /**
        * @brief Constructor del nodo
        * @param val Valor a almacenar en el nodo
        */
        Node(Type val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node *_root; ///< Raíz del árbol AVL

    // --- Métodos privados
    
    /**
    * @brief Método privado recursivo para insertar un valor
    * @param val Valor a insertar
    * @param parentNode Nodo actual en la recursión
    */
    void Add(Type val, Node *&parentNode);
    
    /**
    * @brief Método privado recursivo para eliminar un valor
    * @param val Valor a eliminar
    * @param parentNode Nodo actual en la recursión
    */
    void Remove(Type val, Node *&parentNode);
    
    /**
    * @brief Método privado recursivo para vaciar el árbol
    * @param parentNode Nodo actual en la recursión
    */
    void Clear(Node *&parentNode);

    // - Métodos de obtención
    
    /**
    * @brief Método privado recursivo para buscar un valor
    * @param val Valor a buscar
    * @param parentNode Nodo actual en la recursión
    * @return true si el valor existe, false en caso contrario
    */
    bool Contains(Type val, Node* parentNode) const;
    
    /**
    * @brief Busca un nodo con el valor especificado
    * @param val Valor a buscar
    * @param parentNode Nodo actual en la recursión
    * @return Referencia al puntero del nodo encontrado
    * @throw Lanza excepción si el valor no existe
    */
    Node*& SearchNode(Type val, Node*& parentNode);
    
    /**
    * @brief Encuentra el nodo con el valor mínimo en un subárbol
    * @param parentNode Nodo raíz del subárbol
    * @return Referencia al puntero del nodo con el valor mínimo
    * @throw Lanza excepción si el árbol está vacío
    */
    Node*& FindMin(Node *&parentNode);
    
    /**
    * @brief Encuentra el nodo con el valor máximo en un subárbol
    * @param parentNode Nodo raíz del subárbol
    * @return Referencia al puntero del nodo con el valor máximo
    * @throw Lanza excepción si el árbol está vacío
    */
    Node*& FindMax(Node *&parentNode);
    
    /**
    * @brief Calcula la altura de un subárbol
    * @param parentNode Nodo raíz del subárbol
    * @return Altura del subárbol
    */
    unsigned Height(Node *parentNode) const;
    
    // - Métodos de impresión
    
    /**
    * @brief Imprime un subárbol en orden ascendente
    * @param parentNode Nodo raíz del subárbol
    */
    void PrintAscendent(Node *parentNode) const;
    
    /**
    * @brief Imprime un subárbol en orden descendente
    * @param parentNode Nodo raíz del subárbol
    */
    void PrintDescendent(Node *parentNode) const;
    
    /**
    * @brief Imprime un subárbol en formato de árbol visual
    * @param parentNode Nodo raíz del subárbol
    * @param prefix Prefijo para la visualización jerárquica
    */
    void PrintTreeLinux(Node *parentNode, const string& prefix) const;

    /**
    * @brief Imprime un subárbol en formato de árbol visual para el sistema Windows
    * @param parentNode Nodo raíz del subárbol
    * @param prefix Prefijo para la visualización jerárquica
    */
    void PrintTreeWindows(Node *parentNode, const string& prefix) const;

    // --- Métodos de utilería
    
    /**
    * @brief Realiza una rotación simple a la derecha
    * @param x Nodo que necesita ser balanceado
    * @return Nueva raíz del subárbol
    */
    Node*& RotateRight(Node *&x);
    
    /**
    * @brief Realiza una rotación simple a la izquierda
    * @param x Nodo que necesita ser balanceado
    * @return Nueva raíz del subárbol
    */
    Node*& RotateLeft(Node *&x);
    
    /**
    * @brief Realiza una rotación doble derecha (izquierda-derecha)
    * @param x Nodo que necesita ser balanceado
    * @return Nueva raíz del subárbol
    */
    Node*& DoubleRotateRight(Node *&x);
    
    /**
    * @brief Realiza una rotación doble izquierda (derecha-izquierda)
    * @param x Nodo que necesita ser balanceado
    * @return Nueva raíz del subárbol
    */
    Node*& DoubleRotateLeft(Node *&x);
    
    /**
    * @brief Calcula el factor de balance de un nodo
    * @param parentNode Nodo a evaluar
    * @return Factor de balance (altura subárbol derecho - altura subárbol izquierdo)
    */
    int BalanceFactor(Node *parentNode) const;
    
    /**
    * @brief Actualiza el balance de un nodo y realiza rotaciones si es necesario
    * @param parentNode Nodo a balancear
    * @return Nueva raíz del subárbol después del balanceo
    */
    Node*& UpdateBalance(Node *&parentNode);
};

#include "../Templates/AvlTree.tpp"

#endif
