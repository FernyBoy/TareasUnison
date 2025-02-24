/**
*   \file   Client.cpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   23/02/2025
*/

#include "../Headers/Client.hpp"

// -- Lista de nombres y apellidos disponibles
vector<string>  Client::firstNamesList(100);
vector<string>  Client::lastNamesList(100);
 
// -- Contadores de tiempo
uint8_t Client::timeOfService = 0;
uint8_t Client::serviceCounter = 0;
uint8_t Client::arrivingTime = 0;
        
// -- Listas de llegada y atendidos
CircularQueue<string> Client::arrivingQueue;
CircularQueue<string> Client::attendedQueue;

// -- Variable donde se guardan las cajas
vector<Client::Teller> Client::tellerStations;



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Método para comenzar la simulación ---
//
// --------------------------------------------
void Client::RunService()
{
    srand(time(0));
    GetNames();
    timeOfService = 120 + (rand() % 121);

    ClearScreen();
    PrintBankName();
    SetTellersQuantity();

    while(serviceCounter != timeOfService)
    {
        ClearScreen();
        
        PrintServiceTime();
        
        PrintTellerStations();

        PrintWaitingList();

        UpdateData();

        Wait(1);
    }

    PrintPendingClients();

    PrintDayResume();
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de modificación de atributos--
//
// --------------------------------------------
void Client::GetNames()
{
    std::ifstream firstNamesFile, lastNamesFile;

    firstNamesFile.open("./Assets/firstNames.txt", std::ios::in);
    lastNamesFile.open("./Assets/lastNames.txt", std::ios::in);

    if(firstNamesFile.fail() || lastNamesFile.fail()) throw "No se pudo acceder al archivo txt.";

    for(int i = 0; i < 100; ++i)
    {
        getline(firstNamesFile, firstNamesList[i]);
        getline(lastNamesFile, lastNamesList[i]);
    }
}

void Client::SetTellersQuantity()
{
    cout << "\n    |================================================|";
    cout << "\n     En Banxico abrimos un m\241nimo de 3 cajas y un";
    cout << "\n     m\240ximo de 9 cajas al d\241a.\n";
    cout << "\n     \250Cu\240ntas cajas le gustar\241a abrir hoy?";
    cout << "\n     ~ ";

    int quantity = CapturaSegura<>().LongitudCerrada(3, 9);

    for(uint8_t i = 0; i < quantity; ++i)
    {
        Teller newTeller;
        newTeller.tellerNumber = i + 1;

        tellerStations.push_back(newTeller);
    }
}

string Client::CreateClient()
{
    int fn = rand() % firstNamesList.size();
    int ln = rand() % lastNamesList.size();

    string name = firstNamesList[fn] + " " + lastNamesList[ln];
    return name;
}

void Client::UpdateData()
{
    if(arrivingTime == 0)
    {
        arrivingQueue.Enqueue(CreateClient());
        arrivingTime = 1 + rand() % 4;
    }

    for(Teller &t : tellerStations)
    {
        if(t.tellerCounter < t.tellerTime) ++t.tellerCounter;
    }

    if(arrivingTime > 0) --arrivingTime;
    if(serviceCounter < timeOfService) ++serviceCounter;
}




// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de impresión -----------------
//
// --------------------------------------------
void Client::PrintBankName()
{
    cout << "\n    |================================================|";
    cout << "\n    |                                                |";
    cout << "\n    |              Bienvenido a Banxico              |";
    cout << "\n    |                                                |";
    cout << "\n    |================================================|";
    cout << "\n    |   Donde lo unico chico es su cuenta de banco   |";
    cout << "\n    |================================================|";
    cout << "\n    |                                                |";
    cout << "\n    | Tiempo de atenci\242n el d\241a de hoy: ";
    cout << (int)timeOfService << " minutos  |";
    cout << "\n    |================================================|\n";
}

void Client::PrintServiceTime() 
{
    cout << "+-----------------------------+";
    cout << "\n|   Tiempo de atenci\242n: ";

    if (serviceCounter >= 100) {
        cout << (int)serviceCounter << "   |";
    } else if (serviceCounter >= 10) {
        cout << (int)serviceCounter << "    |";
    } else {
        cout << "0" << (int)serviceCounter << "    |";
    }

    cout << "\n+-----------------------------+\n";
}

void Client::PrintStationTemplate(bool busy, uint8_t tellerNumber, string client, uint8_t attendanceTime)
{
    cout << "_________";
    cout << "\n|   " << (int)tellerNumber << "   |";
    if(busy)
    {
        cout << "\n+-------+        " << client;
        cout << "\n|   O   |   O   /";
        cout << "\n|   |   |   |  /";
        cout << "\n|  /|\\  |  /|\\";
        cout << "\n+-------+   |";
        cout << "\n|";
        if((int)attendanceTime >= 10) cout << (int)attendanceTime;
        if((int)attendanceTime < 10) cout << (int)attendanceTime << " ";
        cout << "     |   |";
        cout << "\n|       |  / \\";
        cout << "\n\n";
    }
    else
    {
        cout << "\n+-------+       ";
        cout << "\n|   O   |";
        cout << "\n|   |   |";
        cout << "\n|  /|\\  |";
        cout << "\n+-------+";
        cout << "\n|       |";
        cout << "\n|       |";
        cout << "\n\n";
    }
}

void Client::PrintTellerStations()
{
    for(Teller &t : tellerStations)
    {
        if(t.tellerCounter == t.tellerTime)
        {
            if(!arrivingQueue.IsEmpty())
            {
                if(!t.tellerQueue.IsEmpty()) attendedQueue.Enqueue(t.tellerQueue.Front());

                t.tellerQueue.Enqueue(arrivingQueue.Front());
                arrivingQueue.Dequeue();
                t.tellerCounter = 0;
                t.tellerTime = 8 + (rand() % 8);
                PrintStationTemplate(true, t.tellerNumber, t.tellerQueue.Rear(), t.tellerCounter);
            }
            else
            {
                PrintStationTemplate(false, t.tellerNumber);
            }
        }
        else
        {
            PrintStationTemplate(true, t.tellerNumber, t.tellerQueue.Rear(), t.tellerCounter);
        }
    }
}

void Client::PrintWaitingList()
{
    cout << "\nLista de espera";
    cout << "\n+----------------------------------------------";
    arrivingQueue.PrintElements();
    cout << endl;
}

void Client::PrintPendingClients()
{
    ClearScreen();

    cout << "\nLista de clientes pendientes";
    cout << "\n+----------------------------------------------";

    for(Teller &t : tellerStations)
    {
        if(t.tellerCounter != t.tellerTime)
        {
            cout << "\n|\tLa caja " << (int)t.tellerNumber << " terminar\240 de atender a " << t.tellerQueue.Rear() << "\n|";
        }
    }
    cout << endl;

    Wait(8);
}

void Client::PrintDayResume()
{
    ClearScreen();
    cout << "\n+-----------------------------------------------------+";
    cout << "\n|                                                     |";
    cout << "\n|                       Banxico                       |";
    cout << "\n|                                                     |";
    cout << "\n+-----------------------------------------------------+";
    cout << "\n|";
    cout << "\n|     Personas atendidas: " << attendedQueue.QueueSize();
    cout << "\n|";
    cout << "\n|     Personas no atendias: " << arrivingQueue.QueueSize();
    cout << "\n|______________________________________________________";

    for(Teller &t : tellerStations)
    {
        cout << "\n\n\nLista de personas atendidas por la caja " << (int)t.tellerNumber;
        cout << "\n+----------------------------------------------------";
        t.tellerQueue.PrintElements();
        cout << "\n|\n|\tTotal: " << t.tellerQueue.QueueSize() << endl;
    }
}



// ----------------------------------------------------------------------------------------



// --------------------------------------------
//
// ----- Métodos de utilería ------------------
//
// --------------------------------------------
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
