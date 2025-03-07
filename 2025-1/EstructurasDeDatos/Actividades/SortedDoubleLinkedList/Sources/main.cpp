/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <cmath>
#include <iostream>
#include "../Headers/SDLL.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::pow;

int main()
{
    try{
        SDLL<int> newList, list2;
        
        for(int i = 0; i < 10; ++i)
        {
            newList.Add((pow(-1, i) * (i + 1)));
        }

        newList.Print();

        list2 = newList;
        
        cout << endl << endl;
        list2.Print();
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
