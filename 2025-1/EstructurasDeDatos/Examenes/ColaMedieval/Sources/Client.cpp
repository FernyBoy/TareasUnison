/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/02/2025
*/

#include "../Headers/Client.hpp"

vector<string>  Client::firstNamesList = {"Fernando", "Javier", "Emily", "Elias", "Flor", "Victor", "Dante", "Oiram"};
vector<string>  Client::lastNamesList = {"Borquez", "Miranda", "Beltran", "Peregrina", "Machado", "Martinez", "Tostado", "Figueroa"}; 
vector<string>  Client::attendedList;
vector<string>  Client::currentPerson;
unsigned        Client::timeOfService = 120;
unsigned        Client::attendingTime = 0;
unsigned        Client::arrivingTime = 0;

void Client::RunService()
{
    MedievalQueue todayList;

    ClearScreen();
    cout << "+--------------------------------------------------+";
    cout << "\n|                                                  |";
    cout << "\n|              Castillo del Rey Arturo             |";
    cout << "\n|                                                  |";
    cout << "\n+--------------------------------------------------+\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    while(timeOfService != 0)
    {
        ClearScreen();
        cout << "\n+-----------------------------------------------------+";
        cout << "\n|                                                     |";
        cout << "\n|               Castillo del Rey Arturo               |";
        cout << "\n|                                                     |";
        cout << "\n+-----------------------------------------------------+";
        cout << "\n|";
        cout << "\n|     Tiempo de atenci\242n restante: " << timeOfService << " minutos";
        cout << "\n|______________________________________________________";
            
        cout << "\n\n\n  W";
        cout << "\n  O  |||";
        cout << "\n  |___|";

        cout << "\t\t  El Rey Arturo ";
        if(currentPerson.empty())
        {
            cout << "se encuentra desocupado";
        }
        else
        {
            if(currentPerson[1] == "noble")
            {
                cout << "se encuentra atendiendo al noble " << currentPerson[0];
            }
            else
            {
                cout << "se encuentra atendiendo al plebeyo " << currentPerson[0];
            }
        }

        cout << "\n /|   |";
        cout << "\n  |   |";
        cout << "\n / |  |";
        cout << "\n________";
        cout << "\n        |_         o";
        cout << "\n          |_      -|-";
        cout << "\n            |_     |";
        cout << "\n              |_  / |\t";
        
        if(attendingTime != 0)
        {
            cout << "Su tiempo de atenci\242n es de " << attendingTime << " minutos";
        }

        cout << "\n\n\nLista de espera";
        cout << "\n+----------------------------------------------";
        todayList.PrintList();
        cout << endl;

        if(!todayList.IsEmpty())
        {
            if(attendingTime == 0)
            {
                if(!currentPerson.empty())
                {
                    attendedList.push_back(currentPerson[0] + " - " + currentPerson[1]);
                }

                currentPerson = todayList.GetFront();
                todayList.Dequeue();
                attendingTime = 15;
            }
        }

        if(arrivingTime == 0)
        {
            vector<string> person = CreatePerson();
            todayList.Enqueue(person[0], person[1]);
            arrivingTime = 8;
        }

        if(arrivingTime > 0) --arrivingTime;
        if(attendingTime > 0) --attendingTime;
        if(timeOfService > 0) --timeOfService;

        Wait(1);
    }

    if(!currentPerson.empty()) attendedList.push_back(currentPerson[0] + " - " + currentPerson[1]);

    ClearScreen();
    cout << "\n+-----------------------------------------------------+";
    cout << "\n|                                                     |";
    cout << "\n|               Castillo del Rey Arturo               |";
    cout << "\n|                                                     |";
    cout << "\n+-----------------------------------------------------+";
    cout << "\n|";
    cout << "\n|     Nobles atendidos: " << todayList.NobleSize();
    cout << "\n|";
    cout << "\n|     Plebeyos atentidos: " << todayList.VillagerSize();
    cout << "\n|______________________________________________________";

    cout << "\n\n\nLista de personas atendidas";
    cout << "\n+----------------------------------------------";
    for(string s : attendedList)
    {
        cout << "\n|\t" << s;
    }
    cout << "\n\n";
}

vector<string> Client::CreatePerson()
{
    vector<string> person(2);

    std::srand(std::time(nullptr));

    int fn = std::rand() % firstNamesList.size();
    int ln = std::rand() % lastNamesList.size();

    person[0] = firstNamesList[fn] + " " + lastNamesList[ln];

    if((std::rand() % 4) + 1 == 1) 
    {
        person[1] = "noble";
    }
    else 
    {
        person[1] = "plebeyo";
    }

    if(person[0] == "Fernando Borquez")
    {
        person[1] = "noble";
    }
    
    return person;
}


void Client::ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

void Client::Wait(unsigned time)
{
    std::this_thread::sleep_for(std::chrono::seconds(time));
}


