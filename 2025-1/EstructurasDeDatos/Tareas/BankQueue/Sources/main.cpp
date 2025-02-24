/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero 
*   \autor  Javier Leonardo Miranda Sanchez
*   \date   23/02/2025
*/

#include <iostream>
#include "../Headers/Client.hpp"

using std::cerr;

int main()
{
    try{
        Client().RunService();
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }

    return 0;
}
