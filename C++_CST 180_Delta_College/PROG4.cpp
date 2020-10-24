// PROGRAM 4
// Windchill2
// Brett Kriz
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void input();
void out(string arg);
void out(double arg);
void error(string arg);
double calculate(double ws, double t);
int round_off(double arg);
void AdviseOut();
void body();

double temp,windspd, windchill;

int main()
{
	system("title PROG 4 - Windchill 2");
	system("color 0A");


	body();// for show


	system("pause");
	return 0;
}
void body()
{
	// Code body
	input();
	cout << "\n\n";
	windchill = calculate(windspd, temp); // Even though my variables are declared in the header
	AdviseOut();


}
void input()
{
	bool f1,f2;
	// TEMP
	do{
		cout << "Tempurature: ";
		cin >> temp;
		f1 = (temp < -40 || temp > 40);
		if (f1){ error("Bad TEMP! Must be between -40 and 40\n");}
	}while (f1);

	// WIND SPEED
	do{
		cout << "Wind Speed: ";
		cin >> windspd;
		f2 = (windspd < 0 || temp > 60);
		if (f2){ error("Bad SPEED! Must be between 0 and 60\n");}
	}while (f2);




}
double calculate(double ws, double t)
{
	double ans;
	// Soooo ya
	ans = double(35.74 + (0.6215*t)-(35.75* pow(ws,0.16))+(0.4275*t*pow(ws,0.16)));
	ans = round_off(ans);
	// I would out but...
	cout << "Windchill: " << fixed << setw(7) << setprecision(3) << ans << " degrees\n";

	return ans;
}
int round_off(double arg)
{
	if (arg == 0.00){return 0;}
	int ans;

	// More of a ceil
	if (arg > 0) {
		ans = int(arg+0.5);
	}else{
		ans = int(arg-0.5);
	}


	return ans;
}
void AdviseOut()
{
	string ans = "", t; // t was going to be used and still might
	double x = windspd; // for shorthand


	if (x < -48){
		ans = "Life threatening: Frostbite can occur within 5 minutes.";
		system("title Life threatening: Frostbite can occur within 5 minutes.");
	}else if (x >= -48 && x <= -31){
		ans = "Danger: Frostbite can occur within 10 minutes.";
		system("title Danger: Frostbite can occur within 10 minutes.");
	}else if (x >= -30 && x <= -13){
		ans = "Warning: Frostbite can occur within 30 minutes.";
		system("title Warning: Frostbite can occur within 30 minutes.");
	}else if (x >= -12 && x <= 17){
		ans = "Advisory: Frostbite can occur with extended exposure.";
		system("title Advisory: Frostbite can occur with extended exposure.");
	}else if (x >= 18 && x <= 39){
		ans = "Notice: Wear cold weather clothing as needed for comfort.";
		system("title Notice: Wear cold weather clothing as needed for comfort.");
	}else{
		ans = "No significant cold weather risk. Go play outside!"; // LOL
		system("title Go play outside \t\t lol");
	}
	
	out(ans);
	out("\n\n");

}
void error(string arg)
{
	cout << "\n[!] ERROR! " << arg << endl;

}
void out(string arg)
{
	cout << arg << endl;
}
void out(double arg)
{
	cout << arg << endl;
}