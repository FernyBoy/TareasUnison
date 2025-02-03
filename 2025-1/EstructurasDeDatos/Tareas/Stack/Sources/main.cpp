#include <iostream>

#include "../Headers/Stack.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Stack<std::string, 5> stack1;
        
        cout << "Está vacío: " << stack1.IsEmpty();
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity() << "\n\n";

        /*
        for(int i = 0; i <= cap; ++i)
        {
            stack1.Push((i + 1) * 2);
        }
        cout << stack1;
        */

        stack1.Push("Fernando");
        stack1.Push("Javier");
        stack1.Push("Victor");
        stack1.Push("Verdelias");
        stack1.Push("Eivor");
        stack1.Push("Ivanna");
        cout << stack1;

        cout << "\nEstá vacía: " << stack1.IsEmpty(); 
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: " << stack1.Top();

        stack1.Pop();
        cout << "\nÚltimo elemento borrado.";
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: " << stack1.Top();
        cout << endl << endl << stack1;

        stack1.ClearStack();
        cout << "\nPila borrada.";
        cout << "\nEstá vacía: " << stack1.IsEmpty(); 
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: " << stack1.Top();
        cout << "\n-----------------------------";
        cout << endl << stack1;
        cout << "\n-----------------------------";

    }catch(const char *err)
    {
        cerr << "Error: " << err << endl;
    }
    return 0;
}
