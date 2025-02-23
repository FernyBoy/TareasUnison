/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   22/02/2025
*/

#include "../Headers/Client.hpp"

vector<string>  Client::firstNamesList = {"Fernando", "Javier", "Emily", "Elias", "Flor", "Victor", "Dante", "Oiram"};
vector<string>  Client::lastNamesList = {"Borquez", "Miranda", "Beltran", "Peregrina", "Machado", "Martinez", "Tostado", "Figueroa"};
string Client::tellerOneAttend;
string Client::tellerTwoAttend;
string Client::tellerThreeAttend;

unsigned Client::tellerOneTime = 0;
unsigned Client::tellerTwoTime = 0;
unsigned Client::tellerThreeTime = 0;

unsigned Client::timeOfService = 120;  
unsigned Client::arrivingTime = 5;
        
Queue<string>                Client::arrivingQueue;
LinkedList<vector<string>>   Client::attendedList;

void Client::RunService()
{
    ClearScreen();
    PrintBankName();
    std::this_thread::sleep_for(std::chrono::seconds(10));

    while(timeOfService != 0)
    {
        ClearScreen();
        PrintServiceTime();

        if(tellerOneTime == 0)
        {
            if(!arrivingQueue.IsEmpty())
            {
                attendedList.AddLast(vector<string> {"1", arrivingQueue.Front()});
                tellerOneAttend = arrivingQueue.Front();
                arrivingQueue.Dequeue();
                tellerOneTime = 15;
            }
            else
            {
                tellerOneAttend = "";
            }
        }
        if(!tellerOneAttend.empty())
        {
            PrintTellerStation(true, 1, tellerOneAttend, tellerOneTime);
        }
        else
        {
                PrintTellerStation(false, 1);
        }

        if(tellerTwoTime == 0)
        {
            if(!arrivingQueue.IsEmpty())
            {
                attendedList.AddLast(vector<string> {"2", arrivingQueue.Front()});
                tellerTwoAttend = arrivingQueue.Front();
                arrivingQueue.Dequeue();
                tellerTwoTime = 10;
            }
            else
            {
                tellerTwoAttend = "";
            }
        }        
        if(!tellerTwoAttend.empty())
        {
            PrintTellerStation(true, 2, tellerTwoAttend, tellerTwoTime);
        }
        else
        {
                PrintTellerStation(false, 2);
        }

        if(tellerThreeTime == 0)
        {
            if(!arrivingQueue.IsEmpty())
            {
                attendedList.AddLast(vector<string> {"3", arrivingQueue.Front()});
                tellerThreeAttend = arrivingQueue.Front();
                arrivingQueue.Dequeue();
                tellerThreeTime = 8;
            }
            else
            {
                tellerThreeAttend = "";
            }
        }
        if(!tellerThreeAttend.empty())
        {
            PrintTellerStation(true, 3, tellerThreeAttend, tellerThreeTime);
        }
        else
        {
            PrintTellerStation(false, 3);
        }


        cout << "\nLista de espera";
        cout << "\n+----------------------------------------------";
        arrivingQueue.PrintElements();
        cout << endl;

        
        if(arrivingTime == 0)
        {
            arrivingQueue.Enqueue(CreateClient());
            arrivingTime = 4;
        }

        if(tellerOneTime > 0) --tellerOneTime;
        if(tellerTwoTime > 0) --tellerTwoTime;
        if(tellerThreeTime > 0) --tellerThreeTime;
        if(arrivingTime > 0) --arrivingTime;
        if(timeOfService > 0) --timeOfService;
        Wait(1);
    }

    ClearScreen();
    cout << "\n+-----------------------------------------------------+";
    cout << "\n|                                                     |";
    cout << "\n|                       Banxico                       |";
    cout << "\n|                                                     |";
    cout << "\n+-----------------------------------------------------+";
    cout << "\n|";
    cout << "\n|     Personas atendidas: " << attendedList.ListSize();
    cout << "\n|";
    cout << "\n|     Personas no atendias: " << arrivingQueue.QueueSize();
    cout << "\n|______________________________________________________";

    cout << "\n\n\nLista de personas atendidas";
    cout << "\n+----------------------------------------------------";
    PrintAttendedList();
    cout << "\n\n";

    cout << "\n\n\nLista de personas no atendidas";
    cout << "\n+----------------------------------------------------";
    arrivingQueue.PrintElements();
    cout << "\n\n";
}

string Client::CreateClient()
{
    int fn = std::rand() % firstNamesList.size();
    int ln = std::rand() % lastNamesList.size();

    return firstNamesList[fn] + " " + lastNamesList[ln];
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

void Client::PrintBankName()
{
    cout << "\n    |================================================|";
    cout << "\n    |                                                |";
    cout << "\n    |              Bienvenido a Banxico              |";
    cout << "\n    |                                                |";
    cout << "\n    |================================================|";
    cout << "\n    |   Donde lo unico chico es su cuenta de banco   |";
    cout << "\n    |================================================|\n";
}

void Client::PrintServiceTime()
{
    cout << "+-----------------------------+";
    cout << "\n|   Tiempo de atención: ";
    
    if(timeOfService >= 100) cout << timeOfService << "   |";
    else if(timeOfService < 100) cout << timeOfService << "    |";
    else if(timeOfService < 10)
    {
        cout << "0 ";
        cout << timeOfService;
        cout << "     |";
    }
    
    cout << "\n+-----------------------------+\n";
}

void Client::PrintTellerStation(bool busy, unsigned teller, string client, unsigned attendanceTime)
{
    cout << "_______";
    cout << "\n|  " << teller << "  |";
    if(busy)
    {
        cout << "\n+-----+       " << client;
        cout << "\n|  O  |  O   /";
        cout << "\n|  |  |  |  /";
        cout << "\n| /|\\ | /|\\";
        cout << "\n+-----+  |";
        cout << "\n|";
        if(attendanceTime >= 10) cout << attendanceTime;
        if(attendanceTime < 10) cout << attendanceTime << " ";
        cout << "   |  |";
        cout << "\n|     | / \\";
        cout << "\n\n";
    }
    else
    {
        cout << "\n+-----+       ";
        cout << "\n|  O  |";
        cout << "\n|  |  |";
        cout << "\n| /|\\ |";
        cout << "\n+-----+";
        cout << "\n|     |";
        cout << "\n|     |";
        cout << "\n\n";
    }
}

void Client::PrintAttendedList()
{
    unsigned size = attendedList.ListSize();

    for(unsigned i = 0; i < size; ++i)
    {
        cout << "\n|\tCaja: " << attendedList[i][0] << "  |  Cliente: " << attendedList[i][1];
    }
}
