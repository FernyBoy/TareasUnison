/**
*   \file   Graph.hpp
*   \author Angel Fernando Bórquez Guerrero
*   \date   18/03/2025
*/

#ifndef _HPP_INCLUDED
#define _HPP_INCLUDED

#include <iostream>
#include <ostream>

#include "../Headers/Node.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Graph
{
    public:
        // -------------------------
        // ----- Constructores -----
        // -------------------------
        explicit Graph();
        Graph(const Graph &g);
        Graph & operator=(const Graph &g);
        
        // --- Destructor
        ~Graph();
        
        // ----------------------------
        // ----- Métodos públicos -----
        // ----------------------------
        // --- Funciones para agregar 
        void        AddNode(char name);
        void        AddEdge(char firstName, char lastName);

        // --- Funciones de eliminación
        void        RemoveNode(char name);
        void        RemoveEdge(char firstName, char lastName);
        void        ClearNode(char name)                        const;
        void        Clear();

        // --- Funciones de obtención
        unsigned    GetNodes()  const;
        unsigned    GetEdges()  const;
        unsigned    GetDegree() const;

        // --- Funciones de búsqueda
        bool        SearchNode(char name)                       const;
        bool        SearchEdge(char firstName, char lastName)   const;

        // --- Funciones de impresión
        void        Print();



    private:
        // --- Atributos
        Node        *First, *Last;
        unsigned    Nodes, Edges;

        // --- Métodos privados
        Node*       PointerOf(char name, Node **prev = nullptr)    const;

        // --- Métodos de utilería

};

#include "../Templates/Graph.cpp"

#endif // !EXPRESSION_HPP_INCLUDED
