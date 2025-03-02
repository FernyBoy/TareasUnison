/**
*   \file   main.cpp
*   \author 
*   \date   
*/

#include <iostream>
#include "../Headers/DoubleLinkedList.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

void ClearScreen();

int main()
{
    DoubleLinkedList<int> list;
    int option = 0, val, index;

    for(int i = 1; i < 6; ++i) list.AddLast(i * 5);

    while(option != 38)
    {
        try{
            ClearScreen();

            if(list.IsEmpty())
            {
                cout << "\n[ ]" << endl;
            }
            else if(!list.IsEmpty())
            {
                cout << endl << list << endl;
            }

            cout << "\n --- Opciones de agregacion ---";
            cout << "\n1.  Agregar un elemento al inicio";
            cout << "\n2.  Agregar un elemento al final";
            cout << "\n3.  Agregar un elemento en cierta posicion";
            cout << "\n4.  Concatenar con otra lista";

            cout << "\n\n --- Opciones de eliminacion ---";
            cout << "\n4.  Eliminar el primer elemento";
            cout << "\n5.  Eliminar el ultimo elemento";
            cout << "\n6.  Eliminar un elemento en cierta posicion";
            cout << "\n7.  Eliminar a partir de cierta posicion";
            cout << "\n8.  Eliminar a partir de un rango de posiciones";
            cout << "\n9.  Eliminar un valor";
            cout << "\n10. Eliminar los valores duplicados";
            cout << "\n11. Eliminar todos los valores iguales";
            cout << "\n12. Eliminar los valores que tambien esten en otra lista";
            cout << "\n13. Remover bajo cierta condicion";
            cout << "\n14. Limpiar la lista";

            cout << "\n\n --- Funciones de modificacion ---";
            cout << "\n15. Modificar un elemento en la lista";
            cout << "\n16. Clonar una lista";

            cout << "\n\n --- Funciones de transferencia ---";
            cout << "\n17. Intercambiar listas";
            cout << "\n18. Transferir todos los valores";
            cout << "\n19. Transferir todos los valores a partir de un indice";
            cout << "\n20. Transferir todos los valores entre dos indices";

            cout << "\n\n --- Funciones de conjuntos ---";
            cout << "\n21. Union de listas";
            cout << "\n22. Interseccion de listas";
            cout << "\n23. Diferencia de listas";
            cout << "\n24. Diferencia simetrica de listas";

            cout << "\n\n --- Funciones de ordenamiento ---";
            cout << "\n25. Invertir lista";
            cout << "\n26. Ordenar de forma ascendente";
            cout << "\n27. Ordenar de forma descendente";

            cout << "\n\n --- Funciones de obtencion ---";
            cout << "\n28. Obtener el primer elemento";
            cout << "\n29. Obtener el ultimo elemento";
            cout << "\n30. Obtener un elemento en cierta posicion";
            cout << "\n31. Buscar si un elemento se encuentra en la lista";
            cout << "\n32. Obtener el indice de un elemento";
            cout << "\n33. Obtener el tamaño de la lista";
            cout << "\n34. Saber si la lista esta vacia";

            cout << "\n\n --- Funciones de comparacion ---";
            cout << "\n35. Comparar si la lista es subconjunto de otra";
            cout << "\n36. Comparar si la lista es superconjunto de otra";
            cout << "\n37. Comparar si dos listas son iguales";

            cout << "\n\n --- Funcinoes de impresion ---";
            cout << "\n38. Imprimir lista";
            cout << "\n39. Imprimir lista al reves";

            cout << "\n\n40. Salir";

            cout << "\n\nElige una de las opciones anteriores:\n - ";
            option = CapturaSegura<>().LongitudCerrada(1, 38);

            ClearScreen();
            if(list.IsEmpty())
            {
                cout << "\n[ ]" << endl;
            }
            else if(!list.IsEmpty())
            {
                cout << endl << list << endl;
            }

            switch (option) 
            {
                case 1:
                    cout << "\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    list.AddFirst(val);
                    break;

                case 2:
                    cout << "\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    list.AddLast(val);
                    break;
                
                case 3:
                    cout << "\nIngresa la posicion donde deseas guardar el valor\n - ";
                    index = CapturaSegura<>().LongitudSegura();
                    
                    cout << "\n\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    list.AddAt(val, index);
                    break;

                case 4:
                    list.RemoveFirst();
                    break;

                case 5:
                    list.RemoveLast();
                    break;

                case 6:
                    cout << "\nIngresa la posicion del valor que deseas eliminar\n - ";
                    index = CapturaSegura<>().LongitudSegura();
                    
                    list.RemoveAt(index);
                    break;

                case 7:
                    cout << "\n\nIngresa el valor a eliminar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    list.RemoveElement(val);
                    break;

                case 8:
                    list.Clear();
                    break;

                case 9:
                    cout << "\nPrimer elemento: " << list.GetFirst() << endl;
                    break;

                case 10:
                    cout << "\nUltimo elemento: " << list.GetLast() << endl;
                    break;

                case 11:
                    cout << "\n\nIngresa la posicion del valor que deseas\n - ";
                    index = CapturaSegura<>().LongitudSegura();
                    cout << "\nElemento en posicion " << index << ": " << list.GetAt(index) << endl;
                    break;

                case 12:
                    cout << "\n\nIngresa el valor a buscar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    cout << "\nIndice de " << val << ": " << list.IndexOf(val) << endl;
                    break;

                case 13:
                    cout << "\nTamaño de la lista: " << list.Size() << endl;
                    break;

                case 14:
                    cout << (list.IsEmpty() ? "\n\nLa lista esta vacía" : "\n\nLa lista no esta vacía");
                    break;
            }
        }catch(const char *err){
            cerr << "\nError: " << err << endl;
            cout << "\n\nPresiona enter para continuar";
            cin.ignore();
            cin.get();
        }

        if(option >= 9 && option != 15)
        {
            cout << "\n\nPresiona enter para continuar";
            cin.ignore();
            cin.get();
        }
    }

    ClearScreen();
}

void ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}
