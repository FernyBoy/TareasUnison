#include <iostream>
#include <cmath>
#include <ctime>

using std::cout;

int main()
{
    srand(time(0));
    double p = 0.7, u;

    for(int i = 0; i < 10; ++i)
    {
        u = std::rand() / (RAND_MAX + 1.0);;
        cout << "\np = " << p;
        cout << "\nq = " << 1 - p;
        cout << "\nu = " << u;
        cout << "\n" << (u > 1 - p ? 1 : 0);
        cout << "\n------------\n";
    }

    return 0;
}
