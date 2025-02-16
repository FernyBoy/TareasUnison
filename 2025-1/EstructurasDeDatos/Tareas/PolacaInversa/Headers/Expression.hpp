/**
*   \file   Expression.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   15/02/2025
*/
#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include "CapturaSegura.hpp"
#include "LinkedStack.hpp"

#include <iostream>
#include <ostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

const char SymbolsList[] = 
{ 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    '.', '+', '-', '*', '/', '^', 
    '{', '}', '(', ')', '[', ']'
};

const unsigned SymbolsSize = 22;

using std::string;

class Expression
{
    // --- Métodos externos
    friend std::ostream& operator<<(std::ostream& output, const Expression& e);
    friend std::istream& operator>>(std::istream& input, Expression& e);

    public:
        // --- Constructores
        explicit Expression();
        explicit Expression(const std::string e);
        Expression(const Expression &e);
        Expression & operator=(const Expression &e);

        // --- Destructor
        ~Expression();

        // --- Métodos públicos
        void    CaptureExpression();
        double  EvaluateExpression();
        void    PrintExpression();
        void    PrintPostfixExpression();

    private:
        // --- Atributos
        string  infixExpression;
        bool    isEvaluable;
        string  postfixExpression;

        // --- Métodos privados
        string  InfixToPostfix();

        // --- Métodos de utilería
        bool    ValidateBrackets(const string &e);
        bool    IsValidExpression();
    
};
#endif // !EXPRESSION_HPP_INCLUDED
