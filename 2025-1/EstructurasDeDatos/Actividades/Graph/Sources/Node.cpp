#include "../Headers/Node.hpp"

Node::Node(char name, Node *next /* = nullptr */): name(name), degree(0), first(nullptr), last(nullptr), next(next) {}

void Node::Add(Node *adj)
{
    Edge *newEdge = new Edge(adj);

    degree == 0 ? first = newEdge : last -> next = newEdge;
    last = newEdge;

    ++degree;
}

void Node::Remove(Node *adj)
{
    Edge *prev, *deleteEdge = PointerOf(adj, &prev);

    if(deleteEdge == nullptr) return;

    prev == nullptr ? first = first -> next : prev -> next = deleteEdge -> next;

    if(first == nullptr) last = nullptr;

    delete deleteEdge;

    --degree;
}

unsigned Node::Clear()
{
    int edgeNumber = 0;

    while(first != nullptr)
    {
        Edge *deleteEdge = first;

        if(first -> adjacent != this) first -> adjacent -> Remove(this);

        first = first -> next;

        delete deleteEdge;

        ++edgeNumber;
    }

    last = nullptr;
    degree = 0;
    return edgeNumber;
}

bool Node::IsAdjacent(Node *adj) const
{
    return PointerOf(adj) != nullptr;
}

void Node::Print() const
{
    Edge *aux = first;

    while(aux != nullptr)
    {
        cout << aux -> adjacent -> name << ", ";
        aux = aux -> next;
    }
    cout << "\b\b ";
}

Edge * Node::PointerOf(Node *adj, Edge **prev /* = nullptr */) const
{
    Edge *aux = first;
    if(prev != nullptr) prev = nullptr;

    while(aux != nullptr && aux -> adjacent != adj)
    {
        if(prev != nullptr) *prev = aux;
        aux = aux -> next;
    }

    return aux;
}


