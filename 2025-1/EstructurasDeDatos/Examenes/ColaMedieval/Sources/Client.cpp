/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/02/2025
*/

#include "../Headers/Client.hpp"

void Client::RunService()
{

    SetServiceTime();

    while(timeOfService != 0)
    {
        cout << "\n+--------------------------------------------------+";
        cout << "\n|              Castillo del Rey Arturo             |";
        cout << "\n+--------------------------------------------------+";

        cout << "\n\nEl Rey Arturo ";
        if(currentPerson == NULL)
        {
            cout << "se encuentra desocupado";
        }
        else
        {
            if(currentPerson[1] == "noble")
            {
                cout << "se encuentra atendiendo a " << currentPerson[0];
            }
            else
        }
    }
}

void Client::GetNames()
{
    std::ifstream firstNamesFile, lastNamesFile;
    string fn, ln;

    firstNamesFile.open("../Assets/firstNames.txt", std::ios::in);
    lastNamesFile.open("../Assets/lastNames.txt", std::ios::in);

    while (getline(firstNamesFile, fn)) 
    {
        firstNamesList.push_back(fn);
    }

    while (getline(lastNamesFile, ln)) 
    {
        lastNamesList.push_back(ln);
    }

    firstNamesFile.close();
    lastNamesFile.close();
}

vector<string> Client::CreatePerson()
{
    vector<string> person(2);

    std::srand(std::time(nullptr));

    int fn = std::rand() % firstNamesList.size();
    int ln = std::rand() % lastNamesList.size();

    person[0] = firstNamesList[fn] + " " + lastNamesList[ln];

    if((std::rand() % 6) + 1 == 1) 
    {
        person[1] = "noble";
    }
    else 
    {
        person[1] = "plebeyo";
    }
    
    return person;
}


void Client::SetServiceTime()
{
    timeOfService = 60 + std::rand() % (120 - 60 + 1);
    currentPerson = NULL;
}

void Client::SetAttendingTime()
{
    attendingTime = 8 + std::rand() % (15 - 8 + 1);
}

void Client::ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}
