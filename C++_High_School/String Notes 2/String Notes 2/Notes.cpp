/*String Notes
At the end of these notes, you should be able to answer the following questions:

******Part 1*******
1. What is a char?
2. What is the relationship between a char and an integer?
3. What are ASCII values?
4. What is the relationship between a char and a string?
5. How can an entire line be read in at once ignoring the spaces?
6. How are strings similar to arrays?

******Part 2*******
7. What are the length(), find(), erase(), and substr() functions?
   Which ones return values and which ones are void?
8. How can two strings be joined (concatonated) together?
9. How can we convert a string to a number?

*/
#include <iostream>
#include <string>
#include <sstream> //Needed for string streams below.
using namespace std;

int main(){
	
	//char- the building blocks of strings 
	//(primitive data type like ints and doubles)
	//***********************************************

	//Declaring chars 
	cout << "CHAR EXAMPLES" << endl;
	char ch = 'a'; //Use  single quotes for a char
	cout << "ch = " << ch << endl;

	//Every char has a number value (see ACSII table)
	//so chars can be worked with like numbers
	ch = ch + 2;
	cout << "After adding 2, ch = " << ch << endl << endl;

	//Getting the the ASCII value of a char
	cout << "ASCII value of ch = " << int(ch) << endl << endl;

	//Getting outputting the char of an ASCII
	cout << "ASCII value of 65: " << char(65) << endl;
	//cout << "ASCII value of 7: " << char(7) << endl << endl;

	system("pause");

	
	//Strings
	//*********************************
	cout << endl << endl << "STRING EXAMPLES" << endl;

	//Declaring a string examples
	string s1;
	string s2 = "Chemic Pride";
	string s3 = ""; //declare to empty

	//Inputting an entire line
	cout << "Please type a few words: ";
	getline(cin, s1);
	cout << "You typed " << s1  << endl << endl;

	system("pause");

	//Strings are arrays of chars and can be treated as such
	cout << "Character 0 of s2 is " << s2[0] << endl << endl;
	

	//Loop through all the characters and make a change to spaces
	cout << "s2 with spaces replaced with underscores: " << endl;
	for(int i = 0; i < s2.length(); i++){
		if(s2[i] == 32){			//OR s2[i] == 32
			s2[i] = '_';
		}
	}
	cout << "After changing, s2 = " << s2 <<endl << endl;


	//String functions
	//****************

	//Length
	cout << endl << endl << "STRING FUNCTION EXAMPLES" << endl;
	cout << "The length of s2 is: " << s2.length() << endl;

	//Substr
	string s4 = s2.substr(7, 5); //7 = start, 5 = how many
	cout << "s2.substr(7, 5) = " << s4 << endl << endl; //s4 = Pride

	//Erase
	s4.erase(3, 2); //Starting at index 3, erase 2 chars ->s4 = Pri
	cout << "After erasing indexes 3 and 4, s4 = " << s4 << endl << endl;

	//Find
	int x = s2.find("mic"); //Returns index of found location -> 3
	cout << "In Chemic Pride, mic was found at position " << x << endl << endl;


	//String concatonation (+)
	//*************************
	string s5 = s2 + ", A Very Special Tradition!";
	cout << "After concatonation s5 = "<<  s5 << endl << endl;

	//Converting a string to a number
	//*******************************************
	string str = "123";
	int num = 0; //We want y to hold the numerical value 123

	stringstream ss;
	ss << str;
	ss >> num;  //num now holds 123
	ss.clear(); //clear ss for next use

	cout << num - 100 << endl;

	//Note that stringstreams can be used in reverse to convert number to a string


	system("pause");
	return 0;
}
