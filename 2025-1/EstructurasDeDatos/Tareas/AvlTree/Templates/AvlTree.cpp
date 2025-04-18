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
    *this = t;
}

template <typename Type>
AvlTree<Type> & AvlTree<Type>::operator=(const AvlTree<Type> &t)
{
    if (this == &t) return *this;
    Clear();

    Queue<Node*> queue;
    queue.Enqueue(t._root);

    while(!queue.IsEmpty()) 
    {
        Node* currentNode = queue.Front();
        queue.Dequeue();

        Add(currentNode -> value);

        if (currentNode -> left != nullptr) queue.Enqueue(currentNode -> left);
        if (currentNode -> right != nullptr) queue.Enqueue(currentNode -> right);
    }

    return *this;
}
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
AvlTree<Type>::~AvlTree()
{
    Clear();
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
    if(_nodes == 0) return;

    cout << "[ ";
    PrintAscendent(_root);
    cout << "\b\b ]";
}

template <typename Type>
void AvlTree<Type>::PrintDescendent() const
{
    if(_nodes == 0) return;

    cout << "[ ";
    PrintDescendent(_root);
    cout << "\b\b ]";
}

template <typename Type>
void AvlTree<Type>::PrintByLevels() const
{
    if (_root == nullptr) return;

    Queue<Node*> queue;
    queue.Enqueue(_root);

    while(!queue.IsEmpty()) 
    {
        Node* currentNode = queue.Front();
        queue.Dequeue();

        cout << currentNode -> value << " ";

        if(currentNode -> left != nullptr) queue.Enqueue(currentNode -> left);
        if (currentNode -> right != nullptr) queue.Enqueue(currentNode -> right);
    }
}

template <typename Type>
void AvlTree<Type>::PrintTree() const
{
    if(_nodes == 0) return;
    
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

    if(parentNode != nullptr) parentNode = UpdateBalance(parentNode);
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

    if(parentNode != nullptr) parentNode = UpdateBalance(parentNode);
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
    if(parentNode == nullptr) return 0;

    int leftHeight = Height(parentNode -> left);
    int rightHeight = Height(parentNode -> right);

    return 1 + std::max(leftHeight, rightHeight);
}

template <typename Type>
void AvlTree<Type>::PrintAscendent(Node *parentNode) const
{
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
    if(parentNode != nullptr)
    {
        PrintDescendent(parentNode -> right);
        cout << parentNode -> value << ", ";
        PrintDescendent(parentNode -> left);
    }
}

template <typename Type>
void AvlTree<Type>::PrintTree(Node *parentNode, const string& prefix) const
{
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
typename AvlTree<Type>::Node *& AvlTree<Type>::RotateRight(Node *&x)
{
   Node *y = x -> left;
   Node *b = y -> right;
   y -> right = x;
   x -> left = b;
   x = y;

   return x;
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::RotateLeft(Node *&x)
{
    Node *y = x -> right;
    Node *b = y -> left;
    y -> left = x;
    x -> right = b;
    x = y;
    return x;
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::DoubleRotateRight(Node *&x)
{
    RotateLeft(x -> left);
    return RotateRight(x);
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::DoubleRotateLeft(Node *&x)
{
    RotateRight(x -> right);
    return RotateLeft(x);
}

template <typename Type>
int AvlTree<Type>::BalanceFactor(Node *parentNode) const
{
    if(parentNode == nullptr) return 0;

    return Height(parentNode -> right) - Height(parentNode -> left);
}

template <typename Type>
typename AvlTree<Type>::Node *& AvlTree<Type>::UpdateBalance(Node *&parentNode)
{
    if(BalanceFactor(parentNode) == 2 && BalanceFactor(parentNode -> right) == 1) return RotateLeft(parentNode);
    if(BalanceFactor(parentNode) == 2 && BalanceFactor(parentNode -> right) == 0) return RotateLeft(parentNode);
    if(BalanceFactor(parentNode) == -2 && BalanceFactor(parentNode -> left) == -1) return RotateRight(parentNode);
    if(BalanceFactor(parentNode) == -2 && BalanceFactor(parentNode -> left) == 0) return RotateRight(parentNode);
    if(BalanceFactor(parentNode) == 2 && BalanceFactor(parentNode -> right) == -1) return DoubleRotateLeft(parentNode);
    if(BalanceFactor(parentNode) == -2 && BalanceFactor(parentNode -> right) == 1) return DoubleRotateRight(parentNode);

    return parentNode;
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
