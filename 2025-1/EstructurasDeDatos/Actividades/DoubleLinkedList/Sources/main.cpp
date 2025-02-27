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
    int option, val, index;
    bool cont = true;

    while(cont)
    {
        try{
            ClearScreen();
            cout << "\n --- Opciones de agregacion ---";
            cout << "\n1. Agregar un elemento al inicio";
            cout << "\n2. Agregar un elemento al final";
            cout << "\n3. Agregar un elemento en cierta posicion";

            cout << "\n\n --- Opciones de eliminacion ---";
            cout << "\n4. Eliminar el primer elemento";
            cout << "\n5. Eliminar el ultimo elemento";
            cout << "\n6. Eliminar un elemento en cierta posicion";
            cout << "\n7. Eliminar un valor";
            cout << "\n8. Eliminar todos los valores";

            cout << "\n\n --- Funciones de obtencion ---";
            cout << "\n9. Obtener el primer elemento";
            cout << "\n10. Obtener el ultimo elemento";
            cout << "\n11. Obtener un elemento en cierta posicion";
            cout << "\n12. Obtener el indice de un elemento";
            cout << "\n13. Obtener el tamaño de la lista";
            cout << "\n14. Saber si la lista esta vacia";
            cout << "\n15. Imprimir la lista";

            cout << "\n\n16. Salir";

            cout << "\n\nElige una de las opciones anteriores:\n - ";
            option = CapturaSegura<>().LongitudCerrada(1, 15);

            ClearScreen();

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
                    cout << "\nIngresa la pocision donde deseas guardar el valor\n - ";
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
                    cout << "\nIngresa la pocision del valor que deseas eliminar\n - ";
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
                    cout << list.GetFirst();
                    break;

                case 10:
                    cout << list.GetLast();
                    break;

                case 11:
                    cout << "\n\nIngresa la posicion del valor que deseas\n - ";
                    index = CapturaSegura<>().LongitudSegura();
                    cout << list.GetAt(index);
                    break;

                case 12:
                    cout << "\n\nIngresa el valor a buscar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    cout << list.IndexOf(val);
                    break;

                case 13:
                    cout << list.Size();
                    break;

                case 14:
                    cout << (list.IsEmpty() ? "La lista esta vacia" : "La lista no esta vacia");
                    break;

                case 15:
                    cout << endl << list << endl;
                    break;

                case 16:
                    cont = false;
                    break;
            }
        }catch(const char *err){
            cerr << "Error: " << err << endl;
        }

        cout << "\n\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();
    }
}

void ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}
