// Template
// Includes
#include <algorithm>	// Algorithms >.>
#include <cmath>		// Basic Math Operations
#include <cstdlib>		// control of stdlib
#include <cstring>		// Maniplulation of strings
#include <ctime>		// Time stuff
#include <fstream>		// File stream (I/O)
#include <iomanip>		// Manipulation of I/O
#include <iostream>		// Input\Output
#include <sstream>		// String stream
#include <stdio.h>		// Stuff For random numbers
#include <stdlib.h>		// Standard Library
#include <string>		// String Stuff
#include <time.h>		// More time stuff
#include <vector>		// Vectors


using namespace std;
// Lead
void file_read();
void setup();
void sleep(unsigned int mseconds);
void commands();
// Variables
vector<string> indstr;

int main(){
	// Main
	setup();
	commands();
	/*
	// File In\Out
	ifstream fin("u:\\in.txt");
	ofstream fout("u:\\out.txt");
	*/


	system("Pause");
	return 0;
}
void file_read(string fpath){
	// Read in a file
	int x = 0;
	vector<double> indbl;
	/*public: static bool Exists(
 String* path
);
*/

	if ( !fpath.find(char(46)) ){
		fpath = "u:\\in.txt";
		cout << "Invalid file path!" << endl;
	}
	ifstream fin(fpath);

	while (!fin.eof()){
		string ind = "";
		getline(fin, ind);

		// Store it
		indstr.push_back(ind);

		x++;
	}

	fin.close();

}
void setup(){
	// Setup
	system ("Title [ Console Application ]");
	system ("Color 07");
	cout << "Console Application Template" << endl << endl;
}
void sleep(unsigned int mseconds){
	// Sleep...
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void commands(){
	// Accept commands
	bool go = 1;
	// Start a loop
	while(go){
	string order = "", instr = "";

	cout << endl << "Input a command (clear, thetime, thetime2, stop):  ";
	cin >> instr;
	order = instr.substr(0, instr.find_first_of(char(32)));

	if (order == "clear"){
		// Clear lol
		system ("cls");
		setup();
	}else if (order == "thetime"){
		cout << "The time is currently:";
		system ("echo %time%");
	}else if (order == "thetime2"){
		time_t rawtime;
		time(&rawtime);
		string curtime = ctime(&rawtime);
		cout << "The current time/date is:" << endl << curtime << endl;
	}else if (order == "stop"){
		bool usure = 0;
		cout << endl << "Are you sure you want to quit? (1 = Yes, 0 = No): ";
		cin >> usure;
		if (usure == 1){
			go = 0;
		}else{
			cout << endl << "~ Choose not to quit" << endl;
		}
	}else if (order == "pause"){
		system ("pause");
	}else{
		cout << endl << "The command couldnt be used (Not valid?)" << endl;
	}
	/*
	x = a * b
	y = a + b
	z = x % y
	if (z = ##?)
	*/
	//system("wmplayer.exe C:\Documents and Settings\All Users\Documents\My Music\Sample Music\New Stories (Highway Blues).wma");
	} // End loop
}