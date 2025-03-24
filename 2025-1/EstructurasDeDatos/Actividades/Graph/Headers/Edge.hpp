/**
*   \file   Edge.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   18/03/2025
*/

#ifndef EDGE_HPP_INCLUDED
#define EDGE_HPP_INCLUDED

struct Node;

struct Edge
{
    Node*   adjacent;
    Edge*   next;

    Edge(Node *adj, Edge* next = nullptr) : adjacent(adj), next(next) {}
};

#endif // EDGE_HPP_INCLUDED
