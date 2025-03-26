/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <cmath>
#include <iostream>
#include "../Headers/BinaryTree.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
    
        BinaryTree<int> tree;

        for(int i = 0; i < 10; ++i)
        {
            tree.Add(pow(-1, i) * i);
        }

        tree.PrintAscendent();
        cout << endl;
        tree.PrintDescendent();
        cout << endl;
        tree.PrintTree();
        
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
