#include <iostream>
#include <cmath>
#include <ctime>

int main()
{
    srand(time(0));
    double lambda = 0.5, u;
    
    for(int i = 0; i < 5; ++i)
    {
        u = std::rand() / (RAND_MAX + 1.0);
        std::cout << "\nLambda = " << lambda;
        std::cout << "\nu = " << u;
        std::cout << "\nx = " << -1/lambda * log(1 - u);
        std::cout << "\n------------\n";
    }

    return 0;
}
