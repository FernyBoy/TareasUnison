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

Expression::Expression(string e)
{   
    cout << e;
    for (char c : e) 
    {
        if (!(std::find(SymbolsList, SymbolsList + SymbolsSize, c) != SymbolsList + SymbolsSize)) 
        {
            string err = "\nError: El car\240cter '" + string(1, c) + "' no est\240 permitido.";
            throw err;
        }
    }

    if(!ValidateBrackets(e)) throw "\n S\241mbolos de cierre mal balanceados. Ingresa de nuevo to expresi\242n\n • ";

    infixExpression = e;

    InfixToPostfix();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
void Expression::CaptureExpression()
{
    while(true)
    {
        infixExpression = CapturaSegura<>().TextoPermitido(SymbolsList, SymbolsSize);
        
        if(ValidateBrackets(infixExpression)) break;

        cout << "\n S\241mbolos de cierre mal balanceados. Ingresa de nuevo tu expresi\242n\n • ";
    }

    InfixToPostfix();
}

double Expression::EvaluateExpression()
{
    LinkedStack<double> stack;

    size_t index = 0;

    while (index < postfixExpression.size()) 
    {
        char c = postfixExpression[index];

        if (isdigit(c)) 
        {
            std::string number = "";

            while (index < postfixExpression.size() && isdigit(postfixExpression[index])) 
            {
                number += postfixExpression[index++];
            }

            stack.Push(std::stod(number));
        }
        else if (c == ' ') 
        {
            ++index;
            continue;
        }
        else 
        {
            double operand2 = stack.Top(); stack.Pop();
            double operand1 = stack.Top(); stack.Pop();

            double result = 0;

            switch (c) 
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;
                    
                case '/':
                    if (operand2 != 0) 
                    {
                        result = operand1 / operand2;
                    } 
                    else 
                    {
                        throw "Division por cero!";
                    }
                    break;

                case '^':
                    result = pow(operand1, operand2);
                    break;
            }

            stack.Push(result);
        }

        ++index;
    }

    return stack.Top();
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
void Expression::InfixToPostfix()
{
    LinkedStack<char> stack;
    std::string currentNumber = "";

    for (char c : infixExpression) 
    {
        if (isdigit(c)) 
        {
            currentNumber += c;
        }
        else 
        {
            if (!currentNumber.empty())     
            {
                postfixExpression += currentNumber;
                postfixExpression += ' ';
                currentNumber = "";
            }

            if (c == '(' || c == '[' || c == '{') 
            {
                stack.Push(c);
            }
            else if (c == ')' || c == ']' || c == '}') 
            {
                char openingBracket = (c == ')') ? '(' : (c == ']') ? '[' : '{';
                
                while (!stack.IsEmpty() && stack.Top() != openingBracket) 
                {
                    postfixExpression += stack.Top();
                    postfixExpression += ' ';
                    stack.Pop();
                }

                if (!stack.IsEmpty() && stack.Top() == openingBracket) 
                {
                    stack.Pop();
                }
            }
            else if (PrecedenceMap.find(c) != PrecedenceMap.end()) 
            {
                while (!stack.IsEmpty() && PrecedenceMap.at(stack.Top()) >= PrecedenceMap.at(c)) 
                {
                    postfixExpression += stack.Top();
                    postfixExpression += ' ';
                    stack.Pop();
                }

                stack.Push(c);
            }
        }
    }

    if (!currentNumber.empty()) 
    {
        postfixExpression += currentNumber;
        postfixExpression += ' ';
    }

    while (!stack.IsEmpty()) 
    {
        postfixExpression += stack.Top();
        postfixExpression += ' ';
        stack.Pop();
    }
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

