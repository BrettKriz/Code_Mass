// Function Notes

/*
Function Basics:
1. Goal 1: Save time by reusing code
2. Goal 2: Break up a complex task into smaller tasks
*/

#include <iostream>
#include <cmath>
using namespace std;

//Prototypes, lets c++ know functions are below
//Paste in the function header with a semi-colion
void example1();
void example2(int param1, int param2);
double QuadFormula(int a, int b, int c);
void valVsRef(int x, int& y);

int main(){

	//Call Example 1
	example1();

	//Call Example 2
	example2(1,1);
	
	//Call Example 3
	int i = 2, j = 3, k = 1;
	double answer = QuadFormula(i, j, k);	//Store return in 'answer'
	//or
	cout << QuadFormula(3, 5, 2) << endl;

	//Call byValExample
	int a = 0, int b = 0;
	valVsRef(a, b);
	//Passing b ByRef means that the function has permission
	//to change it, a is only copied
	cout << "After the call, a = " << a << " b = " << b << endl;



	system("Pause");
	return 0;
}
// Function Declarations
void example1(){
	cout << "Welcome to example1" << endl;
	// More code if desired
	// Void means DO NOT return a value
}
void example2(int param1, int param2){
	if (param1 > param2)
		cout << "Player 1 wins" << endl;
	else if (param1 < param2)
		cout << "Player 2 wins" << endl;
	else
		cout << "Tie" << endl;
}
double QuadFormula(int a, int b, int c){
	double x = (-b + sqrt(pow(b, 2.0) - 4*a*c) ) / (2*a);

	//Return specifices the value to be sent back
	// Only 1 value can be returned
	//Return immediately ends the function
	return x;
}
//By value Vs By Reference paramters

//By Value nakes a copy of the parameter
//By Reference sends the actual variable - not a copy
void valVsRef(int x, int& y){
	x = 10000;
	y = 10000;
}
