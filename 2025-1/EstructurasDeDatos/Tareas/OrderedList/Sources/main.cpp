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
        OrderedList<int> newList, secondList;
        DoubleLinkedList<int> list1, list2;

        for(int i = 0; i < 10; ++i)
        {
            newList.Add(pow(-1, i) * (i + 1));
            list1.AddLast(pow(-1, i) * (i + 1) * 10);
            list2.AddLast(pow(-1, i) * (i + 1) * 100);
        }
        
        cout << "\nLista actual: " << newList;
        cout << "\nLista en orden inverso: ";
        newList.PrintReverse();
        cout << "\nLista sin elementos: " << (newList.Empty() ? "Verdadero" : "Falso");
        cout << "\nCantidad de elementos: " << newList.Size();
 

        cout << "\n\nIngresa un valor para agregarlo en la lista\n - ";
        newList.Add(CapturaSegura<>().LongitudSegura());
        cout << "Lista actualizada: " << newList;
        

        cout << "\n\nIngresa un valor para eliminarlo de la lista\n - ";
        try{ newList.Remove(CapturaSegura<>().LongitudSegura()); } 
        catch(const char *e){ cerr << "Error: " << e << endl; }
        cout << "Lista actualizada: " << newList;


        cout << "\n\nIngresa un elemento para verificar si se encuentra en la lista\n - ";
        cout << (newList.Contains(CapturaSegura<>().LongitudSegura()) ? "El valor se encuentra en la lista" : "El valor no se encuentra en la lista");


        cout << "\n\nSe ha limpiado la lista: ";
        newList.Clear();
        if(newList.Empty()) cout << "[ ]";

        cout << "\n\n\n--- Listas desordenadas auxiliares ---";
        cout << "\nLista desordenada 1: "<< list1;
        cout << "\nLista desordenada 2: "<< list2;
        secondList.MixLists(list1, list2);
        cout << "\nMezcla de ambas listas: " << secondList << endl;
        
    }catch(const char *e){
        cerr << "Error: " << e << endl;
    }

    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}
