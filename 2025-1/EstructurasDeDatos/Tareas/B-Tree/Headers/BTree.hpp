/**
*   \file   BTree.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   29/04/2025
*/

#ifndef BTREE_HPP_INCLUDED
#define BTREE_HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type, unsigned Degree = 5>
class BTree
{
    public:
        // --- Constructores
        BTree();
        BTree(const BTree &bt);
        BTree & operator=(const BTree &bt);

        // --- Destructor
        ~BTree();

        // ----- Métodos públicos -----
        // - Métodos de inserción
        void    Insert(Type value);
        void    Remove(Type value);
        void    Clear();

        // - Métodos de obtención
        bool        IsEmpty()               const;
        unsigned    Size()                  const;
        bool        Contains(Type value)    const;

        // - Métodos de impresión
        void    PrintAscendant()    const;
        void    PrintDescenant()    const;
        void    PrintLevels()       const;
        void    PrintTree()         const;

    private:
        // --- Atributos
        struct Node 
        {
            Node(*parentNode) {};

            ~Node() {};
        };

        Node        *_root;
        unsigned    _nodes;

        // ----- Métodos privados -----
        // - Métodos de inserción
        void    Insert(Type value, Node *subRoot);
        void    Remove(Type value, Node *subRoot);
        void    Clear(Node *subRoot);

        // - Métodos de modificación
        void    LendToLeft(Node *subRoot);
        void    LendToRight(Node *subRoot);
        void    SplitRoot();
        void    Split(Node *left, Node *right);
        void    Merge(Node *& node);
        void    Redistribute(Node *&subRoot);

        // - Métodos de obtención
        bool    Contains(Type value, const Node *subRoot)   const;
        Node*   GetNodeAddress();

        // - Métodos de impresión
        void    PrintAscendant(Node *parentNode)    const;
        void    PrintDescendant(Node *parentNode)   const;
        void    PrintLevels(Node *parentNode)       const;
        void    PrintTree(Node *parentNode)         const;

        // --- Métodos de utilería
        void    CopyNode(Node *&copy, const Node *source);

};

#include "../Templates/BTree.tpp"

#endif // !BTREE_HPP_INCLUDED
