#include "../Headers/Node.hpp"

Node::Node(char name, Node *next /* = nullptr */): name(name), degree(0), first(nullptr), last(nullptr), next(nullptr)
{

}

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
