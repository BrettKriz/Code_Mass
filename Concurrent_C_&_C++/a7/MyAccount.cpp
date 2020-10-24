#include  <iostream>
#include  "MyAccount.h"

using namespace std;

MyAccount::MyAccount(int initial)
             : Balance(initial)
{
}

int MyAccount::Deposit(int Amount)
{
   cout << "Deposit Request  = " << Amount << endl;
   cout << "Previous Balance = " << Balance << endl;
   Balance += Amount;
   cout << "New Balance      = " << Balance << endl << endl;
   return Balance;
}

int MyAccount::Withdraw(int Amount)
{
   cout << "Withdraw Request = " << Amount << endl;
   cout << "Previous Balance = " << Balance << endl;
   Balance -= Amount;
   cout << "New Balance      = " << Balance << endl << endl;
   return Balance;
}

void MyAccount::Display(void)
{
   cout << "Current Balance  = " << Balance << endl << endl;
}
