/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   23/02/2025
*/

#include "../Headers/Client.hpp"
#include <cctype>
#include <cstdlib>

unsigned Client::listNumber = 0;
vector<DoubleLinkedList<int>> Client::lists = {};
DoubleLinkedList<int>* Client::selectedList = nullptr;

bool IsEven(int x) { return x % 2 == 0; }


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Método para comenzar la simulación ---
//
// --------------------------------------------
void Client::RunService()
{
    DoubleLinkedList<int> list1, list2;
    for(int i = 0; i < 10; ++i)
    {
        list1.AddLast(i + 1);
        list2.AddLast((i + 1) * 2);
    }
    lists.push_back(list1);
    lists.push_back(list2);

    ClearScreen();

    MainMenu();

    SystemPause();
    ClearScreen();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de modificación de atributos--
//
// --------------------------------------------


// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de impresión -----------------
//
// --------------------------------------------
// ------------------------------
// --- Funciones de templates ---
// ------------------------------
void Client::MainMenuTemplate()
{
    PrintSelectedList();
    cout << "\n\n";
    cout << "\n1.   Crear una nueva lista";
    cout << "\n2.   Eliminar una lista";
    cout << "\n3.   Seleccionar lista";
    cout << "\n4.   Editar la lista seleccionada";
    cout << "\n\n5.   Salir";
}

void Client::EditMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Agregar";
    cout << "\n2.   Eliminar";
    cout << "\n3.   Modificar";
    cout << "\n4.   Transferir los valores a otra lista";
    cout << "\n5.   Funciones de conjuntos";
    cout << "\n6.   Ordenar valores";
    cout << "\n7.   Consultar valores de la lista";
    cout << "\n8.   Imprimir listas";

    cout << "\n\n9.   Regresar al menu anterior";
}

void Client::AddMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Agregar un valor al inicio";
    cout << "\n2.   Agregar un valor al final";
    cout << "\n3.   Agregar un valor en una posicion especifica";
    cout << "\n4.   Concatenar con una lista";

    cout << "\n\n5.   Regresar al menu anterior";
}
void Client::RemoveMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Eliminar el primer valor";
    cout << "\n2.   Eliminar el ultimo valor";
    cout << "\n3.   Eliminar un valor en una posicion especifica";
    cout << "\n4.   Eliminar a partir de cierta posicion";
    cout << "\n5.   Eliminar a partir de un rango de posiciones";
    cout << "\n6.   Eliminar un valor";
    cout << "\n7.   Eliminar valores duplicados";
    cout << "\n8.   Eliminar todos los valores iguales";
    cout << "\n9.   Eliminar los valores que tambien esten en otra lista";
    cout << "\n10.  Remover bajo cierta condicion";
    cout << "\n11.  Limpiar la lista";

    cout << "\n\n12.  Regresar al menu anterior";
}

void Client::ModificationMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Modificar un valor";
    cout << "\n2.   Clonar a partir de otra lista";

    cout << "\n\n3.   Regresar al menu anterior";
}

void Client::TransferMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Intercambiar valores con otra lista";
    cout << "\n2.   Transferir todos los valores a otra lista";
    cout << "\n3.   Transferir todos los valores a partir de una posicion";
    cout << "\n4.   Transferir todos los valores a partir de un rango";

    cout << "\n\n5.   Regresar al menu anterior";
}

void Client::SetsMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Union";
    cout << "\n2.   Interseccion";
    cout << "\n3.   Diferencia";

    cout << "\n\n4.   Regresar al menu anterior";
}

void Client::SortMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Invertir lista";
    cout << "\n2.   Ordenar de forma ascendente";
    cout << "\n3.   Ordenar de forma descendente";

    cout << "\n\n4.   Regresar al menu anterior";
}
    
void Client::GetMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Consultar el primer valor";
    cout << "\n2.   Consultar el ultimo valor";
    cout << "\n3.   Consultar un valor en una posicion especifica";
    cout << "\n4.   Consultar los valores a partir de una posicion";
    cout << "\n5.   Consultar los valores dentro de un rango";
    cout << "\n6.   Consultar si un valor se encuentra en la lista";
    cout << "\n7.   Consultar el indice de un valor";
    cout << "\n8.   Consultar el tamaño de la lista";
    cout << "\n9.   Consultar si la lista esta vacia";

    cout << "\n\n10.  Regresar al menu anterior";
}

