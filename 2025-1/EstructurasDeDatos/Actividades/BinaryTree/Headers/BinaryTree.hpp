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
        void        Add(Type val);
        void        RemoveNode(Type val);
        void        RemoveBranch(Type val);
        void        Clear();

        // - Métodos de obtención
        bool        Contains(Type val)      const;
        Type        FindMin()               const;
        Type        FindMax()               const;
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
        void    RemoveNode(Type val, Node *&parentNode);
        void    RemoveBranch(Node *&parentNode);

        // - Métodos de obtención
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

};

#include "../Templates/BinaryTree.tpp"

#endif // BINARYTREE_HPP_INCLUDED
