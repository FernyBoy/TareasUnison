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
    ClearScreen();
    try{
        DoubleLinkedList<int> list;
        int option, val, index;

        while(true)
        {
            cout << "\n --- Opciones de agregacion ---";
            cout << "\n1. Agregar un elemento al inicio";
            cout << "\n2. Agregar un elemento al final";
            cout << "\n3. Agregar un elemento en cierta posicion";

            cout << "\n\n --- Opciones de eliminacion ---";
            cout << "\n4. Eliminar el primer elemento";
            cout << "\n5. Eliminar el ultimo elemento";
            cout << "\n6. Eliminar un elemento en cierta posicion";
            cout << "\n7. Eliminar un valor";

            cout << "\n\n --- Funciones de obtencion ---";
            cout << "\n8. Obtener el primer elemento";
            cout << "\n9. Obtener el ultimo element;";
            cout << "\n10. Obtener un elemento en cierta posicion";
            cout << "\n11. Obtener el indice de un elemento";
            cout << "\n12. Obtener el tamaño de la lista";
            cout << "\n13. Saber si la lista esta vacia";
            cout << "\n14. Imprimir la lista";

            cout << "\n\nElige una de las opciones anteriores:\n - ";
            option = CapturaSegura<>().LongitudCerrada(1, 14);

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
                    try{
                        cout << "\nIngresa la pocision donde deseas guardar el valor\n - ";
                        index = CapturaSegura<>().LongitudSegura();
                    
                        cout << "\n\nIngresa el valor a agregar\n - ";
                        val = CapturaSegura<>().LongitudSegura();
                        list.AddAt(val, index);
                    }catch(const char *e){
                        cerr << "Error:" << e << endl;
                    }
                    break;

                case 4:
                    list.RemoveFirst();
                    break;

                case 5:
                    list.RemoveLast();
                    break;

                case 6:
                    cout << "\nIngresa la pocision del valor que deseas eliminar\n - ";
                    index = CapturaSegura<>().LongitudCerrada(0, list.ListSize() - 1);
                    
                    list.RemoveAt(index);
                    break;

                case 7:
                    try{
                        cout << "\n\nIngresa el valor a eliminar\n - ";
                        val = CapturaSegura<>().LongitudSegura();
                        list.RemoveElement(val);
                    }catch(const char *e){
                        cerr << "Error:" << e << endl;
                    }
                    break;

                case 8:
                    cout << list.GetFirst();
                    break;

                case 9:
                    cout << list.GetLast();
                    break;

                case 10:
                    try{
                        cout << "\n\nIngresa la posicion del valor que deseas\n - ";
                        index = CapturaSegura<>().LongitudSegura();
                        list.GetAt(index);
                    }catch(const char *e){
                        cerr << "Error:" << e << endl;
                    }
                    break;

                case 11:
                    try{
                        cout << "\n\nIngresa el valor a buscar\n - ";
                        val = CapturaSegura<>().LongitudSegura();
                        list.IndexOf(val);
                    }catch(const char *e){
                        cerr << "Error:" << e << endl;
                    }
                    break;

                case 12:
                    cout << list.ListSize();
                    break;

                case 13:
                    cout << (list.IsEmpty() ? "La lista esta vacia" : "La lista no esta vacia");
                    break;

                case 14:
                    try{
                        list.PrintList();
                    }catch(const char *e){
                        cerr << "Error:" << e << endl;
                    }
                    break;


                std::cout << "\n\nPresiona Enter para continuar...";
                std::cin.get(); // Espera a que el usuario presione Enter
            }
        }

    }catch(const char *e){
        cerr << "Error:" << e << endl;
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
