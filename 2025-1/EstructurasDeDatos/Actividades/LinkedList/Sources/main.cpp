/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <iostream>
#include "../Headers/LinkedList.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        LinkedList<int> newList;
        
        for(int i = 0; i < 11; ++i)
        {
            newList.AddFirst(i);
        }

        for(int i = 0; i < 10; ++i)
        {
            newList.AddLast(i + 1);
        }

        newList.PrintList();

    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }
}
