#include <iostream>

#include "../Headers/Queue.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try
    {
        Queue<int> myQueue;
        
        for(int i = 0; i < 10; ++i)
        {
            myQueue.Enqueue(i + 1);
        }

        myQueue.PrintElements();

    }catch(const char *err)
    {
        cerr << "Error: \t" << err << endl;
    }
}
