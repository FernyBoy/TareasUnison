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
        LinkedList<int> list, list2;
        
        for(int i = 0; i < 10; ++i)
        {
            list.AddLast(i);
        }
        cout << list;

        list2 = list;
        cout << endl << list2;
        list2.RemoveElement(5);
        cout << endl << list2;


    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }
}
