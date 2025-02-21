/**
*   \file   Client.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/02/2025
*/

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>

#include "./MedievalQueue.hpp"
#include "./Queue.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Client
{
    public:
        static void RunService();

    private:
        // --- Atributos
        static vector<string>  firstNamesList;
        static vector<string>  lastNamesList;
        
        static Queue<vector<string>>   waitingQueue;
        static Queue<vector<string>>   attendedQueue;
        static vector<string>          currentPerson;

        static unsigned        timeOfService;
        static unsigned        attendingTime;

        // --- Métodos
        static void            GetNames();
        static vector<string>  CreatePerson();

        static void    SetServiceTime();
        static void    SetAttendingTime();

        static void    ClearScreen();
        static void    PrintInfo();
};
#endif // !EXPRESSION_HPP_INCLUDED
