//Bank account class
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

struct trans{
	string time;
	double amt;
};

class BankAccount{
public:
	// What a Bank Account should HAVE (variables)
	string accountname;
	double balance;
	vector<trans> history;

	// What a BankAccount DOES (Functions)
	//**********************************************
	//Class constructor (automatically called)
	//-MUST share class name
	//-No return type (not even void)
	//-Usually put initializations here
	BankAccount(){
		cout << "Please enter the account name: ";
		cin >> accountname;
		cout << endl << "Please enter the starting balance: ";
		cin >> balance;

		cout << endl << "Account Created" << endl << endl;
	}
	void deposit(){
		double amount;
		cout << "Please enter the deposit amount for " << accountname << ": ";
		cin >> amount;
		balance = balance + amount;
		//system("pause");
		history.push_back(tstmp(amount));
		cout << "The new balance is: " << balance << endl;
	}
	void withdraw(){
		double amount;
		cout << "Please enter the deposit amount for " << accountname << ": ";
		cin >> amount;
		if ((balance - amount) >= 0){
			balance = balance - amount;
		}else{
			cout << "Insufficant funds for transaction!" << endl;
		}
		history.push_back(tstmp(-amount));
	}
	void showHistory(){
		cout << "Transaction history for " << accountname << ":" << endl << "=========================================" << endl;
		for(int i = 0; i < history.size(); i++){
			cout << history[i] << endl;
		}
	}
	void display(){
		cout << accountname << endl << "$" << balance << endl;
	}
	void intrest(double intrest_son){
		
		balance = balance + intrest_son;
		history.push_back( tstmp(intrest_son));
		cout << "The new balance is: " << balance << endl;
	}

	trans tstmp(double dbl){
		string str2 = 0, str = 0;
		trans temp;
		temp.amt = dbl;

		time_t rawtime;
		time(&rawtime);
		string curtime = ctime(&rawtime);

		temp.time = curtime;

		return temp;
	}
};