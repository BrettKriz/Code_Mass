#include <iostream>
#include <cmath>

using namespace std;

double triArea(double a, double b, double c);
void windchill();
void pulseRate(int age, int& min, int& max);

int main(){

	//TRIANGLE
	double a, b, c;
cout << "Please enter the sides of a legal triangle: " << endl;
cout << "A: ";
cin >> a;
cout << "B: ";
cin >> b;
cout << "C: ";
cin >> c;

double area = triArea(a, b, c);
cout << "The area of your triangle is: " << area << endl;

//HEARTRATE
int min = 0, max = 0, age = 0;
cout << "Please enter your age: ";
cin >> age;
pulseRate(age, min, max);
cout << "For a " << age << " year old: " << endl;
cout << "Minimum target heart rate: " << min << endl;
cout << "Maximum target heart rate: " << max << endl;

//WINDCHILL
windchill();

system("pause"); 
return 0;
}
double triArea(double a, double b, double c){
	double lol, rofl;
	// calculate thee area
	// Assuming this is right
	lol = (a + b + c) / 2.0;
	rofl = sqrt(lol * (lol - a) * (lol - b) * (lol - c));

	return rofl;
}
void windchill(){
	//...Ummm windchill
	
	double cake, mph, temp;
	cout << "Whats the wind speed?";
	cin >> mph;
	cout << endl << "Whats the temp?";
	cin >> temp;

	cake = 91.4 - (91.4 - temp) * (.478 + .301 * sqrt(mph - .02 * mph));

	cout << cake << endl;
}
void pulseRate(int age, int& min, int& max){
	// lol age
	double lol;

	lol = 0.95 * (220 - age);
	max = ceil(lol);
	min = (max * 0.85);
}