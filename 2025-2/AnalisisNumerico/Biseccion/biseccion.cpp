#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

float function(float x);
float media(float a, float b);
void spaces(int s = 5);
void resultsLine(int index, float a, float b, float x, float fx);

int main()
{
    float intervalo[2] = {1.5, 2.0};
    float x = media(intervalo[0], intervalo[1]);
    float fa = function(intervalo[0]);
    float fb = function(intervalo[1]);
    float fx = function(x);

    cout << "\nf(x) = 2x+Sin(x)-4\n";

    if(fa * fb >= 0)
    {
        cout << "La solución no se encuentra dentro del intervalo.";
    }
    else
    {
        cout << "\nn";
        spaces(1);
        cout << "a_n";
        spaces(3);
        cout << "b_n";
        spaces(3);
        cout << "x_n";
        spaces(3);
        cout << " f(x)" << endl;
        for(int i = 0; i < 45; ++i) cout << "-";

        for(int i = 0; i < 21; ++i)
        {
            resultsLine(i, intervalo[0], intervalo[1], x, fx);

            if(fa * fx < 0)
            {
                intervalo[1] = x;
            }
            else
            {
                intervalo[0] = x;
            }

            x = media(intervalo[0], intervalo[1]);

            fa = function(intervalo[0]);
            fx = function(x);
        }
    }
    cout << endl;

    return 0;
}

float function(float x)
{
    return 2 * x + sin(x) - 4;
}

float media(float a, float b)
{
    return (a + b) / 2;
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
    spaces(2 - to_string(index).length());
    cout << fixed << setprecision(4) << a;
    spaces(4 - to_string(a).length());
    cout << fixed << setprecision(4) << b;
    spaces(4 - to_string(b).length());
    cout << fixed << setprecision(4) << x;
    spaces(4 - to_string(x).length());
    cout << " ";
    if(fx < 0) cout << "\b";
    cout << fixed << setprecision(10) << fx;
}
