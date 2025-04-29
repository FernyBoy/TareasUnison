/**
*   \file   BTree.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   29/04/2025
*/

#ifndef BTREE_HPP_INCLUDED
#define BTREE_HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class BTree
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const BTree<T> &bt);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, BTree<T> &bt);

    public:
        // --- Constructores
        explicit BTree();
        BTree(const BTree &bt);
        BTree & operator=(const BTree &bt);

        // --- Destructor
        ~BTree();

        // --- Métodos públicos


    private:
        // --- Atributos


        // --- Métodos privados


        // --- Métodos de utilería

};

#include "../Templates/BTree.tpp"

#endif // !BTREE_HPP_INCLUDED
