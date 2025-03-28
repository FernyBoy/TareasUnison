/**
*   \file   BinaryTree.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   25/03/2025
*/

#ifndef BINARYTREE_HPP_INCLUDED
#define BINARYTREE_HPP_INCLUDED

#include <iostream>

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
        BinaryTree();
        BinaryTree(const BinaryTree &t);
        BinaryTree & operator=(const BinaryTree &t);

        // --- Destructor
        ~BinaryTree();

        // --- Métodos públicos
        void    Add(Type val);
        void    RemoveBranch(Type val);
        bool    Contains(Type val);
        
        void    PrintTree()         const;
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
        void    RemoveBranch(Node *&parentNode);
        Node*&  SearchNode(Type val, Node*& parentNode);
        
        void    PrintTree(Node *parentNode, const string& prefix)   const;
        void    PrintAscendent(Node *parentNode)                    const;
        void    PrintDescendent(Node *parentNode)                   const;

        // --- Métodos de utilería

};

#include "../Templates/BinaryTree.tpp"

#endif // BINARYTREE_HPP_INCLUDED
