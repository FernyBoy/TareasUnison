/**
 *  \file   Client.hpp
 *  \brief  Definición de la clase Client, encargada de la simulación del servicio bancario.
 *  
 *  Esta clase maneja la generación de clientes, la simulación de atención en cajas y la administración de tiempos
 *  durante la jornada laboral del banco.
 *  
 *  \author Angel Fernando Borquez Guerrero
 *  \author Javier Leonardo Miranda Sanchez
 *  \date   23/02/2025
 */

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <iostream>
#include <cstdint>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include <fstream>

#include "./CircularQueue.hpp"
#include "./CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::rand;

/**
 *  \class Client
 *  \brief Clase que representa la simulación del servicio bancario.
 *  
 *  La clase Client administra la llegada de clientes, la asignación a cajas de atención
 *  y la impresión de reportes al finalizar la simulación.
 */
class Client
{
    public:
        /**
         *  \brief Inicia la simulación del servicio bancario.
         */
        static void RunService();

    private:
        // --- Atributos ---
        
        /** Lista de nombres disponibles para generar clientes. */
        static vector<string> firstNamesList;
        
        /** Lista de apellidos disponibles para generar clientes. */
        static vector<string> lastNamesList;

        /** Duración total del servicio en minutos. */
        static uint8_t timeOfService;
        
        /** Contador del tiempo transcurrido en la simulación. */
        static uint8_t serviceCounter;
        
        /** Tiempo restante para la llegada de un nuevo cliente. */
        static uint8_t arrivingTime;
        
        /** Cola de clientes en espera de atención. */
        static CircularQueue<string> arrivingQueue;
        
        /** Cola de clientes que han sido atendidos. */
        static CircularQueue<string> attendedQueue;

        /**
         *  \struct Teller
         *  \brief Representa una caja de atención en el banco.
         */
        struct Teller
        {
            /**
             *  \brief Constructor que inicializa los valores de la caja.
             */
            Teller() : tellerTime(0), tellerCounter(0) {}

            uint8_t tellerNumber;          /**< Número de la caja. */
            uint8_t tellerTime;            /**< Tiempo necesario para atender un cliente. */
            uint8_t tellerCounter;         /**< Contador del tiempo de atención actual. */
            CircularQueue<string> tellerQueue; /**< Cola de clientes asignados a la caja. */
        };
        
        /** Lista de cajas de atención en el banco. */
        static vector<Teller> tellerStations;

        // --- Métodos privados ---
        
        /**
         *  \brief Carga los nombres y apellidos desde archivos de texto.
         */
        static void GetNames();

        /**
         *  \brief Define la cantidad de cajas de atención a abrir en el banco.
         */
        static void SetTellersQuantity();

        /**
         *  \brief Genera un nuevo cliente con un nombre aleatorio.
         *  \return Nombre completo del cliente generado.
         */
        static string CreateClient();

        /**
         *  \brief Actualiza los datos de la simulación, incluyendo la llegada de clientes y la atención en cajas.
         */
        static void UpdateData();

        /**
         *  \brief Imprime el nombre del banco y el tiempo total de servicio.
         */
        static void PrintBankName();

        /**
         *  \brief Imprime el tiempo de servicio transcurrido.
         */
        static void PrintServiceTime();

        /**
         *  \brief Imprime una representación gráfica de una caja de atención.
         *  \param busy Indica si la caja está ocupada.
         *  \param teller Número de la caja.
         *  \param client Nombre del cliente atendido (opcional).
         *  \param attendanceTime Tiempo de atención restante (opcional).
         */
        static void PrintStationTemplate(bool busy, uint8_t teller, string client = "", uint8_t attendanceTime = 0);

        /**
         *  \brief Imprime el estado de todas las cajas de atención.
         */
        static void PrintTellerStations();

        /**
         *  \brief Imprime la lista de espera de clientes.
         */
        static void PrintWaitingList();

        /**
         *  \brief Imprime la lista de clientes que no fueron atendidos al finalizar la simulación.
         */
        static void PrintPendingClients();

        /**
         *  \brief Imprime un resumen del día con la cantidad de clientes atendidos.
         */
        static void PrintDayResume();
    
        /**
         *  \brief Limpia la pantalla de la consola.
         */
        static void ClearScreen();

        /**
         *  \brief Hace una pausa en la ejecución del programa.
         *  \param time Tiempo de espera en segundos.
         */
        static void Wait(unsigned time);
};

#endif // CLIENT_HPP_INCLUDED
