#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

float function(float x);
float LineRoot(float a, float b);
void limit(float interval[2]);
void spaces(int s = 5);
void resultsLine(int index, float a, float b, float x, float fx);

int main()
{
    float intervalo1[2] = {1.0, 3.0};

    limit(intervalo1);
    
    return 0;
}

float function(float x)
{
    return 2 * x + sin(x) - 4;
}

float LineRoot(float a, float b)
{
    return a - (function(a) * (b - a)) / (function(b) - function(a));
}

void limit(float interval[2])
{
    float x = LineRoot(interval[0], interval[1]);
    float fa = function(interval[0]);
    float fb = function(interval[1]);
    float fx = function(x);

    int cicles = 0;

    cout << "\nf(x) = 2x+Sin(x)-4";

    cout << "\nIntervalo: [" << fixed << setprecision(2) << interval[0] << ", " << fixed << setprecision(2) << interval[1] << "]\n";

    if(function(interval[0]) == 0)
    {
        cout << "\nSolución: " << interval[0];

        if(function(interval[1]) == 0)
        {
            cout << "\nSolución: " << interval[1];
        }
    }
    else if (function(interval[1]) == 0) 
    {
        cout << "\nSolución: " << interval[1];
    }
    else if(fa * fb >= 0)
    {
        cout << "La solución no se encuentra dentro del intervalo.";
    }
    else
    {
        cout << "\nn";
        spaces(2);
        cout << "a_n";
        spaces(7);
        cout << "b_n";
        spaces(7);
        cout << "x_n";
        spaces(7);
        cout << " f(x)" << endl;
        for(int i = 0; i < 58; ++i) cout << "-";

        for(int i = 0; i < 20; ++i)
        {
            resultsLine(cicles, interval[0], interval[1], x, fx);

            if(fa * fx < 0)
            {
                interval[1] = x;
            }
            else
            {
                interval[0] = x;
            }

            x = LineRoot(interval[0], interval[1]);

            fa = function(interval[0]);
            fx = function(x);

            if(fx == 0) 
            {
                cout << "\n\nSolución: " << x;
                break;
            }

            ++cicles;
        }
    }
    cout << endl;

}

void spaces(int s)
{
    for(int i = 0; i < s; ++i) cout << " ";
    cout << " | ";
}

void resultsLine(int index, float a, float b, float x, float fx)
{
    cout << endl;
    cout << index;
    spaces(3 - to_string(index).length());
    cout << fixed << setprecision(6) << a;
    spaces(6 - to_string(a).length());
    cout << fixed << setprecision(6) << b;
    spaces(6 - to_string(b).length());
    cout << fixed << setprecision(6) << x;
    spaces(6 - to_string(x).length());
    cout << " ";
    if(fx < 0) cout << "\b";
    cout << fixed << setprecision(10) << fx;
}
