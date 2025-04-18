/**
*   \file   AvlTree.tpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   17/04/2025
*/

#include "../Headers/AvlTree.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
AvlTree<Type>::AvlTree() : _nodes(0), _root(nullptr) {}

template <typename Type>
AvlTree<Type>::AvlTree(const AvlTree &t)
{   

}

template <typename Type>
AvlTree<Type> & AvlTree<Type>::operator=(const AvlTree<Type> &t)
{
    return *this;
}
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
AvlTree<Type>::~AvlTree()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template <typename Type>
void AvlTree<Type>::Add(Type val)
{
    Add(val, _root);
}

template <typename Type>
void AvlTree<Type>::Remove(Type val)
{
    Remove(val, _root);   
}

template <typename Type>
void AvlTree<Type>::Clear()
{
    Clear(_root);
}

template <typename Type>
bool AvlTree<Type>::Contains(Type val) const
{
    return Contains(val, _root);
}

template <typename Type>
unsigned AvlTree<Type>::Size() const
{
    return _nodes;
}

template <typename Type>
unsigned AvlTree<Type>::Height() const
{
    return Height(_root);
}

template <typename Type>
void AvlTree<Type>::PrintAscendent() const
{
    cout << "[ ";
    PrintAscendent(_root);
    cout << "\b\b ]";
}

template <typename Type>
void AvlTree<Type>::PrintDescendent() const
{
    cout << "[ ";
    PrintDescendent(_root);
    cout << "\b\b ]";
}

template <typename Type>
void AvlTree<Type>::PrintByLevels() const
{
    PrintByLevels(_root);
}

template <typename Type>
void AvlTree<Type>::PrintTree() const
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
void AvlTree<Type>::Add(Type val, Node *&parentNode)
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
void AvlTree<Type>::Remove(Type val, Node *&parentNode)
{
    if(parentNode == nullptr) return;

    if(val == parentNode -> value)
    {
        if(parentNode -> left != nullptr && parentNode -> right != nullptr)
        {
            Node *&leftMax = FindMax(parentNode);
            parentNode -> value = leftMax -> value;
            Remove(leftMax -> value, leftMax);
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
    else if(val < parentNode -> value) Remove(val, parentNode -> left);
    else Remove(val, parentNode -> right);
}   

template <typename Type>
void AvlTree<Type>::Clear(Node *&parentNode)
{
    if(parentNode != nullptr)
    {
        Clear(parentNode -> left);
        Clear(parentNode -> right);

        Node* temp = parentNode;
        parentNode = nullptr;
        delete temp;
    }

    _nodes = 0;
}

template <typename Type>
bool AvlTree<Type>::Contains(Type val, Node* parentNode) const
{
    if(parentNode == nullptr) return false;
    
    if(val == parentNode -> value) return true;

    return (val < parentNode -> value) ? Contains(val, parentNode -> left) : Contains(val, parentNode -> right);
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::SearchNode(Type val, Node*& parentNode)
{
    if(parentNode == nullptr) throw "El valor no existe";
    
    if(val == parentNode -> value) return parentNode;

    return (val < parentNode -> value) ? SearchNode(val, parentNode -> left) : SearchNode(val, parentNode -> right);
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::FindMin(Node *&parentNode)
{
    if(_nodes == 0) throw "Árbol vacío";

    if(parentNode -> left != nullptr) return FindMin(parentNode -> left);
    else return parentNode;
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::FindMax(Node *&parentNode)
{
    if(_nodes == 0) throw "Árbol vacío";

    if(parentNode -> right != nullptr) return FindMax(parentNode -> right);
    else return parentNode;
}

template <typename Type>
unsigned AvlTree<Type>::Height(Node *parentNode) const
{
    unsigned height = 0;

    if(parentNode == nullptr) return height;
    return height;
}

template <typename Type>
void AvlTree<Type>::PrintAscendent(Node *parentNode) const
{
    if(_nodes == 0) return;
    
    if(parentNode != nullptr)
    {
        PrintAscendent(parentNode -> left);
        cout << parentNode -> value << ", ";
        PrintAscendent(parentNode -> right);
    }
}

template <typename Type>
void AvlTree<Type>::PrintDescendent(Node *parentNode) const
{
    if(_nodes == 0) return;

    if(parentNode != nullptr)
    {
        PrintDescendent(parentNode -> right);
        cout << parentNode -> value << ", ";
        PrintDescendent(parentNode -> left);
    }
}

template <typename Type>
void AvlTree<Type>::PrintByLevels(Node *parentNode) const
{
    if(_nodes == 0) return;

    if(parentNode == nullptr) cout << " ";
}

template <typename Type>
void AvlTree<Type>::PrintTree(Node *parentNode, const string& prefix) const
{
    if (parentNode == nullptr) return;

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
template <typename Type>
void    AvlTree<Type>::RotateRight(Node *&parentNode)
{

}

template <typename Type>
void    AvlTree<Type>::RotateLeft(Node *&parentNode)
{

}

template <typename Type>
void    AvlTree<Type>::DoubleRotateRight(Node *&parentNode)
{

}

template <typename Type>
void    AvlTree<Type>::DoubleRotateLeft(Node *&parentNode)
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//--------------------------------------------- 
template <typename Type>
std::ostream & operator<<(std::ostream &output, AvlTree<Type> &t)
{
    t.PrintTree();

    return output;
}

/*
template <typename Type>
std::istream & operator>>(std::istream &input, AvlTree<Type> &t)
{
    

    return input;
}
*/
