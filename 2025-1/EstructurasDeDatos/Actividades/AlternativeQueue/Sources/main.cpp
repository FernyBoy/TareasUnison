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
        Queue<int> myQueue, notMyQueue;
        
        for(int i = 0; i < 10; ++i)
        {
            myQueue.Enqueue(i + 1);
        }

        myQueue.PrintElements();
        /*notMyQueue = myQueue;
        /*
        cout << endl;
        notMyQueue.PrintElements();
        notMyQueue.ClearQueue();
        cout << endl;
        notMyQueue.PrintElements();
        */
    }catch(const char *err)
    {
        cerr << "Error: \t" << err << endl;
    }
}
