#include  <iostream>
using namespace std;

int main(void)
{
   int  i, n, factorial;

   cout << "A positive integer --> ";
   cin  >> n;
   factorial = 1;
   for (i = 1; i <= n; i++)
      factorial *= i; 
   cout << "Factorial of " << n << " = " << factorial << endl;
   return 0;
}

