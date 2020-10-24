#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Pig{

public: 
  //The face values of the dice
  int die1;
  int die2;

  Pig(){
    //Class constructor. Give the dice an initial roll here
	  roll();
  }

  
  void roll(){
   //Roll behavior should set the 2 attributes to random 
   //numbers between 1 and 6
	  
	srand((unsigned)time(0));
	  die1 = (rand() % 6) + 1;
	srand((unsigned)time(0) * 1337);
	  die2 = (rand() % 6) + 1;

	  if (die2 == die1  ){
		cout << "Ooooh... bad roll" << endl;
	  }else{
		cout << "Rolled a " << die1 << endl;
		cout << "Rolled a " << die2 << endl;
	}
  }

  int score(){
    //The job of this behavior is to handle scoring
    //This function should return a value depending on what
    //is rolled. 

    //If the roll is a pair, return 0
	//If the roll is a pair of ones, return -1
	  if (die1 == die2){
		  if (die1 == 1){
			  // Snake eyes
			return -1;
		  }else{
			return 0;
		  }
	  }else{
		//If the roll is a non pair, return the sum of the 2 faces
		return (die1 + die2);
		}
	}
  void display(){
    //This should draw a pretty picture of the dice
    //The code is provided on Moodle
	if (die1 >= 1 && die1 <= 6){
		cout << "_______" << endl << "|     |" << endl << "|  " << die1 << "  |" << endl << "|     |" << endl << "_______" <<endl;
	}
	if (die2 >= 1 && die2 <= 6){
		cout << "_______" << endl << "|     |" << endl << "|  " << die2 << "  |" << endl << "|     |" << endl << "_______" <<endl;
	}
  }

};
