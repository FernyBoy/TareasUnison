#ifndef EDGE_HPP_INCLUDED
#define EDGE_HPP_INCLUDED

struct Node;

struct Edge
{
    Node*   adjacent;
    Edge*   next;

    Edge(Node *adj, Edge* next = nullptr): adjacent(adj), next(next) {}
};

#endif // EDGE_HPP_INCLUDED
