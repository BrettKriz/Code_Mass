// Template
// Includes
#include <algorithm>	// Algorithms >.>
#include <cmath>		// Basic Math Operations
#include <cctype>		// Type booling for chars (isspace, isalpha, isdigit)
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
void body();
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
// Body of code
void body(){





}
void file_read(string fpath){
	// Read in a file
	int x = 0;
	vector<double> indbl;
	
	/*
	public: static bool Exists(
	String* path
		);
		*/

	if ( !fpath.find(char(46)) ){
		fpath = "in.txt";
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
	system ("Color 0A");
	cout << "Console Application Template" << endl << endl;

	// Get the system time.
   unsigned seed = time(0);
   // Seed the random number generator.
   srand(seed); 

}
void sleep(unsigned int mseconds){
	// Sleep...
	system("cls");
	system("color 03");
	system("echo Yawn! Goodnight! %time%");

    clock_t goal = mseconds + clock();
    while (goal > clock());

	system("echo .");
	system("echo .");
	system("echo .");
	system("echo Good Morning! %time%");

	system("color 0A");
}
void commands(){
	// Accept commands
	bool go = 1;
	// Start a loop
	while(go){
	string order = "", instr = "";

	cout << endl << "Input a command (clear, body, switchtitle, thetime, thetime2, sleep, stop):  ";
	cin >> instr;
	order = instr.substr(0, instr.find_first_of(char(32)));

	if (order == "clear"){
		// Clear lol
		system("title ~ ... ~");
		system ("cls");
		setup();

	}else if (order == "switchtitle"){
		int y = 6, roll = (rand()%6) + 1;

		switch(roll){ // Breaks needed at the end of each case or default!! Otherwise it will run into other cases
			case 1: {system("title ~ You think thats AIR you're breathing? ~"); break;}
			case 2: {system("title ~ Thanks for the keyboard massage ~"); break;}
			case 3: {system("title ~ 3 Blind guys walk into a bar ~"); break;}
			case 4: {system("title ~ Ya ever just get stuff done before its due? ~"); break;}
			case 5: {system("title ~ The spoon isn't real ~"); break;}
			case 6: {system("title ~ I really need to think of better titles ~"); break;}
			default: {system("title ~ I Dunno LOL ~"); break;}
		}
	}else if (order == "thetime"){
		system("title ~ The time currently is %time% ~");

		cout << "The time is currently:";

		system ("echo %time%");
	}else if (order == "sleep"){
		system("title ~ Yawn! Good Night ~");
		double zzz;
		cout << endl << "How long should I sleep? (SECONDS): ";
		cin >> zzz;

		zzz = zzz*1000;

		
		sleep(zzz);
	}else if (order == "thetime2"){
		system("title ~ The time currently is %time% ~");

		time_t rawtime;
		time(&rawtime);
		string curtime = ctime(&rawtime);

		cout << "The current time/date is:" << endl << curtime << endl;
	}else if (order == "stop"){
		bool usure = 0;

		system("title ~ Leaving so soon? ~");

		cout << endl << "Are you sure you want to quit? (1 = Yes, 0 = No): ";
		cin >> usure;

		if (usure == 1){
			go = 0;
		}else{
			cout << endl << "~ Choose not to quit" << endl;
		}
	}else if (order == "pause"){
		system("title ~ STOP!	Hammer Time ~");
		system ("pause");

	}else if (order == "body"){
		system("title ~ BODY ~");
		body();
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