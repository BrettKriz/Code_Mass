
/*------------------------------------------

	Brett Kriz
	Program 8

-------------------------------------------*/
#include <algorithm>	// Algorithms >.>
#include <cmath>		// Basic Math Operations
#include <cstdlib>		// control of stdlib
#include <cstring>		// Cstrings
#include <ctime>		// Time stuff
#include <ctype.h>		// typeing
#include <fstream>		// File stream (I/O)
#include <iomanip>		// Manipulation of I/O
#include <iterator> 
#include <iostream>		// Input\Output
#include <sstream>		// String stream
#include <stdlib.h>		// Standard Library
#include <string>		// String Stuff
#include <string.h>		// String Stuff
#include <time.h>		// More time stuff

#include "Student.h"
// SEE HEADER


using namespace std;
void body();
void sleep(unsigned int mseconds = 250);
void printall(Student s[], int size);
int upd(int& n);

int main()
{
	system("color F0");
	system("title PROGRAM 8: Student Class");

	body();

	cout << "\n";
	system("pause");
	return 0;
}
// Code Body
void body(){
	int x = 0, size = 0;
	bool go = true;

	Student all[50];
	// Create a table of students, then add
	all[upd(size)]	= Student("Starter Student","1010", 75,85,95,1);
	all[upd(size)] = Student("Stu Little", "8008", 45,55,65,0);
	all[upd(size)] = Student("AJ", "125", 25,25,25,1);
	all[upd(size)] = Student("Claude Speed", "2001", 25,75,75,3);
	all[upd(size)] = Student("Alice Wounder", "165", 25,25,25,135);
	all[upd(size)] = Student("Erins Neverdone", "205", 35,25,11,0);
	all[upd(size)] = Student("Brett K", "305", 25,25,25,8);
	all[upd(size)] = Student("BURR SWAG", "40585", 25,50,25,10);
	all[upd(size)] = Student("Fox Bob", "507", 25,25,25,20);
	all[upd(size)] = Student("Klondike Smith", "555", 98,95,66,100);
	all[upd(size)] = Student("Ender Student ~ SEE BELOW FOR ADDED", "5075", 25,25,25,100);

	string arg = "";

	do{ // LOOP for a menu
		
		cout << "\nWould you like to (add,view,exit)?: ";
		cin >> arg;
		cin.clear();

		if (arg.find("add") < arg.npos){ // npos for not found
			Student z(true); // tag it for client 
			all[size] = z;
			size++;
			sleep();
			//size++;
		}else if(arg.find("view")<arg.npos){
			system("cls");
			printall(all,size); //  PRINT ALL RECORDS
			sleep(1000);
		}else if(arg.find("exit")<arg.npos){
			go = false; // Itll just stop this loop
		}else{
			cout << "\n\n\t What? I dont know what that means!\n";  // bad in
			sleep();
		}
			

	}while(go); // end menu

}
void printall(Student s[], int size){
	int x = 0;
	while(x < size){
		s[x].Print(); // Print record
		x++;
		sleep(); // Fo decoration
	}
}
void sleep(unsigned int mseconds){
	// Sleep...
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int upd(int& n){
	int nn = n;
	n++;
	return nn;
}
