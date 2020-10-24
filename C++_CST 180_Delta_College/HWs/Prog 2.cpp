#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

double basep = 0, weight = 0, shipcost, tax, totalcost = 0.00, hazcost = 0;
bool inState = false;
char hcode, instateC;

void outmoney(string str, double arg);
void shipping();
void part2();


int main()
{
	system("color 0A");
	system("title Program 2");


	shipping();
	shipping();
	shipping();

	system("pause");
	return 0;
}
void shipping()
{	
	tax = 0; // set vals for repeat
	inState = false;

	cout << "\nBase price: ";
	cin >> basep;
	cout << "\nWeight: ";
	cin >> weight;
	cout << "\nIs the shipping destination IN STATE? (y or n): ";
	cin >> instateC;
	cout << "\nWhich hazard code? [a,b,c]: ";
	cin >> hcode;

	// 1.
	if ((basep < 0)||(weight < 0)){cout << "\n\n\tBAD NUMBER! Try agian!\n"; return;}
	if (instateC == char('y')){inState = true;}
	if (!(hcode == char('a')||hcode == char('b')||hcode == char('c'))){
		cout << "Bad Hazard Code!\n"; return;
	}
	// end1

	if (inState){tax = basep*0.06;} // Get tax
	// 2.
	part2();
	// end2
	totalcost = basep + tax + hazcost + shipcost;

	cout << "\n\n\tSUCESS!" << "\n DETAILS: \n";

	outmoney("Original Price:\t$", basep);
	outmoney("Tax:\t$", tax);
	if (hazcost > 0) {outmoney("~Hazard Cost:\t$",hazcost);} // If there IS a haz cost...
	outmoney("Shipping cost:\t$",shipcost);
	outmoney("\nTOTAL:\t$",totalcost);
	cout << "\n\n\n";

}
void outmoney(string str, double arg)
{
	cout.precision(2);
	cout << fixed << str 
		<< double(arg) << endl;

}
void part2()
{
	double x = weight;

	if (x <= 20){
		shipcost = 14.95;
	}else if (x > 20 && x < 50){
		shipcost = 19.95;
	}else if (x >= 50 && x <= 100 ){
		shipcost = 29.95;
	}else if (x > 100 && !(x>200)){
		shipcost = 49.95;
	}else{
		shipcost = 99.95;
	}
	// Aaaaand
	if (inState){shipcost = shipcost - 10;}



}