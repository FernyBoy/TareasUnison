/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \date   23/03/2025
*/

#include <iostream>
#include "../Headers/Graph.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Graph g;
        g.AddNode('a');
        g.AddNode('b');
        g.AddNode('c');
        g.AddNode('d');
        g.AddNode('e');
        g.AddNode('f');

        g.AddEdge('a', 'b');
        g.AddEdge('a', 'c');
        g.AddEdge('a', 'd');
        g.AddEdge('a', 'e');
        g.AddEdge('a', 'f');

        g.AddEdge('b', 'c');
        g.AddEdge('b', 'd');
        g.AddEdge('b', 'e');
        g.AddEdge('b', 'f');

        g.AddEdge('c', 'd');
        g.AddEdge('c', 'e');
        g.AddEdge('c', 'f');

        g.AddEdge('d', 'e');
        g.AddEdge('d', 'f');

        g.AddEdge('e', 'f');

        g.Print();

    }catch (const std::runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}
