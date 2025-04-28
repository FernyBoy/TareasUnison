/**
*   \file   main.cpp
*   \author Angel Fernando Bórquez Guerrero
*   \author Javier Leonardo Miranda Sánchez
*   \date   26/04/2025
*/

#include <iostream>
#include <cmath>
#include "../Headers/Client.hpp"
#include "../Headers/CapturaSegura.hpp"

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

    return 0;
}
