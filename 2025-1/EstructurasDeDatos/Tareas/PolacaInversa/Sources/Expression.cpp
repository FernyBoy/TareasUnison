/**
*   \file   Expression.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   15/02/2025
*/

#include "../Headers/Expression.hpp"

using std::cout;
using std::cin;
using std::end;

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
Expression::Expression() : infixExpression(NULL), isEvaluable(false), postfixExpression(NULL) {}

Expression::Expression(const std::string e)
{

}

Expression::Expression(const Expression &e)
{

}

Expression & Expression::operator=(const Expression &e)
{

}
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
    
}

double Expression::EvaluateExpression()
{

}

void Expression::PrintExpression()
{

}

void Expression::PrintPostfixExpression()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
bool Expression::IsValidExpression()
{
    
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------

