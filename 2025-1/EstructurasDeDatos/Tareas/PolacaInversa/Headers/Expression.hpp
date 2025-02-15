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

class Expression
{
    // --- Métodos externos
    friend std::ostream& operator<<(std::ostream& output, const Expression& e);
    friend std::istream& operator>>(std::istream& input, Expression& e);

    public:
        // --- Constructores
        explicit Expression();
        Expression(const Expression &e);
        Expression & operator=(const Expression &e);

        // --- Destructor
        ~Expression();

        // --- Métodos públicos


    private:
        // --- Atributos


        // --- Métodos privados


        // --- Métodos de utilería
    //
};
#endif // !EXPRESSION_HPP_INCLUDED
