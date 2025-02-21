/**
*   \file   Client.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   21/02/2025
*/

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

#include "./MedievalQueue.hpp"

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
        
        static vector<string>   attendedList;
        static vector<string>   currentPerson;

        static unsigned     timeOfService;
        static unsigned     attendingTime;
        static unsigned     arrivingTime;

        // --- Métodos
        static vector<string>  CreatePerson();

        static void     ClearScreen();
        static void     PrintInfo();
        static void     Wait(unsigned time);
};
#endif // !EXPRESSION_HPP_INCLUDED
