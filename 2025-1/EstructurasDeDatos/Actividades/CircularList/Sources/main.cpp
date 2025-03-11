/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <iostream>
#include "../Headers/CircularList.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        CircularList<int> newList, list2;

        for(int i = 1; i <= 10; ++i)
        {
            newList.Add(i);
        }

        newList.Print();


    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
