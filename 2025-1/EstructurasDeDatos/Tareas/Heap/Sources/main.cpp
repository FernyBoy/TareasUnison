/**
*   \file   main.cpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   26/04/2025
*/

#include <iostream>
#include <cmath>
#include "../Headers/Heap.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Heap<int> heap;

        for(int i = 0; i < 20; ++i)
        {
            heap.Insert(pow(-1, i) * (i + 1));
        }

        int answer = 1;
        while(answer != 0)
        {
            system("clear");
            cout << heap;
            cout << "\n - ";
            cin >> answer;
            heap.Remove();
        }

    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
