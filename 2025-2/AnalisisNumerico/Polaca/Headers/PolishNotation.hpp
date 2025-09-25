/**
*   \file   PolishNotation.hpp
*   \author Fernando Borquez
*   \date   18/09/2025
*/

#ifndef POLISHNOTATION_HPP_INCLUDED
#define POLISHNOTATION_HPP_INCLUDED

#include "./CapturaSegura.hpp"
#include "./LinkedStack.hpp"

#include <iostream>
#include <ostream>
#include <cmath>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unordered_map;

const unordered_map<char, int> PrecedenceMap = 
{
    {'(', 0}, {'[', 0}, {'{', 0},
    {')', 1}, {']', 1}, {'}', 1},
    {'.', 2},
    {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, 
    {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2},
    {'x', 2},
    {'+', 3}, {'-', 3},
    {'*', 4}, {'/', 4},
    {'^', 5}
};

const char SymbolsList[] = 
{ 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'x',
    '.', '+', '-', '*', '/', '^', 
    '{', '}', '(', ')', '[', ']'
};

const unsigned SymbolsSize = 23;



template <typename Type>
class PolishNotation
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const PolishNotation<T> &ex);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, PolishNotation<T> &ex);

    public:
        // --- Constructores
        explicit PolishNotation();
        PolishNotation(const PolishNotation &ex);
        PolishNotation & operator=(const PolishNotation &ex);

        // --- Destructor
        ~PolishNotation();

        // --- Métodos públicos
        void    CaptureExpression();
        Type    EvaluateExpression(Type x);
        void    PrintInfixExpression();
        void    PrintPostfixExpression();


    private:
        // --- Atributos
        string  infixExpression;
        string  postfixExpression; 
        bool    isEvaluable;

        // --- Métodos privados
        void    InfixToPostfix();
        bool    ValidateBrackets(const string ex);
        bool    IsValidExpression();

        // --- Métodos de utilería

};

#include "../Templates/PolishNotation.tpp"

#endif // !POLISHNOTATION_HPP_INCLUDED
