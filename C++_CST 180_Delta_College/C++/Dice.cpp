// This program tests a die throw function by counting the frequency 
// of throw values by simulating a large number of throws

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUMBER_THROWS = 6000;

int main()
{
    int i, dieThrow;
    int tot_1,tot_2,tot_3,tot_4,tot_5,tot_6;

    // Initialize all counters to zero at once
    tot_1 = tot_2 = tot_3 = tot_4 = tot_5 = tot_6 = 0;
    
    // Set random number seed to current time
    time_t seconds;
    time(&seconds);
    srand( (unsigned int) seconds);

    // Perform die throw simulation
    for (i = 1; i <= NUMBER_THROWS; i++)    
    {
        // Simulate die throw
        dieThrow = rand() % 6 + 1;

        // Increment appropriate die counter   
        switch(dieThrow)
        {
            case 1: tot_1++; break;
            case 2: tot_2++; break;
            case 3: tot_3++; break;
            case 4: tot_4++; break;
            case 5: tot_5++; break;
            case 6: tot_6++; break;
        }  // end switch
    }  // end for

    // Write results
    cout << "Die Value   Count" << endl;
    cout << "   1         " << tot_1 << endl;
    cout << "   2         " << tot_2 << endl;
    cout << "   3         " << tot_3 << endl;
    cout << "   4         " << tot_4 << endl;
    cout << "   5         " << tot_5 << endl;
    cout << "   6         " << tot_6 << endl;
    cout << endl << "Total throws: " << NUMBER_THROWS << endl;  
    
    return 0;  
} 