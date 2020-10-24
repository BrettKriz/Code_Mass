/*
ID:krizba1
PROB:friday
LANG:C++
 */
#include<iostream> 
#include<fstream>
using namespace std;

int to(int x,int m,int d) 
{ 
		if(m<3){m+=12;x--;} 
		int c=(x/100);
		int y=x-100*c; 
		int w=((c/4)-(2*c)+y+(y/4)+(26*(m + 1)/10)+d-1)%7;
		return (w+7)%7;
}

int main()
{
int n;
ifstream fin("friday.in");
ofstream fout("friday.out");
fin>>n;
	int x[7]={0};
for(int i=1900;i<1900+n;i++)
{
	for(int j=1;j<=12;j++)
	{
	x[to(i,j,13)]++;
	}
}

fout<<x[6];
for(int i=0;i<=5;i++)
	{
	fout <<" "<<x[i];
	}
	fout <<endl;
	return 0;
}  