/*------------------------------------------

	Brett Kriz
	Student Class
	

-------------------------------------------*/
// Include
#include <cmath>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>		// File stream (I/O)



using namespace std;

//Proto
//bool doover(bool b); // 1 proto

class Student{
	private:
	// VARIABLES
	string fname, lname;
	char minit;
	int score1, score2, score3, absences;
	// FUNCTIONS
	bool doover(bool b);// For Loops! Checks if false, prompts user to re-enter; Returns the input bool

	// @PUBLIC
	public:
	// @FUNCTIONS
		// Contstructors
	Student();
	Student(string fn, char mi, string ln, int s1, int s2, int s3, int a);
	Student(char to_ask_user); // Just to change how its stacked
		// Gets
	char getMInit();
	string getFName();
	string getLName();
	int getScore1();
	int getScore2();
	int getScore3();
	int getAbsences();
	
		// Sets
	void setMInit( char i = ' ' );
	void setFName( string s = "" );
	void setLName( string s = "" );
	void setScore1( int n = -1 );
	void setScore2( int n = -1 );
	void setScore3( int n = -1 );
	void setAbsences( int n = -1 );
		// Other
	double getFinal();
	double getAverage();
	string getLetterGrade(double tot = -1);
	string gageSuccess(double f);
	void Print();
};

// @Constructors
Student::Student(char to_ask_user){ // Menu creation style
	// char doesnt matter
		setFName();
		setMInit();
		setLName();

		setScore1();
		setScore2();
		setScore3();
		setAbsences();
	
}
Student::Student(){
	fname = "";
	char minit = ' ';
	lname = "";

	score1 = 0;
	score2 = 0;
	score3 = 0;
	absences = 0;
}
Student::Student(string fn, char mi, string ln, int s1, int s2, int s3, int a){
	fname = fn;
	minit = mi; // Edit this area
	lname = ln;

	score1 = s1;
	score2 = s2;
	score3 = s3;
	absences = a;
}
// @PRIVATE
bool Student::doover(bool b){
	if (b == true){ // For while loops
		//system("cls");
		cout << "\nBad Input! Please re-enter!\n";
		cin.clear();
	}
	return b;
}


// @GETS 
void Student::setMInit(char i){
	cin.clear();
	string n = ""; // for answer processing

	if (isalpha(i)){
		minit = i;
		return;
	}

	do{
		cout << "\nPlease enter Initial: ";
		cin >> n;
		i = n.c_str()[0]; // Remove char
		cout << endl;
	}while( doover( !isalpha(i) || i == ' ' ) );

	minit = i;
	cout << endl;
}
void Student::setFName(string s){ // overload for file in
	cin.clear();
	
	if (s.size() > 3) {
		fname = s;
		return;
	}

	cout << "\nPlease enter First Name: ";
	cin >> s;

	fname = s;
	cout << endl;
}
void Student::setLName(string s){	
	cin.clear();

	if (s.size() > 3) {
		lname = s;
		return;
	}

	cout << "\nPlease enter Last Name: ";
	cin >> s;

	lname = s;
	cout << endl;
}
void Student::setScore1(int n){	
	// int n = -1; // Trickledown With Error Precention
	cin.clear();
	if (n >= 0 && n <= 100){
		score1 = n;
		return;
	}

	do{
		cout << "\nPlease enter Score1: ";
		cin >> n;
		cout << endl;
	}while( doover(n<0 || n>100) );

	score1 = n;
	cout << endl;
}
void Student::setScore2(int n){	
	// int n = -1; // Trickledown With Error Precention
	cin.clear();

	if (n >= 0 && n <= 100){
		score2 = n;
		return;
	}

	do{ // If 'n' wasnt actually given , ask for it!
	cout << "\nPlease enter Score2: ";
	cin >> n;
	}while( doover(n<0 || n>100) );

	score2 = n;
	cout << endl;
}
void Student::setScore3(int n){	
	// int n = -1; // Trickledown With Error Precention
	cin.clear();

	if (n >= 0 && n <= 100){
		score3 = n;
		return;
	}

	do{ // If 'n' wasnt actually given , ask for it!
	cout << "\nPlease enter Score3: ";
	cin >> n;
	}while( doover(n<0 || n>100) );

	score3 = n;
	cout << endl;
}
void Student::setAbsences(int n){	
	// int n = -1; // Trickledown With Error Precention
	cin.clear();

	if (n >= 0 && n <= 365*4){
		absences = n;
		return;
	}

	do{ // If 'n' wasnt actually given , ask for it!
	cout << "\nPlease enter Absences: ";
	cin >> n;
	}while( doover(n < 0 || n > 365*4) );

	absences = n;
	cout << endl;
}

