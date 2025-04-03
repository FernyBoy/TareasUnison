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
void BinaryTree<Type>::RemoveNode(Type val)
{
    RemoveNode(val, _root);   
}

template <typename Type>
void BinaryTree<Type>::RemoveBranch(Type val)
{
    RemoveBranch(SearchNode(val, _root));
}

template <typename Type>
void BinaryTree<Type>::Clear()
{
    RemoveBranch(_root);
}

template <typename Type>
bool BinaryTree<Type>::Contains(Type val) const
{
    try{
        SearchNode(val, _root);
    }catch(...){
        return false;
    }
    
    return true;
}

template <typename Type>
Type BinaryTree<Type>::FindMin() const
{
    return FindMin(_root) -> value;
}

template <typename Type>
Type BinaryTree<Type>::FindMax() const
{
    return FindMax(_root) -> value;
}

template <typename Type>
unsigned BinaryTree<Type>::Size() const
{
    return _nodes;
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

template <typename Type>
void BinaryTree<Type>::PrintTree() const
{
    cout << _root -> value << endl;
    PrintTree(_root, "");
    cout << endl;
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
void BinaryTree<Type>::RemoveNode(Type val, Node *&parentNode)
{
    if(parentNode == nullptr) return;

    if(val == parentNode -> value)
    {
        if(parentNode -> left != nullptr && parentNode -> right != nullptr)
        {
            Node *&leftMax = FindMax(parentNode);
            parentNode -> value = leftMax -> value;
            RemoveNode(leftMax -> value, leftMax);
        }
        else
        {
            Node *deleteNode = parentNode;
            if(parentNode -> left == nullptr && parentNode -> right == nullptr) parentNode = nullptr;
            else if(parentNode -> left != nullptr) parentNode = parentNode -> left;
            else parentNode = parentNode -> right;
            delete deleteNode;
            --_nodes;
        }
    }
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
typename BinaryTree<Type>::Node * BinaryTree<Type>::FindMin(Node *parent) const
{
    if(_nodes == 0) throw "Árbol vacío";

    if(parent -> left != nullptr) return FindMin(parent -> left);
    else return parent;
}

template <typename Type>
typename BinaryTree<Type>::Node * BinaryTree<Type>::FindMax(Node *parent) const
{
    if(_nodes == 0) throw "Árbol vacío";

    if(parent -> right != nullptr) return FindMax(parent -> right);
    else return parent;
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
