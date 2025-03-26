/**
*   \file   BinaryTree.tpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   25/03/2025
*/

#include "../Headers/BinaryTree.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
BinaryTree<Type>::BinaryTree() : _nodes(0), _root(nullptr) {}

template <typename Type>
BinaryTree<Type>::BinaryTree(const BinaryTree &t)
{   

}

template <typename Type>
BinaryTree<Type> & BinaryTree<Type>::operator=(const BinaryTree<Type> &t)
{
    return *this;
}
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
BinaryTree<Type>::~BinaryTree()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template <typename Type>
void BinaryTree<Type>::Add(Type val)
{
    Add(val, _root);
}

template <typename Type>
void BinaryTree<Type>::PrintTree() const
{
    PrintTree(_root, 0);      
}

template <typename Type>
void BinaryTree<Type>::PrintAscendent() const
{
    cout << "[ ";
    PrintAscendent(_root);
    cout << "\b\b ]";
}

template <typename Type>
void BinaryTree<Type>::PrintDescendent() const
{
    cout << "[ ";
    PrintDescendent(_root);
    cout << "\b\b ]";
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template <typename Type>
void BinaryTree<Type>::Add(Type val, Node *&parentNode)
{
    if(parentNode == nullptr)
    {
        parentNode = new Node(val);
        ++_nodes;
        return;
    }
    else if(val == parentNode -> value) return;
    else if(val > parentNode -> value) Add(val, parentNode -> right);
    else Add(val, parentNode -> left);
}

template <typename Type>
void BinaryTree<Type>::PrintTree(Node *parentNode, int level) const
{
    if(parentNode != nullptr)
    {
        cout << endl;
        if(level) cout << "    ";
        for(int i = 1; i < level; ++i)
        {
            cout << "│    ";
        }
        cout << "└── " << parentNode -> value;

        PrintTree(parentNode -> left, ++level);
        PrintTree(parentNode -> right, ++level);
    }
}

template <typename Type>
void BinaryTree<Type>::PrintAscendent(Node *parentNode) const
{
    if(parentNode != nullptr)
    {
        PrintAscendent(parentNode -> left);
        cout << parentNode -> value << ", ";
        PrintAscendent(parentNode -> right);
    }
}

template <typename Type>
void BinaryTree<Type>::PrintDescendent(Node *parentNode) const
{
    if(parentNode != nullptr)
    {
        PrintDescendent(parentNode -> right);
        cout << parentNode -> value << ", ";
        PrintDescendent(parentNode -> left);
    }
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
/* 
template <typename Type>
std::ostream & operator<<(std::ostream &output, BinaryTree<Type> &t)
{
    

    return output;
}


template <typename Type>
std::istream & operator>>(std::istream &input, BinaryTree<Type> &t)
{
    

    return input;
}
*/
