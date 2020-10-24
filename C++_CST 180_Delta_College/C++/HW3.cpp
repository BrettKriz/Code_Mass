// This program simulates throwing two dice and counts the
// frequency of throw values using a large number of throws
// The result is written as a histogram

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int ThrowDice(); // Prototype

const int NUMBER_THROWS = 200;

int main()
{
int i, j, diceThrow;
int total[13];
int min = 2; // 1+1
int max = 12;// 6+6
// Initialize all counters to zero at once
    for (i = min; i <= max; i++)
    {
        total[i] = 0;
    }
    // Set random number seed to current time
    time_t seconds;
    time(&seconds);
    srand( (unsigned int) seconds);
    
    //cout << "STARTING LOOP\n\n";
       // Perform dice throw simulation
        for (i = 1; i <= NUMBER_THROWS; i++)
        {
        // Simulate dice throw
        diceThrow = ThrowDice();
        // Throw two dice
        total[diceThrow]++; // Add one to correct counter
        } // end for
// DIP
        // Write results as histogram
        for (i = min; i <= max; i++)
        {
            cout << setw(2) << i << ": ";
            for (j = 1; j <= total[i]; j++)
            cout << "+";
            cout << endl;
        }
		system("pause");
return 0;
}

// This function utilizes the C++ random number generator
// to simulate throwing two dice.
int ThrowDice()
{
    int throw1, throw2;
    
    throw1 = rand() % 6 + 1 ;
    throw2 = rand() % 6 + 1 ;
    
    return throw1 + throw2;
}
