/**
*   \file   Node.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   18/03/2025
*/

#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <iostream>

#include "Edge.hpp"

using std::cout;

struct Node
{
    char        name;
    unsigned    degree;
    Edge        *first, *last;
    Node        *next;

    Node(char name, Node *next = nullptr);

    void        Add(Node *adj);
    void        Remove(Node *adj);
    unsigned    Clear();
    bool        IsAdjacent(Node *adj)                       const;
    void        Print()                                     const;
    Edge*       PointerOf(Node *adj, Edge **prev = nullptr) const;
};

#endif // NODE_HPP_INCLUDED
