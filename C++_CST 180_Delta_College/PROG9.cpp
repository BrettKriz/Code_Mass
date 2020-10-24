
/*------------------------------------------

	Brett Kriz
	Program 8.2 AKA 9

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

// Variables
const int ARRAY_SIZE = 250;
struct List{ // Nice struct for lists
	int size;
	Student students[ARRAY_SIZE]; 
};


void body(); //Module of program, for repetition if needed
void sleep(unsigned int mseconds = 250);// Sleep for slower outputs mostly
void printall(List s);	// Prints all the students in s[]
int upd(int& n);						// unbugable ++iterator, ++x is prone to certian code step problems :/
void resetpanel(bool cls = true);		// default to true/use clear screen
string trim(const string &t); // trims the string of leading and ending space

string token_burn(string& line, string den, int lookat = 0); // Shortens the line by finding the next den, returns a token string
bool Read_IN(List& data, string des = "studentdata.txt");

int main()
{
	
	resetpanel();
	body();

	cout << "\n";
	system("pause");
	return 0;
}
void resetpanel(bool cls){

	system("color F0");
	system("title PROGRAM 9: Student Class v2");
	if (cls) {
		system("cls");
		cin.clear();
	}else{
		cout << "\n";
		cin.clear();
	}
}
// Code Body
void body(){
	// VARIABLES
	int x = 0, size = 0;
	bool go = true;
	List data;
	data.size = 0;  
	string arg = "";

	// WORK
	Read_IN( data );	// Read in data
	resetpanel();		// Just fo decoration
	
	do{ // LOOP for a menu
		
		cout << "\nWould you like to (add,view,exit)?: ";
		cin >> arg;
		cin.clear();

		if (arg.find("add") < arg.npos){ // npos for not found
			Student cur(true); // tag it for clients to fill
			data.students[ upd(data.size) ] = cur;
			sleep();
		}else if(arg.find("view")<arg.npos){	// DISPLAY
			system("cls");
			printall(data); //  PRINT ALL RECORDS
			sleep(1000);
		}else if(arg.find("exit")<arg.npos){	// EXIT
			go = false; // Itll just stop this loop
		}else{
			cout << "\n\n\t What? I dont know what that means!\n";  // bad in
			sleep();
		}
			

	}while(go); // end menu

}
void printall(List s){
	int x = 0;
	while(x < s.size){
		s.students[x].Print(); // Print record
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
	n++; // I know, I know "Just use ++n!", but that was messin up!!
	return nn;
}
string trim(const string &t){
    string ans = t;
    size_t found;
    found = ans.find_last_not_of( " \n\r\t" ); // find Whitespace

    if (found != t.npos){
    	ans.erase( found + 1 );
	}else{
    	ans.clear(); // str is whitespace
	}

    return ans;
}
string token_burn(string& line, string den, int lookat){
		//Trim
		line = trim(line);

		int pos = line.find( den, lookat ), x = 0; 
		string z = "";
		// Show where the break will occure
		// Under the text!           ^
		while(x < pos){z += " "; x++;}
		z += "^";// HERE

		//cout << line << "\n" << z << "\n";

		string token = line.substr( 0 , pos );
		line = line.substr( pos + 1 ); // till end
		

		//cout << line << "\n\"" << token <<  "\"" 
			//<< endl;

		sleep(20);
	return token;
}
bool Read_IN(List& data, string des){
	
	system("title Program 9: Read in Student List");
	ifstream IN;
	int x = 0;
	bool good = true;
	
	IN.open(des); // Modularity >:3
	//cout << endl;

	if (IN.is_open()){
			system("color F8");
			

			while(!IN.eof()){
				// Variables
				Student cur = Student(); // Student Variable
				char rawline[ 256 ];
				string s = ",", line = "", den = ",";

				// Work
				IN.getline( rawline, 256 );	// snag all vic C string
				line = string(rawline);		// create string
				
				if (line.length() < 3 ){
					// ABORT Read, bad line
					break;
				}

				// Token_Burn was such a good idea
				// 5 , then newline = 6
				string t1, t2, t3, t4, t5, t6;
				// TOKENIZE ME CAPTIN!
				t1 = token_burn( line, den, 3 ); // Last
				line = line.substr(1); // Space...
				t2 = token_burn( line, den, 2 ); // First & Middle
				t3 = token_burn( line, den, 0 ); // Score 1
				t4 = token_burn( line, den, 0 ); // Score 2
				t5 = token_burn( line, den, 0 ); // Score 3
				t6 = line;		 // Absences (The remaindedr)
		
				cout << "\n RAW #"				<< x 
					 <<			" ~~~~~~~~~~~~~~~~~~~~"
					 << "\n LName: >"			<< t1	<< "<"
					 << "\n First & Middle: >"	<< t2	<< "<"
					 << "\n Score1: >"			<< t3	<< "<"
					 << "\n Score2: >"			<< t4	<< "<"
					 << "\n Score3: >"			<< t5	<< "<"
					 << "\n Absences: >"		<< t6	<< "<"
					 << endl;
				
				// Work with the data
				char m = t2.substr( t2.size() - 2).c_str()[0];
				string first = t2.substr( 0, t2.find_first_of(' '));


				// Set
				cur.setLName( t1 );
				cur.setMInit( m );
				cur.setFName( first );

				cur.setScore1( atoi(t3.c_str()) );
				cur.setScore2( atoi(t4.c_str()) );
				cur.setScore3( atoi(t5.c_str()) );
				cur.setAbsences( atoi(t6.c_str()) );
				// atoi(line.c_str());

				// Save it!
				data.students[x] = cur;
				x++; // yup increment
				sleep( 50 );
			} // end loop

		cout << "\n Student read in complete!\n\n";
		data.size = x; // Store size

		//system("pause");
		sleep(950);
		
	
	}else{ // not Open?
		cout << "\n\nInput File is empty!\n\t Check path!\a\n";
		good = false;
	}// end if

	IN.close();// Better close that...
	return good;
}// end func
