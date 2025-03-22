/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/03/2025
*/

#include <iostream>
#include <cstdint>
#include <vector>
#include <ctime>
#include <fstream>

#include "../Headers/CircularList.hpp"
#include "../Headers/CapturaSegura.hpp"

using namespace std;

int main()
{
    CircularList<int> list;

    for(int i = 1; i <= 10; ++i)
    {
        list.Add(i);
    }

    list.Print();

    cout << "\nHead: " << list.GetHead();
    list.MoveForward();
    list.MoveForward();
    list.MoveForward();
    cout << "\nHead: " << list.GetHead();
    list.RemoveHead();
    cout << endl;
    list.Print();

    return 0;
}
