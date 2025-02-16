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
#include <cmath>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unordered_map;

const std::unordered_map<char, int> PrecedenceMap = 
{
    {'(', 0}, {'[', 0}, {'{', 0},

    {')', 1}, {']', 1}, {'}', 1},

    {'.', 2},
    {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, 
    {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2},

    {'+', 3}, {'-', 3},

    {'*', 4}, {'/', 4},

    {'^', 5}
};

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
        void    InfixToPostfix();

        // --- Métodos de utilería
        bool    ValidateBrackets(const string &e);
        bool    IsValidExpression();
    
};
#endif // !EXPRESSION_HPP_INCLUDED
