/************************************************************/
/* This program demonstrates a function that removes        */
/* duplicate elements in an ordered list of integers.       */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIST_SIZE = 100;                // Max list size

// Function prototypes
void GetList(int inList[],int& listsize, int maxlistsize);
void RemoveDuplicates(int theList[],int& listSize);
void DisplayList(int theList[],int listsize);

int main()
{
    int InList[MAX_LIST_SIZE];      // Array of list elements
    int ListSize;                   // Index of last list element
                                        
    GetList(InList, ListSize, MAX_LIST_SIZE);
    cout << "Before:" << endl;
    DisplayList(InList, ListSize);  // Display list with duplicates

    RemoveDuplicates(InList, ListSize);   
    
    cout << "After:" << endl;
    DisplayList(InList, ListSize);  // Display list without duplicates
    
    return 0;
}

/************************************************************/
/* This function receives an ordered list of integers and   */
/* removes duplicate values (in adjacent storage elements)  */
/*   Parameters:                                            */
/*        list            array of integers to build        */
/*        listsize        number of integers in list        */

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/*   Parameters:                                            */
/*        list            array of integers to build        */
/*        listsize        number of integers in list        */
/*        maxlistsize     max size allowable for list array */
/************************************************************/
void GetList(int inList[], int& listsize, int maxlistsize)
{
    ifstream InFile("dupeList.txt");
    int ListElement;
    
    int i = 0;
    InFile >> ListElement;
    while(InFile && i < maxlistsize)
    {
        inList[i] = ListElement;
        i++;
        InFile >> ListElement;
    }
    listsize = i;        // Size of list is lastindex + 1
}

/************************************************************/
/* This function writes a list to console output:  one list */
/* item at a time.                                          */
/************************************************************/
void DisplayList(int theList[],int listsize)
{
    for (int i = 0;i < listsize; i++)
        cout << theList[i] << " ";
        
    cout << endl << endl;
} 