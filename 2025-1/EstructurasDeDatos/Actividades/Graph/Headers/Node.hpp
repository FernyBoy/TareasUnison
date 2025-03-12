#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include "Edge.hpp"

struct Node
{
    char    name;
    int     degree;
    Edge    *first, *last;
    Node    *next;

    Node(char name, Node *next = nullptr);

    void    Add(Node *adj);
    void    Remove(Node *adj);
    void    Clear();
    bool    IsAdjacent(Node *adj)                       const;
    void    Print()                                     const;
    Edge *  PointerOf(Node *adj, Edge **prev = nullptr) const;
};

#endif // NODE_HPP_INCLUDED
