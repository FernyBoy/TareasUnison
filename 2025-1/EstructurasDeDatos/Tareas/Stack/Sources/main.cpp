#include <iostream>

#include "../Headers/Stack.hpp"
#include "../Headers/Vector.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Stack<Vector, 5> stack1;
      
        /*
        Vector v1(3, 1);
        Vector v2(5, 3);
        Vector v3(6, 2);
        */

        for(int i = 1; i < 12; ++i)
        {
            Vector v(i, i*3);
            stack1.Push(v);
        }

        cout << "Está vacío: " << stack1.IsEmpty();
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity() << "\n\n";

        cout << "\nEstá vacía: " << stack1.IsEmpty(); 
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: " << stack1.Top();

        stack1.Pop();
        cout << "\n\nÚltimo elemento borrado.";
        cout << "\nCapacidad usada: " << stack1.UsedCapacity();
        cout << "\nCapacidad actual: " << stack1.Capacity();
        cout << "\nTope: " << stack1.Top();
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
