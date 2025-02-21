/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero 
*   \date   21/02/2025
*/

#include <iostream>
#include "../Headers/Client.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try{
        Client().RunService();
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }
}