/*
void Client::CompareMenuTemplate()
{
    PrintSelectedList();

    cout << "\n\n";
    cout << "\n1.   Comparar si la lista es subconjunto de otra";
    cout << "\n2.   Comparar si la lista es superconjunto de otra";
    cout << "\n3.   Comparar si la lista es igual a otra";

    cout << "\n\n4.   Regresar al menu anterior";
}
*/
        
void Client::PrintMenuTemplate()
{
    cout << "\n\n";
    cout << "\n1.   Imprimir lista al reves";
    cout << "\n2.   Imprimir otra lista";
    cout << "\n3.   Imprimir todas las listas";

    cout << "\n\n4.   Regresar al menu anterior";
}


// --------------------------
// --- Funciones de menus ---
// --------------------------
void Client::MainMenu()
{
    unsigned opt = 0, index;

    while(opt != 5)
    {
        ClearScreen();
        MainMenuTemplate();
        opt = GetOption(1, 5);
        
        try{
            switch(opt)
            {
                case 1: // Crear una lista
                {
                    DoubleLinkedList<int> newList;
                    lists.push_back(newList);
                    listNumber = lists.size();
                    selectedList = &lists[lists.size() - 1];
                    AddMenu();
                    break;
                }

                case 2: // Eliminar una lista
                {
                    ClearScreen();

                    if(!lists.empty())
                    {
                        PrintAllLists();

                        cout << "\nSelecciona la lista que deseas eliminar\n - ";
                        index = CapturaSegura<unsigned>().LongitudSegura();

                        if(!IsValidIndex(index - 1)) throw "\326ndice inv\240lido";

                        if(index == listNumber) selectedList = nullptr;

                        lists.erase(lists.begin() + index - 1);
                    }
                    break;
                }

                case 3: // Seleccionar una lista
                    ClearScreen();

                    if(!lists.empty())
                    {
                        PrintAllLists();
                        cout << "\n\nSelecciona la lista que deseas\n - ";
                        index = CapturaSegura<>().LongitudSegura();
                        if(IsValidIndex(index - 1))
                        {
                            listNumber = index;
                            selectedList = &lists[listNumber - 1];
                        }
                        else
                        {
                            throw "\326ndice inv\240lido";
                        }
                    }
                    break;

                case 4: // Editar la lista seleccionada
                    ClearScreen();

                    if(CheckSelectedList())
                    {
                        EditMenu();
                    }
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::EditMenu()
{
    unsigned opt = 0;

    while(opt != 9)
    {
        ClearScreen();
        EditMenuTemplate();
        opt = GetOption(1, 9);
        
        switch (opt) 
        {
            case 1: // Agregar
                AddMenu();
                break;
            
            case 2: // Eliminar
                RemoveMenu();
                break;

            case 3: // Modificar
                ModificationMenu();
                break;

            case 4: // Transferir
                TransferMenu();
                break;

            case 5: // Conjuntos
                SetsMenu();
                break;

            case 6: // Ordenamiento
                SortMenu();
                break;

            case 7: // Consulta
                GetMenu();
                break;

            case 8: // Impresión
                PrintMenu();
                break;
        }
    }
}

void Client::AddMenu()
{
    unsigned opt = 0, val, index;

    while(opt != 5)
    {
        ClearScreen();
        AddMenuTemplate();
        opt = GetOption(1, 5);

        try{
            switch(opt) 
            {
                case 1: // Agregar al inicio
                    cout << "\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    selectedList -> AddFirst(val);
                    break;

                case 2: // Agregar al final
                    cout << "\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    selectedList -> AddLast(val);
                    break;
                
                case 3: // Agregar en posición
                    cout << "\nIngresa la posicion donde deseas guardar el valor\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    cout << "\n\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    selectedList -> AddAt(val, index);
                    break;

                case 4: // Concatenar
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas concatenar\n - ";
                    selectedList -> Concat(lists[SelectOtherList()]);
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::RemoveMenu()
{
    unsigned opt = 0, val, index, endIndex;

    while(opt != 12)
    {
        ClearScreen();
        RemoveMenuTemplate();
        opt = GetOption(1, 12);

        try{
            switch(opt) 
            {
                case 1: // Eliminar el primero
                    selectedList -> RemoveFirst();
                    break;

                case 2: // Eliminar el último
                    selectedList -> RemoveLast();
                    break;
                
                case 3: // Eliminar una posición
                    cout << "\nIngresa la posicion del valor que deseas eliminar\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    selectedList -> RemoveAt(index);
                    break;

                case 4: // Eliminar a partir de una posición
                    cout << "\nIngresa la posición inicial\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    selectedList -> RemoveFrom(index);
                    break;
                
                case 5: // Eliminar rango
                    cout << "\nIngresa la posición inicial\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    cout << "\nIngresa la posición final\n - ";
                    endIndex = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    selectedList -> RemoveRange(index, endIndex);
                    break;

                case 6: // Eliminar valor
                    cout << "\nIngresa el valor que deseas eliminar\n - ";
                    val = CapturaSegura<>().LongitudSegura();

                    selectedList -> RemoveElement(val);
                    break;

                case 7: // Eliminar duplicados
                    selectedList -> RemoveDuplicates();
                    break;

                case 8: // Eliminar iguales
                    cout << "\nIngresa el valor que deseas eliminar junto a sus copias\n - ";
                    val = CapturaSegura<>().LongitudSegura();
        
                    selectedList -> RemoveAllElements(val);
                    break;

                case 9: // Eliminar valores que también estén en otra lista
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas remover sus concurrencias\n - ";
                    selectedList -> RemoveMatching(lists[SelectOtherList()]);
                    break;

                case 10: // Remover bajo cierta condición
                {
                    bool (*func)(int) = IsEven;
                    selectedList -> RemoveIf(func);
                    break;
                }

                case 11: // Limpiar la lista
                    selectedList -> Clear();
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::ModificationMenu()
{
    unsigned opt = 0, val, index;

    while(opt != 3)
    {
        ClearScreen();
        ModificationMenuTemplate();
        opt = GetOption(1, 3);

        try{
            switch(opt) 
            {
                case 1: // Modificar un valor
                    cout << "\nIngresa la posición que deseas modificar\n - ";
                    index = CapturaSegura<>().LongitudSegura() - 1;

                    cout << "\nIngresa el valor a agregar\n - ";
                    val = CapturaSegura<>().LongitudSegura();
                    selectedList[index] = val;
                    selectedList->SetAt(index, val);
                    break;

                case 2: // Clonar
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas clonar\n - ";
                    selectedList -> Clone(lists[SelectOtherList()]);
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::TransferMenu()
{
    unsigned opt = 0, index, endIndex;

    while(opt != 5)
    {
        ClearScreen();
        TransferMenuTemplate();
        opt = GetOption(1, 5);

        try{
            switch(opt) 
            {
                case 1: // Intercambiar valores
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas clonar\n - ";
                    selectedList -> Swap(lists[SelectOtherList()]);
                    break;

                case 2: // Transferir todos los datos
                    PrintAllLists();
                    cout << "\nSelecciona la lista a la que deseas transferir los datos\n - ";
                    selectedList -> TransferAll(lists[SelectOtherList()]);
                    break;

                case 3: // Transferir a partir de un indice
                    cout << "\nIngresa la posición inicial\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;

                    PrintAllLists();
                    cout << "\nSelecciona la lista a la que deseas transferir los datos\n - ";
                    selectedList -> TransferFrom(index, lists[SelectOtherList()]);
                    break;

                case 4: // Transferir a partir de un rango
                {
                    cout << "\nIngresa la posición inicial\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    cout << "\nIngresa la posición final\n - ";
                    endIndex = CapturaSegura<unsigned>().LongitudSegura() - 1;

                    PrintAllLists();
                    cout << "\nSelecciona la lista a la que deseas transferir los datos\n - ";
                    selectedList -> TransferRange(index, endIndex, lists[SelectOtherList()]);
                    break;
                }
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::SetsMenu()
{
    unsigned opt = 0, answer = 0;
    DoubleLinkedList<int> auxList;

    while(opt != 4)
    {
        ClearScreen();
        SetsMenuTemplate();
        opt = GetOption(1, 4);

        try{
            switch(opt) 
            {
                case 1: // Union
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas unir\n - ";
                    auxList = selectedList -> Union(lists[SelectOtherList()]);
                    cout << "\n - Unión - \n\n" << auxList;
                    break;

                case 2: // Intersección
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas intersectar\n - ";
                    auxList = selectedList -> Intersection(lists[SelectOtherList()]);
                    cout << "\n - Intersección - \n\n" << auxList;
                    break;

                case 3: // Diferencia
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas eliminar sus concurrencias\n - ";
                    auxList = selectedList -> Difference(lists[SelectOtherList()]);
                    cout << "\n - Diferencia - \n\n" << auxList;
                    break;
                /*
                case 4: // Diferencia simétrica
                    PrintAllLists();
                    cout << "\nSelecciona la lista que deseas su diferencia simétrica\n - ";
                    auxList = selectedList -> SymmetricDifference(lists[SelectOtherList()]);
                    cout << "\n - Diferencia simétrica - \n\n" << auxList;
                    break;
                */
            }
            PrintDivision();
            cout << "\n¿Deseas guardar la lista creada?\n1. Si\n2. No\n - ";
            answer = CapturaSegura<unsigned>().LongitudCerrada(1, 2);
            if(answer == 1)
            {
                lists.push_back(auxList);
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::SortMenu()
{
    unsigned opt = 0;

    while(opt != 4)
    {
        ClearScreen();
        SortMenuTemplate();
        opt = GetOption(1, 4);

        try{
            switch(opt) 
            {
                case 1: // Invertir
                    selectedList -> Reverse();
                    break;

                case 2: // Ascendente
                    selectedList -> SortAscending();
                    break;

                case 3: // Descendente
                    selectedList -> SortDescending();
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

void Client::GetMenu()
{
    unsigned opt = 0, val, index, endIndex;

    while(opt != 10)
    {
        ClearScreen();
        GetMenuTemplate();
        opt = GetOption(1, 10);

        try{
            switch(opt) 
            {
                case 1: // Primero
                    cout << "\nPrimer valor: " << selectedList -> GetFirst();
                    break;

                case 2: // Último
                    cout << "\nÚltimo valor: " << selectedList -> GetLast();
                    break;

                case 3: // Consultar una posición
                    cout << "\nIngresa la posición que deseas consultar\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    cout << "\n\nValor en la posici\242n " << index + 1 << ": " << selectedList -> GetAt(index);
                    break;

                case 4: // Consultar a partir de una posición
                    cout << "\nIngresa la posición inicial\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;

                    cout << "\n\nValores a partir de la posición " << index + 1 << ": ";
                    (selectedList -> GetFrom(index)).Print();;
                    break;

                case 5: // Consultar un rango
                    cout << "\nIngresa la posición inicial\n - ";
                    index = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
                    cout << "\nIngresa la posición final\n - ";
                    endIndex = CapturaSegura<unsigned>().LongitudSegura() - 1;

                    cout << "\n\nValores de la posici\242n " << index + 1 << " a la posici\242n " << endIndex + 1 << ": ";
                    (selectedList -> GetRange(index, endIndex)).Print();
                    break;

                case 6: // Consultar si un valor está en la lista
                    cout << "\nIngresa el valor que deseas consultar\n - ";
                    val = CapturaSegura<>().LongitudSegura();

                    cout << (selectedList->Contains(val) ? "\n\nEl valor se encuentra en la lista" : "\n\nEl valor no se encuentra en la lista");
                    break;

                case 7: // Consultar índice
                    cout << "\nIngresa el valor que deseas consultar\n - ";
                    val = CapturaSegura<>().LongitudSegura();

                    cout << "\n\nValor " << val << " con \241ndice " << selectedList->IndexOf(val) + 1;
                    break;

                case 8: // Consultar el tamaño de la lista
                    cout << "\nTama\244o de la lista: " << selectedList -> Size();
                    break;

                case 9: // Consultar si la lista está vacía
                    cout << (selectedList -> IsEmpty() ? "\n\nLa lista est\240 vac\241a" : "\n\nLa lista no est\240 vac\241a");
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}

/*
void Client::CompareMenu()
{
    unsigned opt = 0, index;

    while(opt != 4)
    {
        ClearScreen();
        CompareMenuTemplate();
        opt = GetOption(1, 4);

        try{
            switch(opt) 
            {
                case 1: // Subconjunto
                    cout << "\nSelecciona la lista a la que deseas comparar\n - ";
                    index = SelectOtherList();
                    if(selectedList -> IsSubsetOf(lists[index]))
                    {
                        cout << "\nLa lista " << listNumber << " es subconjunto de la lista " << index;
                    }
                    else
                    {
                        cout << "\nLa lista " << listNumber << " no es subconjunto de la lista " << index;
                    }
                    break;

                case 2: // Superconjunto
                    cout << "\nSelecciona la lista a la que deseas comparar\n - ";
                    index = SelectOtherList();
                    if(selectedList -> IsSubsetOf(lists[index]))
                    {
                        cout << "\nLa lista " << listNumber << " es superconjunto de la lista " << index;
                    }
                    else
                    {
                        cout << "\nLa lista " << listNumber << " no es superconjunto de la lista " << index;
                    }
                    break;

                case 3: // Igualdad
                    cout << "\nSelecciona la lista a la que deseas comparar\n - ";
                    index = SelectOtherList();
                    if(selectedList -> IsSubsetOf(lists[index]))
                    {
                        cout << "\nLa lista " << listNumber << " es igual a lista " << index;
                    }
                    else
                    {
                        cout << "\nLa lista " << listNumber << " no es igual a la lista " << index;
                    }
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}
*/

void Client::PrintMenu()
{
    unsigned opt = 0;
    DoubleLinkedList<int> auxList;

    while(opt != 4)
    {
        ClearScreen();
        PrintMenuTemplate();
        opt = GetOption(1, 4);

        try{
            switch(opt) 
            {
                case 1: // Imprimir al reves
                    selectedList -> PrintReverse();
                    PressEnter();
                    break;

                case 2: // Imprimir de forma ascendente
                    auxList = lists[listNumber - 1];
                    auxList.SortAscending();
                    cout << auxList;
                    PressEnter();
                    break;

                case 3: // Imprimir de forma descendiente
                    auxList = lists[listNumber - 1];
                    auxList.SortDescending();
                    cout << auxList;
                    PressEnter();
                    break;
            }
        }catch(const char *err){
            ClearScreen();
            cout << "\nError: " << err;
            PressEnter();
        }
    }
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
unsigned Client::GetOption(unsigned start, unsigned end)
{
    PrintDivision();

    unsigned opt;

    cout << "\nIngresa una de las opciones anteriores\n - ";
    opt = CapturaSegura<unsigned>().LongitudCerrada(start, end);

    return opt;
}

unsigned Client::SelectOtherList()
{
    if(lists.size() == 1) throw "\nNo cuentas con suficientes listas para poder realzar esta accion";

    unsigned otherList;
    otherList = CapturaSegura<unsigned>().LongitudSegura() - 1;
                    
    if(!IsValidIndex(otherList)) throw "\nRespuesta invalida";
    
    return otherList;
}

void Client::PrintDivision()
{
    cout << "\n\n";
    for(int i = 0; i < 60; ++i)
    {
        cout << "-";
    }
}

void Client::PrintSelectedList()
{
    if(CheckSelectedList())
    {
        cout << endl << "\nLista " << listNumber << " seleccionada: ";

        try{
            cout << lists[listNumber - 1];
        }catch(const char *err){
            cout << "[ ]";
        }
    }

    PrintDivision();
}

void Client::PrintAllLists()
{
    for(unsigned i = 0; i < lists.size(); ++i)
    {
        cout << "\n\nLista " << i + 1 << ": ";
        try{
            lists[i].Print();
        }catch(const char *err){
            cout << "[ ]";
        }
    }

    PrintDivision();
}

bool Client::CheckSelectedList()
{
    PrintDivision();
    if(lists.size() == 0)
    {
        cout << "\n\nActualmente no tienes listas creadas";
        return false;
    }
    else if (selectedList == nullptr) 
    {
        cout << "\n\nActualmente no tienes una lista seleccionada";
        return false;
    }

    return true;
}

bool Client::IsValidIndex(unsigned index)
{
    return index < lists.size();
}

void Client::PressEnter()
{
    cout << "\n\nPresiona enter para continuar";
    cin.ignore();
    cin.get();
}

void Client::ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

void Client::SystemPause()
{
    #ifdef _WIN32
        system("pause");
    #endif
}
