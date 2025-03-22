/**
*   \file   main.cpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/03/2025
*/

#include <iostream>
#include <cstdint>
#include <vector>
#include <ctime>
#include <fstream>

#include "../Headers/CircularList.hpp"
#include "../Headers/CapturaSegura.hpp"

using namespace std;

void GetNames(vector<string> &firstNamesList);
string CreatePlayer(vector<string> &firstNamesList);
void PressEnter();
void ClearScreen();
void SystemPause();


int main()
{
    ClearScreen();

    vector<string> firstNamesList(100);
    srand(time(0));
    GetNames(firstNamesList);

    CircularList<string> Players;

    cout << "\nIngresa la cantidad de jugadores que van a participar\n - ";
    unsigned playersNumber = CapturaSegura<unsigned>().LongitudMinima(3);
    for(unsigned i = 0; i < playersNumber; ++i)
    {
        Players.Add(CreatePlayer(firstNamesList));
    }

    ClearScreen();
    cout << "\nLista de jugadores:\n";
    Players.Print();
    PressEnter();
    
    ClearScreen();
    unsigned moves = 0;
    while(Players.Size() != 1)
    {
        cout << "\n\nIngresa la cantidad de lugares a recorrer para eliminar un jugador\n - ";
        moves = CapturaSegura<unsigned>().LongitudPositiva();

        for(unsigned i = 0; i < moves; ++i)
        {
            Players.MoveForward();
        }
        
        cout << "\nJugador eliminado: " << Players.GetHead();
        Players.RemoveHead();
        
        cout << "\n\nJugadores actuales:\n";
        Players.Print();

        cout << endl;
        for(int i = 0; i < 40; ++i)
        {
            cout << "-";
        }
    }

    cout << "\n\nEl ganador es";
    
    cout << "\n---";
    for(int i = 0; i < (int)Players.GetHead().size(); ++i)
    {
        cout << "-";
    }
    cout << "---";
    
    cout << "\n|  " << Players.GetHead() << "  |";
    
    cout << "\n---";
    for(int i = 0; i < (int)Players.GetHead().size(); ++i)
    {
        cout << "-";
    }
    cout << "---";   

    SystemPause();
    return 0;
}

void GetNames(vector<string> &firstNamesList)
{
    std::ifstream firstNamesFile;

    firstNamesFile.open("./Assets/firstNames.txt", std::ios::in);

    if(firstNamesFile.fail()) throw "No se pudo acceder al archivo txt.";

    for(int i = 0; i < 100; ++i)
    {
        getline(firstNamesFile, firstNamesList[i]);
    }
}

string CreatePlayer(vector<string> &firstNamesList)
{
    int fn = rand() % firstNamesList.size();
    string name = firstNamesList[fn];
    return name;
}

void PressEnter()
{
    cout << "\n\nPresiona enter para continuar";
    cin.ignore();
    cin.get();
}

void ClearScreen() 
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

void SystemPause()
{
    #ifdef _WIN32
        system("pause");
    #endif
}
