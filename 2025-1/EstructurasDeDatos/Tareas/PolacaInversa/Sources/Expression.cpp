/**
*   \file   Expression.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   15/02/2025
*/

#include "../Headers/Expression.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
Expression::Expression() : infixExpression(""), isEvaluable(false), postfixExpression("") {}
/*
Expression::Expression(const std::string e)
{
    
}

Expression::Expression(const Expression &e)
{
    
}

Expression & Expression::operator=(const Expression &e)
{
    
}
*/
// ----------------------
// ----- Destructor -----
// ----------------------
Expression::~Expression()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
void Expression::CaptureExpression()
{
    cout << "\nIngresa la expresi\242n a evaluar\n - ";

    while(true)
    {
        infixExpression = CapturaSegura<>().TextoPermitido(SymbolsList, SymbolsSize);
        
        if(ValidateBrackets(infixExpression)) break;

        cout << "\n S\241mbolos de cierre mal balanceados. Ingresa de nuevo to expresi\242n\n • ";
    }
}

double Expression::EvaluateExpression()
{
    return 0; 
}

void Expression::PrintExpression()
{
    cout << infixExpression;
}

void Expression::PrintPostfixExpression()
{
    cout << postfixExpression;
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
string Expression::InfixToPostfix()
{
    return "";
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
bool Expression::ValidateBrackets(const string &e)
{
    LinkedStack<char> stack;
    
    for(int i = 0; i < (int)e.size(); ++i)
    {
        if(e[i] == '(' || e[i] == '[' || e[i] == '{') stack.Push(e[i]);

        switch (e[i]) 
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

bool Expression::IsValidExpression()
{
    return false;
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------

