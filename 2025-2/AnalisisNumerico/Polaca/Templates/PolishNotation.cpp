/**
*   \file   PolishNotation.tpp
*   \author Fernando Borquez
*   \date   18/09/2025
*/

#include "../Headers/PolishNotation.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
template <typename Type>
PolishNotation<Type>::PolishNotation() : infixExpression(""), postfixExpression(""), isEvaluable(false) {}


template <typename Type>
PolishNotation<Type>::PolishNotation(const PolishNotation &ex)
{   

}

template <typename Type>
PolishNotation<Type> & PolishNotation<Type>::operator=(const PolishNotation<Type> &ex)
{

}
// ----------------------
// ----- Destructor -----
// ----------------------
template <typename Type>
PolishNotation<Type>::~PolishNotation()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------
template <typename Type>
void PolishNotation<Type>::CaptureExpression()
{
    while(true)
    {
        infixExpression = CapturaSegura<>().TextoPermitido(SymbolsList, SymbolsSize);
        
        if(ValidateBrackets(infixExpression)) break;

        cout << "\n S\241mbolos de cierre mal balanceados. Ingresa de nuevo tu expresi\242n\n • ";
    }

    InfixToPostfix();
}

template <typename Type>
Type PolishNotation<Type>::EvaluateExpression(Type x)
{
    Type result = 0;

    return result;
}

template <typename Type>
void PolishNotation<Type>::PrintInfixExpression()
{

}

template <typename Type>
void PolishNotation<Type>::PrintPostfixExpression()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
template <typename Type> 
void PolishNotation<Type>::InfixToPostfix()
{

}

template <typename Type>
bool ValidateBrackets(const string ex)
{
    return true;
}

template <typename Type>
bool PolishNotation<Type>::IsValidExpression()
{
    return true;
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
/* 
template <typename Type>
std::ostream & operator<<(std::ostream &output, PolishNotation<Type> &ex)
{
    

    return output;
}


template <typename Type>
std::istream & operator>>(std::istream &input, PolishNotation<Type> &ex)
{
    

    return input;
}
*/
