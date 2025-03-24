/**
*   \file   Graph.cpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   18/03/2025
*/

#include "../Headers/Graph.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------

Graph::Graph() : First(nullptr), Last(nullptr), Nodes(0), Edges(0) {}

Graph::Graph(const Graph &g) : First(nullptr), Last(nullptr), Nodes(0), Edges(0)
{   
    *this = g;
}


Graph & Graph::operator=(const Graph &g)
{
    if(this == &g) return *this;

    Clear();

    Node *auxNode = g.First;

    while(auxNode != nullptr)
    {
        AddNode(auxNode -> name);
        auxNode = auxNode -> next;
    }

    auxNode = g.First;
    Edge *auxEdge;
    while(auxNode != nullptr)
    {
        auxEdge = auxNode -> first;

        while(auxEdge != nullptr)
        {
            if(!SearchEdge(auxNode -> name, auxEdge -> adjacent -> name))
            {
                AddEdge(auxNode -> name, auxEdge -> adjacent -> name);
            }
            auxEdge = auxEdge -> next;
        }
        auxNode = auxNode -> next;
    }

    return *this;
}


// ----------------------
// ----- Destructor -----
// ----------------------
Graph::~Graph()
{
    Clear();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
// ----------------------------------
// ----- Funciones para agregar -----
// ----------------------------------
void Graph::AddNode(char name)
{
    Node *newNode = new Node(name);

    Nodes == 0 ? First = newNode : Last -> next = newNode;

    Last = newNode;

    ++Nodes;
}

void Graph::AddEdge(char FirstName, char LastName)
{
    Node *firstNode = PointerOf(FirstName);
    if(firstNode == nullptr) {
        throw std::runtime_error("Node with name '" + std::string(1, FirstName) + "' does not exist.");
    }

    Node *lastNode = PointerOf(LastName);
    if(lastNode == nullptr) {
        throw std::runtime_error("Node with name '" + std::string(1, LastName) + "' does not exist.");
    }

    firstNode->Add(lastNode);
    lastNode->Add(firstNode);
    
    ++Edges;
}


// -----------------------------------
// ----- Funciones para eliminar -----
// -----------------------------------
void Graph::RemoveNode(char name)
{
    Node *prev, *deleteNode = PointerOf(name, &prev);

    if (deleteNode == nullptr) return;
    Edges -= deleteNode -> Clear();

    if(prev == nullptr) 
    {
        First = First -> next;
        if(First == nullptr) Last = nullptr;
    }
    else 
    {
        prev -> next = deleteNode -> next;
        if(deleteNode == Last) Last = prev;
    }

    delete deleteNode;
    --Nodes;
}


void Graph::RemoveEdge(char firstName, char lastName)
{
    Node *firstPointer = PointerOf(firstName);
    if(firstPointer == nullptr) return;

    Node *lastPointer = PointerOf(lastName);
    if(lastPointer == nullptr) return;

    firstPointer -> Remove(lastPointer);
    lastPointer -> Remove(firstPointer);

    --Edges;
}

void Graph::ClearNode(char name)
{
    Node *aux = PointerOf(name);

    if(aux == nullptr) return;

    Edges -= aux -> Clear();
}

void Graph::Clear()
{
    while(First != nullptr)
    {
        Node* nodeToDelete = First;
        First = First->next;
        delete nodeToDelete;
    }

    Nodes = 0;
    Edges = 0;
}


// ----------------------------------
// ----- Funciones de obtención -----
// ----------------------------------
unsigned Graph::GetNodes() const
{
    return Nodes;
}

unsigned Graph::GetEdges() const
{
    return Edges;
}

unsigned Graph::GetDegree(char name) const
{
    Node *aux = PointerOf(name);

    if(aux == nullptr) throw "El nodo no existe";

    return aux -> degree;
}


// ---------------------------------
// ----- Funciones de búsqueda -----
// ---------------------------------
bool Graph::SearchNode(char name) const
{
    return PointerOf(name) != nullptr;
}

bool Graph::SearchEdge(char firstName, char lastName) const
{
    Node *firstPointer = PointerOf(firstName);
    Node *lastPointer = PointerOf(lastName);

    return firstPointer && lastPointer && firstPointer -> PointerOf(lastPointer) != nullptr;
}



// ----------------------------------
// ----- Funciones de impresión -----
// ----------------------------------

void Graph::Print() const
{
    if(Nodes == 0) return;

    if(Nodes == 1)
    {
        cout << "│" << endl;
        cout << "└── " << First->name << endl;
        return;
    }

    Node *currentNode = First;

    while(currentNode != nullptr)
    {

        cout << "\n│";
        cout << (currentNode -> next == nullptr ? "\n└── " : "\n├── ") << currentNode -> name;

        Edge *currentEdge = currentNode -> first;

        while(currentEdge != nullptr)
        {
            cout 
                << (currentNode -> next != nullptr ? "\n│   " : "\n    ")
                << (currentEdge -> next == nullptr ? "└── " : "├── ")
                << currentEdge -> adjacent -> name;

            currentEdge = currentEdge->next;
        }

        currentNode = currentNode -> next;

        if(currentNode != nullptr)
        {
            currentEdge = currentNode -> first;
        }
    }
}


void Graph::DebugPrint() const
{
    Node *currentNode = First;

    while(currentNode != nullptr)
    {
        cout << "Node: " << currentNode -> name << "\nEdges: ";
        Edge *currentEdge = currentNode -> first;
        while(currentEdge != nullptr)
        {
            cout << currentEdge -> adjacent -> name << " ";
            currentEdge = currentEdge -> next;
        }
        cout << "\n";
        currentNode = currentNode -> next;
    }
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
Node* Graph::PointerOf(char name, Node **prev) const
{
    Node *aux = First;

    if(prev != nullptr) *prev = nullptr;

    while(aux != nullptr && aux -> name != name)
    {
        if(prev != nullptr) *prev = aux;

        aux = aux -> next;
    }

    return aux;
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
