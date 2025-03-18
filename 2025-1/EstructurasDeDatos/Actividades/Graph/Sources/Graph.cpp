/**
*   \file   Graph.tpp
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

void Graph::AddEdge(char FirstName, char lastName)
{
    Node *FirstNode = PointerOf(FirstName);
    if(FirstNode == nullptr) return;

    Node *lastNode = PointerOf(lastName);
    if(lastNode == nullptr) return;

    FirstNode -> Add(lastNode);
    lastNode -> Add(FirstNode);
    
    ++Edges;
}

// -----------------------------------
// ----- Funciones para eliminar -----
// -----------------------------------
void Graph::RemoveNode(char name)
{
    Node *prev, *deleteNode = PointerOf(name, &prev);

    if(deleteNode == nullptr) return;
    Edges -= deleteNode -> Clear();

    
}

void Graph::RemoveEdge(char FirstName, char lastName)
{

}

void Graph::ClearNode(char name) const
{

}

void Graph::Clear()
{

}


// ----------------------------------
// ----- Funciones de obtención -----
// ----------------------------------
unsigned Graph::GetNodes() const
{

}

unsigned Graph::GetEdges() const
{

}

unsigned Graph::GetDegree() const
{

}


// ---------------------------------
// ----- Funciones de búsqueda -----
// ---------------------------------
bool Graph::SearchNode(char name) const
{

}

bool Graph::SearchEdge(char FirstName, char lastName) const
{

}


// ----------------------------------
// ----- Funciones de impresión -----
// ----------------------------------
void Graph::Print()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
Node* Graph::PointerOf(char name, Node **prev) const
{

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
