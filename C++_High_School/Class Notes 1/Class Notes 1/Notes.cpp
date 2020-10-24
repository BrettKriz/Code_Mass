#include<iostream>
#include"BankAccount.h" //include the header file we made

using namespace std;


int main(){
	//Create a couple of bank accounts
	//Note that the constructor will automatically be called
	BankAccount b1, b2, b3;

	/*
	Notes:
	-BankAccount is a CLASS (a blueprint)
	-B1 and B2 are OBJECTS (created from the class)
	-B1 and B2 each have their own name, balance, and transaction history
	*/

	//Example transactionss with the accounts
	b1.deposit();// Change balance
	b1.withdraw();// lol
	b1.display();

	b2.deposit();
	b2.withdraw();
	b2.display();

	b3.deposit();
	b3.withdraw();
	b3.display();

	cout << "Its going to get ugly..." << endl << endl;
	//Show the transaction history for both accounts
	b1.intrest(0.05);
	b1.showHistory();
	b2.intrest(0.06);
	b2.showHistory();
	b3.intrest(0.07);
	b3.showHistory();

	//Get the current balances
	cout << b1.accountname << "= " << b1.balance << endl;
	cout << b2.accountname << "= " << b2.balance << endl;

	system("pause");
	return 0;
}