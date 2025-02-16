/**
 *   \file   Expression.hpp
 *   \brief  Definición de la clase Expression para evaluar expresiones en notación polaca inversa.
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

/**
 * @brief Mapa de precedencia de operadores y operandos.
 */
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

/**
 * @brief Lista de símbolos permitidos en la expresión.
 */
const char SymbolsList[] = 
{ 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    '.', '+', '-', '*', '/', '^', 
    '{', '}', '(', ')', '[', ']'
};

/**
 * @brief Tamaño de la lista de símbolos.
 */
const unsigned SymbolsSize = 22;

/**
 * @class Expression
 * @brief Clase que representa una expresión matemática y permite evaluarla.
 */
class Expression
{
    // --- Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& output, const Expression& e);

    public:
        /**
         * @brief Constructor por defecto.
         */
        explicit Expression();

        /**
         * @brief Constructor que inicializa la expresión con un string dado.
         * @param e Expresión matemática en formato infijo.
         */
        explicit Expression(string e);

        /**
         * @brief Captura la expresión ingresada por el usuario.
         */
        void CaptureExpression();

        /**
         * @brief Evalúa la expresión en notación polaca inversa.
         * @return Resultado de la evaluación.
         */
        double EvaluateExpression();

        /**
         * @brief Imprime la expresión en notación infija.
         */
        void PrintExpression();

        /**
         * @brief Imprime la expresión convertida a notación postfija.
         */
        void PrintPostfixExpression();

    private:
        string  infixExpression;   /**< Expresión matemática en notación infija. */
        bool    isEvaluable;       /**< Indica si la expresión es válida para ser evaluada. */
        string  postfixExpression; /**< Expresión convertida a notación postfija. */

        /**
         * @brief Convierte la expresión infija a notación postfija.
         */
        void InfixToPostfix();

        /**
         * @brief Valida la correcta apertura y cierre de paréntesis en la expresión.
         * @param e Expresión a validar.
         * @return Verdadero si los paréntesis están bien balanceados.
         */
        bool ValidateBrackets(const string &e);

        /**
         * @brief Verifica si la expresión ingresada es válida.
         * @return Verdadero si la expresión es válida.
         */
        bool IsValidExpression();
};

#endif // !EXPRESSION_HPP_INCLUDED
