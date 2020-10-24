#include  <iostream>
#include  "MyAccount.h"

using namespace std;

int main(void)
{
   MyAccount  *NewAccount;

   NewAccount = new MyAccount(0);
   NewAccount->Display();
   NewAccount->Deposit(20);
   NewAccount->Deposit(35);
   NewAccount->Withdraw(40);
   NewAccount->Display();
   return 0;
}

