#include <iostream>
using namespace std;

class Base
{
   public:
      int  a;
      Base(int x=10):a(x)
         { cout << "Base has " << a << endl; }
};

class Derived: public Base
{
   public:
      int x;
      Derived(int m=20):x(m)
         { cout << "Derived has " << x << endl; }
};

int main(void)
{
   Base    X, *XX;
   Derived Y, *YY;

   cout << "Base's value    = " << X.a << endl;
   cout << "Derived's value = " << Y.x << endl;
   cout << endl;
 
   XX = new Base(123);
   YY = new Derived(789);
   cout << "Base's value    = " << XX->a << endl;
   cout << "Derived's value = " << YY->x << endl;

   return 0;
}  

