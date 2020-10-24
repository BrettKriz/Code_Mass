// This program demonstrates real-time computing requirements
// necessary to perform the bubble sort on large lists.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>

void makeRandArray(int theArray[], int size);
void sortArray(int theArray[], int elems);

using namespace std;

const int MAXPOWER_OF_2 = 20;

int main()
{
    int maxsize   = pow(2.0,MAXPOWER_OF_2);

// Time variables
    time_t startTime, endTime;   
    time_t currentTime;
    struct tm * timeinfo;

    int elapsed;                 // To measure outcome
    int *theArray;               // Array to sort

    // Perform test: randomize array, mark time, sort, mark
    // time again.  Report elapsed time.  Increment array
    // size by 10 and repeat
    for (int size = 2; size <= maxsize; size *= 2)
    {
       theArray = new int[size];

       makeRandArray(theArray, size);   // Create random array

       // Perform Bubble Sort - marking time before/after
       time(&startTime);
       sortArray(theArray, size);
       time(&endTime);

       // Report results
       elapsed = int(endTime)-int(startTime);
       cout << "Sorting " << size << " elements took " 
    << elapsed << " second(s) - ending ";

       // Write current local date/time
       time ( ¤tTime );
       timeinfo = localtime ( ¤tTime );
       printf ( "%s", asctime (timeinfo) );
    }
   return 0;
}


/************************************************************/
// Bubble Sort - sort an array of integers
/************************************************************/
void sortArray(int theArray[], int elems)
{
    int temp, end;

   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          if (theArray[count] > theArray[count + 1])
          {
             temp = theArray[count];
             theArray[count] = theArray[count + 1];
             theArray[count + 1] = temp;
          }
       }
   }
}


/************************************************************/
// Function creates an array of n elements that initially
// include 1,2,...,n.  Elements are randomized and array is
// returned.
/************************************************************/
void makeRandArray(int theArray[], int size)
{
    vector<int> myvector;

  // set some values:
  for (int i=0; i<size; ++i)
      myvector.push_back(i+1);

  // using built-in random generator:
  random_shuffle ( myvector.begin(), myvector.end() );


   for (int i=0; i<size; ++i)
   {
       theArray[i] = myvector[i];
   }

} 