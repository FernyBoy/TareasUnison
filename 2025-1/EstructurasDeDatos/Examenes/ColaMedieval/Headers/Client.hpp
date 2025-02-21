/**
 *  @file   Client.hpp
 *  @author Angel Fernando Borquez Guerrero
 *  @date   21/02/2025
 *  @brief  Definición de la clase Client para la simulación de audiencias en el castillo del Rey Arturo.
 *
 *  La clase `Client` gestiona el flujo de atención de nobles y plebeyos en la corte del Rey Arturo.
 *  Controla la cola de espera, asigna tiempos de atención y simula el servicio de audiencias.
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

/**
 *  @class Client
 *  @brief Simula la gestión de atención de personajes en el castillo del Rey Arturo.
 *
 *  Esta clase se encarga de organizar la cola de espera de nobles y plebeyos,
 *  asignar tiempos de llegada y atención, y administrar la simulación del proceso de audiencias.
 */
class Client
{
    public:
        /**
         * @brief Inicia la simulación del servicio de audiencias.
         *
         * Administra la cola de espera, atiende a los personajes en orden de prioridad y muestra 
         * información en pantalla en tiempo real. La simulación se ejecuta hasta que el tiempo de servicio
         * se agota.
         */
        static void RunService();

    private:
        // --- Atributos ---

        static vector<string>  firstNamesList;  /**< Lista de nombres posibles. */
        static vector<string>  lastNamesList;   /**< Lista de apellidos posibles. */

        static vector<string>  currentPerson;   /**< Persona actualmente en audiencia con el Rey Arturo. */

        static unsigned timeOfService;  /**< Tiempo total del servicio de audiencias en minutos. */
        static unsigned attendingTime;  /**< Tiempo de atención del Rey Arturo a la persona actual. */
        static unsigned arrivingTime;   /**< Tiempo restante para que llegue una nueva persona a la cola. */

        // --- Métodos ---

        /**
         * @brief Genera una persona con un nombre y un estatus aleatorio.
         *
         * Selecciona un nombre y un apellido aleatorio de las listas predefinidas y
         * asigna un estatus basado en una probabilidad del 16.67% de ser noble.
         * 
         * @return Un vector con el nombre y el estatus de la persona generada.
         */
        static vector<string> CreatePerson();

        /**
         * @brief Limpia la pantalla de la consola.
         *
         * Usa `system("cls")` en Windows y `system("clear")` en Linux/macOS.
         */
        static void ClearScreen();

        /**
         * @brief Muestra información relevante en pantalla.
         *
         * (Nota: Método declarado pero no implementado en `Client.cpp`).
         */
        static void PrintInfo();

        /**
         * @brief Pausa la ejecución por el tiempo especificado.
         *
         * @param time Cantidad de segundos que debe esperar la ejecución.
         */
        static void Wait(unsigned time);
};

#endif // CLIENT_HPP_INCLUDED
