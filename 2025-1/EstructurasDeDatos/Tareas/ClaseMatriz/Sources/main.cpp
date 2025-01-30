#include <iostream>

#include "../Headers/Matriz.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Matriz m1(3, 3);
    cout << m1 << endl;
 
    Matriz m2(3, 3);
    cout << m2 << endl;

    cout << m1 * 3;
    cout << endl;
    cout << 3 * m1;
    cout << endl;

    cout << m1 * m2;
    cout << endl;
    cout << m2 * m1;

    return 0;
}
