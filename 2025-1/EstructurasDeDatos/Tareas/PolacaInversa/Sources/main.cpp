/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   15/02/2025
*/

#include <cctype>
#include <iostream>
#include "../Headers/Expression.hpp"
#include "../Headers/CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        char respuestas[4] = {'C', 'c', 'S', 's'};
        string res;
        Expression exp;

        while(true)
        {
            cout << "\n\nIngresa alguna de las siguientes opciones:";
            cout << "\nC: Capturar una expresi\242n";
            cout << "\nS: Salir\n • ";
            
            res = CapturaSegura<>().TextoPermitido(respuestas, 4);

            if(res == "c" || res == "C")
            {
                cout << "\nIngresa la expresi\242n a evaluar\n • ";
                exp.CaptureExpression();

                cout << "\nExpresi\242n infija:\t";
                exp.PrintExpression();

                cout << "\nExpresi\242n posfija:\t";
                exp.PrintPostfixExpression();

                cout << "\nResultdado:\t\t";
                cout << exp.EvaluateExpression();
            }
            else
            {
                break;
            }
        }

    }catch(const char *err){
        cerr << "Error:" << endl;
    }
}
