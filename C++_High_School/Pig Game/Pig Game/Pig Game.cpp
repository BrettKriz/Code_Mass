// Template
// Includes
#include <iostream>		// Input\Output
#include <iomanip>		// Manipulation of I/O
#include <string>		// String Stuff
#include <cstring>		// Maniplulation of strings
#include <cstdlib>		// 
#include <sstream>		// String stream
#include <fstream>		// File stream (I/O)
#include <cmath>		// Basic Math Operations
#include <vector>		// Vectors
#include <algorithm>	// Algorithms >.>
#include <ctime>		// Time stuff
#include <stdlib.h>		// Standard Library
#include <time.h>		// Time styuf
#include "Pig.h"		// PIGS


using namespace std;

// Lead
void setup();
void commands();
void gameitup();
int winner_check(bool force, double playaS, double NPCS);
void sleep(unsigned int mseconds);

bool playersturn = true;
int playerS = 0, compS = 0, MaxS = 50;
Pig dice;

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

void setup(){
	// Setup
	system ("cls");
	system ("Title [ PIG GAME! ]");
	system ("Color 07");
	cout << "PIG dice game" << endl << endl;
}
void commands(){
	// Accept commands
	bool go = 1;
	// Start a loop
	while(go){
	string order = "", instr = "";

	cout << endl << "Input a command (clear, stop, play):  ";
	cin >> instr;
	order = instr.substr(0, instr.find_first_of(char(32)));

	if (order == "clear"){
		// Clear lol
		system ("cls");
		setup();
	}else if (order == "stop"){
		bool usure = 0;
		cout << endl << "Are you sure you want to quit? (1 = Yes, 0 = No): ";
		cin >> usure;
		if (usure == 1){
			go = false;
		}else{
			cout << endl << "~ Choose not to quit" << endl;
		}
	}else if (order == "play"){

		gameitup();
	}else{
		cout << endl << "The command couldnt be used (Not valid?)" << endl;
	}
	} // End loop
}
void gameitup(){
		bool rollit = true, doneson = false;
		int playaS = 0, NPCS = 0, x = 0;

		srand((unsigned)time(0) * 21);

		cout << "2 games" << endl;

	while (!doneson || x > 2){
		cout << "Changing turn..." << endl << endl;
		rollit = true;
		if (playersturn == true) {
			// Roll, ask if they want to roll agian
		system("pause");
			while (rollit){
				dice.roll();
				dice.display();

				int lescore = 0;
					lescore = dice.score();
					if (lescore == -1){
						cout << "Snake Eyes! lost all points" << endl;
						playaS = 0;
						playerS = 0;
						playersturn = false;
						break;
						break; // rounds over
					}else if (lescore == 0){
						cout << "Pairs" << endl;
						playaS = 0;
						playersturn = false;
						break;
					}else cout << "Scored: " << lescore << endl;

				playaS = playaS + lescore;

				int rar = 0;
				winner_check(false, playaS, NPCS);
				if (rar == 1) break;

				int lol = 0;
				cout << "Roll again? (0 = Yes, 1 = No)";
				cin >> lol;
				if (lol){
					rollit = false;
					playersturn = false;
				}
			}
		// NPC turn
		}else if (playersturn == false){
			// NPCs play
			cout << "Computers turn" << endl;
			while (rollit){
					sleep(500);
					dice.roll();
					dice.display();

					int lescore = 0;
					lescore = dice.score();

					if (lescore == -1){
						cout << "Snake Eyes! lost ALL points!" << endl;
						compS = 0;
						playersturn = true;
						break;
					}else if (lescore == 0){
						cout << "Pairs! lost all points this round!" << endl;
						playersturn = true;
						break;
					}else cout << "Scored: " << lescore << endl;

					NPCS = NPCS + lescore;

					int rar = 0;
					winner_check(false, playaS, NPCS);
					if (rar == 1) break;
						
					// a 4 in 9 chance they wont be greedy
					srand((unsigned)time(0) * 5);
					int lol = (rand() % 11);
					if (lol < 5 ){
						cout << "Computer has decided not to roll" << endl;
						rollit = false;
						playersturn = true;
					}else{
						cout << "Computer has decided to roll again" << endl;
					}
			}// end of rollit
		}// End of player turn
		// Done yet?
		// Done, add round score
	if (x > 2) doneson = true;

	if (doneson){
		playerS = playerS + playaS;
		cout << endl << "Player earned: (oiginal)" << playerS << " + (this round)" << playaS << endl;
		compS = compS + NPCS;
		cout << "Computer earned: (original)" << compS << " + (this round)" << NPCS << endl;

		NPCS = 0;
		playaS = 0;
		break;
	}
	x++;
	//doneson = true;
	}// end of doneson
	
}
int winner_check(bool force, double playaS, double NPCS){
	// Check it
	int rar = 0;
	if (force){
		rar = 1;
	if (playaS < NPCS)
			cout << "Player wins this round!" << endl;
		else if (playaS > NPCS)
			cout << "Player wins this round!" << endl;
		else
			cout << "Tie round!" << endl;

	}else{
		if (playaS == MaxS || NPCS == MaxS){
			rar = 1;
			if (playaS < NPCS)
				cout << "Player wins this round!" << endl;
			else if (playaS > NPCS)
				cout << "Player wins this round!" << endl;
			else
				cout << "Tie round!" << endl;
		}
	}
	return rar;
}
void sleep(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}