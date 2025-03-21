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
        
        CircularList<int> newList;
        newList.Add(10);
        /*
        for(int i = 1; i <= 10; ++i)
        {
            newList.Add(i);
        }
*/
    }catch (const char* e) {
        cerr << "Caught exception: " << e << endl;
    }

    return 0;
}
