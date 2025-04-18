/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <system_error>
#include "../Headers/BinaryTree.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    system("clear");

    try{
    
        BinaryTree<int> tree;

        tree.Add(35);
        tree.Add(20);
        tree.Add(52);
        tree.Add(10);
        tree.Add(29);
        tree.Add(41);
        tree.Add(115);
        tree.Add(95);
        
        while(true)
        {
            system("clear");
            tree.PrintTree();
            cout << "\n\nIngresa el valor a eliminar:\n - ";
            int deleteNode;
            cin >> deleteNode;

            tree.Clear();
            cout << endl << endl;
        }


    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