// @GETS
char Student::getMInit(){
	return minit;
}
string Student::getFName(){
	return fname;
}
string Student::getLName(){
	return lname;
}
int Student::getScore1(){
	return score1;
}
int Student::getScore2(){
	return score2;
}
int Student::getScore3(){
	return score3;
}
int Student::getAbsences(){
	return absences;
}

// @OTHER FUNCTIONS
double Student::getAverage(){ // The literal average
	return  ( score1 + score2 + score3 )/3.0 ;
}
double Student::getFinal(){ // The number for percent display/total score
	int xtra = 0;
	if (absences == 0){
		xtra = 2;
	}
	return (( score1 + score2 + score3 )/300.0)*100 + xtra;
}
string Student::gageSuccess(double f){
	if (f >= 73){ // Greater than or equal to a 'C'
		return "Successful!";
	}else{
		return "Unsuccessful..";
	}
}
void Student::Print(){

	cout << "\nName: "			<< getFName() << " " << getMInit() << ". " << getLName()
		 << "\nTest Average: "	<< getAverage()
		//<< "\nScore1: "		<< getScore1()
		//<< "\nScore2: "		<< getScore2()
		//<< "\nScore3: "		<< getScore3()
		 << "\nAbsences: "		<< getAbsences()
		 //<< "\nFinal Grade: "	<< fixed << setprecision(2) << getFinal() << "%"
		 << "\nLetter Grade: "	<< getLetterGrade()
		 << "\n\t"				<< gageSuccess(getFinal())
		 << endl;
} // End Print

string Student::getLetterGrade(double arg){
	string ans = "F"; // Default it

	if (arg == -1) { // Handle unsent info :D
		arg = getFinal();
	}

	
	if (arg > 100){
		ans = "A+";

		//A
		//93.0% - 100%
	}else if( arg >= 93.0 && arg <= 100 ){
		ans = "A";

		//A-
		//90.0% - 92.99%
	}else if( arg >= 90 && arg < 93 ){
		ans = "A-";

		//B+
		//87.0% - 89.99%
	}else if( arg >= 87 && arg < 90 ){
		ans = "B+";

		//B
		//83.0% - 86.99%
	}else if( arg >= 83 && arg < 87 ){
		ans = "B";

		//B-
		//80.0% - 82.99%
	}else if( arg >= 80 && arg < 83 ){
		ans = "B-";

		//C+
		//77.0% - 79.99%
	}else if( arg >= 77 && arg < 80 ){
		ans = "C+";

		//C
		//73.0% - 76.99%
	}else if( arg >= 73 && arg < 78 ){
		ans = "C";

		//C-
		//70.0% - 72.99%
	}else if( arg >= 70 && arg < 73 ){
		ans = "C-";

		//D+
		//67.0% - 69.99%
	}else if( arg >= 67 && arg < 70 ){
		ans = "D+";

		//D
		//60.0% - 66.99%
	}else if( arg >= 60 && arg < 67 ){
		ans = "D";
	} // I guess no D- then...
	//F
	//Below 60.0%

	return ans;
}