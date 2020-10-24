#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Base
{
   public:
      int  a;
      char name[100];
      Base(int);
};

Base::Base(int x = 10) : a(x)
{
   char  buffer[10];

   strcpy(name, "Class");
   sprintf(buffer, "%d", a);
   strcat(name, buffer);
   cout << "Base class has a = " << a << " and "
        << '\"' << name << '\"' << endl;
}
   
class Derived: public Base
{
   public:
      Derived(int m=20): Base(m)
         {  }
};

int main(void)
{
   Base     X(23);
   Derived  Y(789);

   cout << "Base's name    = " << X.name << endl;
   cout << "Derived's name = " << Y.name << endl;
  
   return 0;
}  

