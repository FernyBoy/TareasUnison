#include <iostream>

#include "../Headers/Stack.hpp"
#include "../Headers/Vector.hpp"
#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Stack<Matriz, 3> stack1;
        
        /*
        for(int i = 1; i < 12; ++i)
        {
            Vector v(i, i*3);
            stack1.Push(v);
        }
        */

        cout << "Está vacía: " << stack1.IsEmpty();
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity() << "\n\n";        
        cout << stack1 << endl;

        cout << "\nEstá vacía: " << stack1.IsEmpty(); 
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: \n" << stack1.Top();

        stack1.Pop();
        cout << "\n\nÚltimo elemento borrado.";
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: \n" << stack1.Top();
        cout << endl << endl << stack1;

        stack1.ClearStack();
        cout << "\n\nPila borrada.";
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
