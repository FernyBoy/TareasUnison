/**
*   \file   AvlTree.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   17/04/2025
*/

#ifndef AVLTREE_HPP_INCLUDED
#define AVLTREE_HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class AvlTree
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const AvlTree<T> &t);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, AvlTree<T> &t);

    public:
        // --- Constructores
        AvlTree();
        AvlTree(const AvlTree &t);
        AvlTree & operator=(const AvlTree &t);

        // --- Destructor
        ~AvlTree();

        // --- Métodos públicos
        void        Add(Type val);
        void        Remove(Type val);
        void        Clear();

        // - Métodos de obtención
        bool        Contains(Type val)      const;
        unsigned    Size()                  const;
        unsigned    Height()                const;
        
        // - Métodos de impresión
        void        PrintAscendent()        const;
        void        PrintDescendent()       const;
        void        PrintByLevels()         const;
        void        PrintTree()             const;


    private:
        // --- Atributos
        unsigned _nodes;
        
        struct Node
        {
            Type value;
            Node *left, *right;

            Node(Type val) : value(val), left(nullptr), right(nullptr) {}
        };

        Node *_root;

        // --- Métodos privados
        void    Add(Type val, Node *&parentNode);
        void    Remove(Type val, Node *&parentNode);
        void    Clear(Node *&parentNode);

        // - Métodos de obtención
        bool        Contains(Type val, Node* parentNode)            const;
        Node*&      SearchNode(Type val, Node*& parentNode);
        Node*&      FindMin(Node *&parentNode);
        Node*&      FindMax(Node *&parentNode);
        unsigned    Height(Node *parentNode)                        const;
        
        // - Métodos de impresión
        void    PrintAscendent(Node *parentNode)                    const;
        void    PrintDescendent(Node *parentNode)                   const;
        void    PrintByLevels(Node *parentNode)                     const;
        void    PrintTree(Node *parentNode, const string& prefix)   const;

        // --- Métodos de utilería
        void    RotateRight(Node *&parentNode);
        void    RotateLeft(Node *&parentNode);
        void    DoubleRotateRight(Node *&parentNode);
        void    DoubleRotateLeft(Node *&parentNode);
};

#include "../Templates/AvlTree.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
