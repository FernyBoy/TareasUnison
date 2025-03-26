/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <cmath>
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
        
        cout << endl;
        tree.PrintAscendent();
        cout << endl;
        tree.PrintDescendent();
        cout << endl << endl;
        tree.PrintTree();

        int val;
        /*
        for(int i = 0; i < 3; ++i)
        {
            cout << "\n\nIngresa el valor a buscar\n - ";
            cin >> val;
                
            cout << endl << "Contiene el " << val << ": " << (tree.Contains(val) ? "Si" : "No");
        }
*/
        for(int i = 0; i < 10; ++i)
        {
            system("clear");
            tree.PrintTree();
            cout << "\n\nIngresa el valor a eliminar\n - ";
            cin >> val;
            tree.RemoveBranch(val);
        }
        
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
