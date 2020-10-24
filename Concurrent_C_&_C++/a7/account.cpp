#include  <iostream>
using namespace std;

class MyAccount 
{
   public:
      MyAccount(int Initial_Amount);
      int  Deposit(int);
      int  Withdraw(int);
      void Display(void);

   private:
      int  Balance;
};

MyAccount::MyAccount(int initial)
{
   Balance = initial;
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

int main(void)
{
   MyAccount  NewAccount(0);

   NewAccount.Display();
   NewAccount.Deposit(20);
   NewAccount.Deposit(35);
   NewAccount.Withdraw(40);
   NewAccount.Display();
   return 0;
}

