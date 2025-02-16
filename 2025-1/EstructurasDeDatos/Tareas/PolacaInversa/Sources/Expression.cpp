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
    cout << "\nIngresa la expresi\242n a evaluar\n • ";

    while(true)
    {
        infixExpression = CapturaSegura<>().TextoPermitido(SymbolsList, SymbolsSize);
        
        if(ValidateBrackets(infixExpression)) break;

        cout << "\n S\241mbolos de cierre mal balanceados. Ingresa de nuevo to expresi\242n\n • ";
    }

    InfixToPostfix();
}

double Expression::EvaluateExpression()
{
    LinkedStack<double> stack;  // Pila para los operandos
    int index = 0;
    // Iteramos sobre cada carácter de la expresión posfija
    while(index < postfixExpression.size())
    {   
        char c = postfixExpression[index];
        if (isdigit(c)) {
            // Si el carácter es un número, construimos el número completo y lo agregamos a la pila
            std::string number = "";
            while (isdigit(c)) {
                number += c;  // Agregar el dígito al número
                c = postfixExpression[++index];  // Avanzar al siguiente carácter
            }
            stack.Push(std::stod(number));  // Convertir el número de string a double y lo empujamos a la pila
        }
        else if (c == ' ') {
            // Ignoramos los espacios
            continue;
        }
        else {
            // Si es un operador, sacamos los dos operandos de la pila
            double operand2 = stack.Top(); stack.Pop();
            double operand1 = stack.Top(); stack.Pop();

            double result = 0;

            // Realizamos la operación correspondiente
            switch (c) {
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
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        std::cerr << "Error: Division por cero!" << endl;
                        return -1;  // Error en la división por cero
                    }
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
            }

            // Colocamos el resultado en la pila
            stack.Push(result);
        }
    }

    // Al final, el resultado estará en la cima de la pila
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

