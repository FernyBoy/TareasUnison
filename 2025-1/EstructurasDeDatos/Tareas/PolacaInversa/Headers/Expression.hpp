/**
*   \file   Expression.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/
#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <string>

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
        int     EvaluateExpression();
        void    PrintExpression();
        void    PrintPostfixExpression();

    private:
        // --- Atributos
        string  infixExpression;
        bool    isEvaluable;
        string  postfixExpression;

        // --- Métodos privados
        bool    IsValidExpression();

        // --- Métodos de utilería
    //
};
#endif // !EXPRESSION_HPP_INCLUDED
