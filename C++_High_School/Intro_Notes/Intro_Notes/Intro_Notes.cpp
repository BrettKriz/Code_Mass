//C++ INtro Notes
/*
	Comments( 2 methods): comments are denoted by either using // or
	opeing and closing a comment with /* (called C-Style comments)
*/

// Header files add functionality (commands) to program
#include <iostream>		// Console input/output
#include <cmath>		//Advanced math operations
#include <string>		// Strings
#include <iomanip>		// Output formatting

using namespace std;	// must be included to define scope of variables
				// STD stands for >>> standard <<<
				// ;D
// Define the main program - - MUST be called main()
// {} Denote the beginning and end of function's code
int main() {

	// Print message to console and end the line
	// ALL executed lines must end with a ;
	cout << "Hello World!" << endl; // endl = end line
	// C Out operator, Prints to screen


	// Create 3 number variables
	int num1;				//Declare alone
	double num2, num3 = 5;	//Declare as group w/ commas and optional variables

	// Unlike VB, variables are not automatically 0
	cout << num1 << " " << num3 << endl;

	//Getting input from the user
	cout << "Please enter a number: ";
	cin >> num1; // no endl because you cant input an end line
	cout << endl << "You entered: " << num1 << endl;
	//When it is cout then the arrows point out and away from the variable but what its cin the arrows point to the variable


	//Math operators demo =, -, =, / ... no ^
	num1 = 1;
	num2 = 2;
	num3 = num3 + num2 * num1 - 9 / 3;




	// String Variables (Need <string>)
	string str = "Hello";
	cout <<str << endl;

	// Formating numerical output
	/*not sci. Not. | Always show dec. pt.| align left */
	cout.setf(ios_base::fixed | ios_base::showpoint| ios_base::left);
	cout << setprecision(3); // Set output to 3 decimals


	cout << "Rounded to 3 decimals" << 3.0/2.0 << endl;

	//Wait for user to press a key
	system ("pause");
	// end the main function
	return 0;

}