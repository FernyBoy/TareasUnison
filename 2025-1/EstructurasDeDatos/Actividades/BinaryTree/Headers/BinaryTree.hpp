/**
*   \file   BinaryTree.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   25/03/2025
*/

#ifndef BINARYTREE_HPP_INCLUDED
#define BINRAYTREE_HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class BinaryTree
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const BinaryTree<T> &t);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, BinaryTree<T> &t);

    public:
        // --- Constructores
        explicit BinaryTree();
        BinaryTree(const BinaryTree &t);
        BinaryTree & operator=(const BinaryTree &t);

        // --- Destructor
        ~BinaryTree();

        // --- Métodos públicos
        void    Add(Type val);

        void    PrintAscendent()    const;
        void    PrintDescendent()   const;


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

        void    PrintAscendent(Node *parentNode)    const;
        void    PrintDescendent(Node *parentNode)   const;

        // --- Métodos de utilería

};

#include "../Templates/BinaryTree.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
