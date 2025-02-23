/**
 *  @file   Client.hpp
 *  @author Angel Fernando Borquez Guerrero
 *  @author Javier Leonardo Miranda Sanchez
 *  @date   22/02/2025
 */

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

#include "./Queue.hpp"
#include "./LinkedList.hpp"

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
        // --- Atributos ---
        static vector<string>   firstNamesList;
        static vector<string>   lastNamesList;

        static string           tellerOneAttend;
        static string           tellerTwoAttend;
        static string           tellerThreeAttend;

        static unsigned         tellerOneTime;
        static unsigned         tellerTwoTime;
        static unsigned         tellerThreeTime;

        static unsigned         timeOfService;  
        static unsigned         arrivingTime;
        
        static Queue<string>                arrivingQueue;
        static LinkedList<vector<string>>   attendedList;

        static string   CreateClient();

        static void     ClearScreen();
        static void     PrintInfo();
        static void     Wait(unsigned time);
        
        static void     PrintBankName();
        static void     PrintServiceTime();
        static void     PrintTellerStation(bool busy, unsigned teller, string client = "", unsigned attendanceTime = 0);
        static void     PrintAttendedList();
};

#endif // CLIENT_HPP_INCLUDED
