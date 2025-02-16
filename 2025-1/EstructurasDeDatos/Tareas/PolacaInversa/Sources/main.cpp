/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   15/02/2025
*/

#include <iostream>
#include "../Headers/Expression.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Expression newEx;
        newEx.CaptureExpression();
        cout << "\nExpresion infija" << endl;
        newEx.PrintExpression();
        cout << "\nExpresion postfija" << endl;
        newEx.PrintPostfixExpression();



    }catch(const char *err){
        cerr << "Error:" << endl;
    }
}
