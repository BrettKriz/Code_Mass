#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
void fuel();

int hours;
double miles, liters;

int main()
{
	system("color 0A");

	fuel();
	fuel();


	system("pause");
	return 0;
}

void fuel()
{
	double rmiles, gals;
	int weeks, days, hours2;


	cout << "\nTime Traveled: ";
	cin >> hours;
	cout << "\nDistance Traveled: ";
	cin >> miles;
	cout << "\nFuel used: ";
	cin >> liters;
	// CALC

	int x = hours;
	weeks = int(x/168.0);
	days = int((x%168)/24.0);
	hours2 = int((x%168)%24);

	rmiles = double(miles*1.15);
	gals = double(liters*0.264172051242);

	cout << "Trip Summary\n";

	cout << "Distance: " << //setw(7) <<
		setprecision(2) << miles << " Nautical Miles\n" << //setw(7) <<
		setprecision(2) << rmiles << " statue miles\n";

	cout << "Average Speed: " << //setw(6) << 
		setprecision(2) << double(rmiles/hours) << "MPH\n";

	cout << "Time: " << //setw(2) <<
		weeks << " Weeks " << setw(2) << 
		days << " Days " << setw(2) << hours2 << " Hours\n";

	cout << "Fuel: " << //setw(5) <<
		 setprecision(2) << gals << " Gallons used for " << //setw(4) <<
		 setprecision(1) << double(rmiles/gals) << " Miles per gallon\n\n";


	system("pause");


}