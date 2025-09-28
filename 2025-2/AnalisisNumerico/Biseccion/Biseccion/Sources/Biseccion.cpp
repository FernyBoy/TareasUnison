/**
*   \file   Biseccion.cpp
*   \author Fernando Borquez
*   \date   25/09/2025
*/

#include "../Headers/Biseccion.hpp"

// --------------------------------------------
//
// ----- Constructores ------------------------
//
// --------------------------------------------
Biseccion::Biseccion() 
{

}

Biseccion::Biseccion(const Biseccion &b)
{   

}

Biseccion & Biseccion::operator=(const Biseccion &b)
{

}
// ----------------------
// ----- Destructor -----
// ----------------------
Biseccion::~Biseccion()
{

}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos públicos ---------------------
//
// --------------------------------------------




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos privados ---------------------
//
// --------------------------------------------
float Biseccion::Function(float x)
{
    return cos(x) - 10 * pow(x, 2) - 560 * x - 7834;
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
void Biseccion::Spaces(int s)
{
    for(int i = 0; i < s; ++i) cout << " ";
    cout << " | ";
}

void Biseccion::PrintResultsLine(int index, float a, float b, float x, float fx) 
{
    cout << endl;
    cout << index;
    Spaces(3 - to_string(index).length());
    cout << fixed << setprecision(6) << a;
    Spaces(6 - to_string(a).length());
    cout << fixed << setprecision(6) << b;
    Spaces(6 - to_string(b).length());
    cout << fixed << setprecision(6) << x;
    Spaces(6 - to_string(x).length());
    cout << " ";
    if(fx < 0) cout << "\b";
    cout << fixed << setprecision(10) << fx;
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos externos ---------------------
//
//---------------------------------------------
/*
std::ostream & operator<<(std::ostream &output, Biseccion &b)
{
    

    return output;
}

std::istream & operator>>(std::istream &input, Biseccion &b)
{
    

    return input;
}
*/
