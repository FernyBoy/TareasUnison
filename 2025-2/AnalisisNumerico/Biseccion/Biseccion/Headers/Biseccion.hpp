/**
*   \file   Biseccion.hpp
*   \author Fernando Borquez
*   \date   25/09/2025
*/

#ifndef BISECCION_HPP_INCLUDED
#define BISECCION_HPP_INCLUDED

#include "Queue.hpp"
#include "CapturaSegura.hpp"

#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::to_string;
using std::setprecision;

class Biseccion
{
    // --- Métodos externos
    friend std::ostream& operator<<(std::ostream& output, const Biseccion &b);
    friend std::istream& operator>>(std::istream& input, Biseccion &b);

    public:
        // --- Constructores
        explicit Biseccion();
        Biseccion(const Biseccion &b);
        Biseccion & operator=(const Biseccion &b);

        // --- Destructor
        ~Biseccion();

        // --- Métodos públicos
        void    PrintResults();


    private:
        // --- Atributos
        int     cicles;
        float   a;
        float   b;
        float   x;
        float   fa;
        float   fb;
        float   fx;

        Queue<vector<float>>    pendingIntervals;

        struct ResultsTable
        {
            

            void Append(float a, float b, float x, float fx);
        };

        vector<ResultsTable> resultsList;

        // --- Métodos privados
        float   Function(float x);
        float   Mean();
        void    Calculate();


        // --- Métodos de utilería
        void    Spaces(int s);
        void    PrintResultsLine(int index, float a, float b, float x, float fx);
        void    PrintResultsTable();

};
#endif // BISECCION_HPP_INCLUDED
