#include <cstdlib>; //C++ standard library of functions
#include <ctime>;   //Functions to interact with clock
#include <iostream>;
//#include <string>; // Psssh...

using namespace std;

int Compair(int Player, int Computer);
void WinCheck(int sp, int sc);

// Press any key to continue . . .

int main(){
	srand((unsigned)time(0));
	int RandNum = rand() % 3 + 1;

	int sp, sc, Winner;
	
	sp = 0;
	sc = 0;
	cout << "Rock, Paper, Scissors!" << endl;

	// Get it in!
	while (sp < 5 && sc < 5 ){
		int RandNum = rand() % 3 + 1;
		int RandNum2 = rand() % 3 + 1;
		int tp;
		tp =RandNum2;
		//cout << "Pick your move! (Rock(1) Paper(2) or Scissor(3)): ";
		//cin >> tp;
		
		int tc = RandNum;
		// Out the turns
		cout << endl << "Player Picked " << tp << endl << "Computer Picked " << tc << endl;
		//989 513 6027 = call and harras this number LOL
		// Compair turns

		Winner = Compair(tp, tc);
		if (Winner == 2){
			cout << "Tie!" << endl;
		}else if (Winner == 1){
			sp++;
			cout << "Player won!" << endl;
		}else{
			sc++;
			cout << "Computer won!" << endl;
		}
		WinCheck(sp, sc);
	}
	system("Pause");
	return 0;
}
void WinCheck(int sp, int sc){
	// check for wins
	if (sc >= 5)
		cout << endl << "Player wins the game" << endl;
	else if (sp >= 5)
		cout << endl << "Computer wins the game" << endl;

}
int Compair(int Player, int Computer){
	// Compair the numbers
	int Pvict;
	Pvict = 0;
		// Compair the stuff son, lol
	if ((Player == 1 && Computer == 3) || (Player == 2 && Computer == 1) || (Player == 3 && Computer == 2))
		Pvict = 1;
	else if (Player == Computer)
		Pvict = 2;

	return Pvict;
}