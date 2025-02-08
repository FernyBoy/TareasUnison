/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#include <iostream>
#include <cstdlib>
#include <limits>

#include "../Headers/LinkedStack.hpp"
#include "../Headers/CapturaSegura.hpp"
#include "../Headers/Vector.hpp"
using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

bool VerificarLlaves(std::string cadena);
string CadenaSegura();

int main()
{
    try
    {
        cout << "\nIngresa la cadena a verificar:\n - ";
        string c = CadenaSegura();

        if(VerificarLlaves(c))
        {
            cout << "\nCadena perfectamente cerrada" << endl;
        }
        else
        {
            cout << "\nCadena incorrectamnete cerrada" << endl;
        }
    }catch(const char *err)
    {
        cerr << "Error: \t" << err << endl;
    }

    return 0;
}

bool VerificarLlaves(string cadena)
{
    LinkedStack<char> stack;
    
    for(int i = 0; i < (int)cadena.size(); ++i)
    {
        if(cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') stack.Push(cadena[i]);

        switch (cadena[i]) 
        {
            case ')':
                if(stack.IsEmpty() || stack.Top() != '(') return false;
                stack.Pop();
                break;

            case ']':
                if(stack.IsEmpty() || stack.Top() != '[') return false;
                stack.Pop();
                break;

            case '}':
                if(stack.IsEmpty() || stack.Top() != '{') return false;
                stack.Pop();
                break;
        }
    }

    return stack.IsEmpty();
}

string CadenaSegura()
{
    string cadena;
    cin >> cadena;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa una respuesta v\240lida.\n - ";
        cin >> cadena;
    }

    return cadena;
}
