#include <iostream>

using namespace std;

int main(){

	/*
	RELATIONAL OPERATORS:
	> -greater than
	< -less than
	>= -gr or eq. to
	<= -lt or eq. to
	!= -Not equal
	== -Equal to (2 = signs)

	*/

	int x, y; 
	cin >> x; 
	cin >> y;

	//If
	if(x == 0){
		cout << "x == 0" << endl;
	
	}
	//If/else
	if(x == 0){
		cout << "x == 0" << endl;
	}else{
		cout << "x != 0" << endl;
	}

	//If/elseif/else (of course we can have multiple else ifs)
	if(x == 0){
		cout << "x == 0" << endl;
	}else if (x == 1){
		cout << "x == 1" << endl;
	}else{
		cout << "x != 0 and x != 1" << endl;
	}//end if

	//LOGICAL OPERATORS
	// && -AND
	// || -OR
	// !  -NOT
	//( ) -Parentheses
	//******************
	int i = 1, j = 2, k = -1;

	//and
	if (i == 1 && k == -1){
		cout << "i and k are 1" << endl;
	}

	//or
	if (i ==1 || i == -7){
		cout << "i is 1 or -7" << endl;
	}

	//not
	if (!(i == 5 || i == -7)){
		cout << "i is NOT 5 or -7" << endl;
	}

	//op precedence
	//&& is evaluated before or unless you use parentheses
	if ((i == 3 || j == 2) && k == 3){
		cout << "always false since && is eval. 1st" << endl;
	}

	//1 liners
	double grade = 85;

	if(grade >= 90) cout << "A" << endl;
	else if(grade >= 80) cout << "B" << endl;
	else if(grade >= 70) cout << "C" << endl;
	else if(grade >= 60) cout << "D" << endl;
	else if(grade >= 50) cout << "E" << endl;
	else cout << "very bad" << endl;

	/* OR even
	if(grade >= 90)
		cout << "A" << endl;
	else if(grade >= 80)
		cout << "B" << endl;
	else if(grade >= 70)
		cout << "C" << endl;
	else if(grade >= 60)
		cout << "D" << endl;
	else if(grade >= 50)
		cout << "E" << endl;
	else
		cout << "very bad" << endl;
	*/
	//C++ switch statement (only works with ints, chars, bools)
	int input;
	cin >> input;
	// Without breaks, it will check every case
	switch(input){
		case 1:
			cout << "input is 1" << endl;
			break;
		case 2:
			cout << "input is 2" << endl;
			break;
		case 3:
			cout << "input is 3" << endl;
			break;
		default:
			cout << "input is not 1, 2 or 3" << endl;
	}
		



	system("pause");
	return 0;
}
