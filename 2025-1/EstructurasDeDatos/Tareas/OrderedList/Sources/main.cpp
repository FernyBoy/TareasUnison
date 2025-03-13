/**
*   \file   main.cpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   12/03/2025
*/

#include <iostream>
#include <cmath>

#include "../Headers/OrderedList.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        OrderedList<int> newList;
        DoubleLinkedList<int> list1, list2;

        for(int i = 0; i < 10; ++i)
        {
            newList.Add(pow(-1, i) * (i + 1));
            list1.AddLast(pow(-1, i) * (i + 1) * 10);
            list2.AddLast(pow(-1, i) * (i + 1) * 100);
        }

        newList.Print();
        cout << endl;
        newList.MixLists(list1, list2);
        cout << endl;
        list1.Print();
        cout << endl;
        list2.Print();
        cout << endl;
        newList.Print();

    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
