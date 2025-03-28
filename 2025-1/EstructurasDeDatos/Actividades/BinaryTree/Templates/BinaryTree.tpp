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
void BinaryTree<Type>::RemoveBranch(Type val)
{
    RemoveBranch(SearchNode(val, _root));
}

template <typename Type>
bool BinaryTree<Type>::Contains(Type val)
{
    try{
        SearchNode(val, _root);
    }catch(...){
        return false;
    }
    
    return true;
}

template <typename Type>
void BinaryTree<Type>::PrintTree() const
{
    cout << _root -> value << endl;
    PrintTree(_root, "");
    cout << endl;
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
void BinaryTree<Type>::RemoveBranch(Node *&parentNode)
{
    if(parentNode != nullptr)
    {
        RemoveBranch(parentNode -> left);
        RemoveBranch(parentNode -> right);
        parentNode = nullptr;
        delete parentNode;
        --_nodes;
    }
}

template <typename Type>
typename BinaryTree<Type>::Node *& BinaryTree<Type>::SearchNode(Type val, Node*& parentNode)
{
    if(parentNode == nullptr) throw "El valor no existe";
    
    if(val == parentNode -> value) return parentNode;

    return (val < parentNode -> value) ? SearchNode(val, parentNode -> left) : SearchNode(val, parentNode -> right);
}

template <typename Type>
void BinaryTree<Type>::PrintTree(Node *parentNode, const string& prefix) const
{
    if(parentNode == nullptr) return;

    bool hasLeft = (parentNode -> left != nullptr);
    bool hasRight = (parentNode -> right != nullptr);

    if (!hasLeft && !hasRight) return;

    cout << prefix;
    cout << ((hasLeft  && hasRight) ? "├── " : "");
    cout << ((!hasLeft && hasRight) ? "└── " : "");

    if(hasRight)
    {
        bool printStrand = (hasLeft && hasRight && (parentNode -> right -> right != nullptr || parentNode -> right -> left != nullptr));
        string newPrefix = prefix + (printStrand ? "│   " : "    ");
        cout << parentNode -> right -> value << endl;
        PrintTree(parentNode -> right, newPrefix);
    }

    if(hasLeft)
    {
        cout << (hasRight ? prefix : "") << "└── " << parentNode -> left -> value << endl;
        PrintTree(parentNode -> left, prefix + "    ");
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
