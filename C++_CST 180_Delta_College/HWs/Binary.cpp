#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void OutInt(long arg);
void OutBinary(int arg);
void OutBinary(string arg);
void OutHex(int arg);
void OutHex(string arg);

// Vals for conversion
const char* hex_to_bin(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}
/*
const string bin_to_hex(string s)
{
	if ((s.length % 2) == 0.00)
	{
		switch(toupper(s)) // lol
		{
			case "0000": return '0';
			case "0001": return '1';
			case "0010": return '2';
			case "0011": return '3';
			case "0100": return '4';
			case "0101": return '5';
			case "0110": return '6';
			case "0111": return '7';
			case "1000": return '8';
			case "1001": return '9';
			case "1010": return 'A';
			case "1011": return 'B';
			case "1100": return 'C';
			case "1101": return 'D';
			case "1110": return 'F';
			case "1111": return 'F';
		}
	}else{

		cout << "WHAT?" << endl;
		return;
	}
}

*/

int main()
{
	cout << "Hello! Lets convert Binary! \n";
	OutInt(11101011);
	//OutInt(11010110101);
		system("pause");
	OutHex(1111);
	OutHex(1011);
	OutHex(0110);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		system("pause");
	OutBinary(9);
	OutBinary(12); // I couldnt figure out how to type in hex lololol



	system("pause");
	return 0;
}
void OutInt(long arg)
{
	string ans;
	cout << "INPUT: " << arg << " | BASE: 10 | ANSWER: ";
	while (arg > 0) {

		ans += arg%10;
		arg /= 10;

	}
	cout.precision(18);
	cout << dec << ans << "\n";
}
void OutBinary(int arg)
{
	string ans;
	cout << "INPUT: " << arg << " | BASE: 2\n";
	while (arg > 0) {

		ans += arg%2;
		arg /= 2;

	}

	cout.precision(18);
	cout << ans << "\n";
}
void OutBinary(string arg)
{
	// HEX?
	string ans = "";
	string var = "";
	cout << "INPUT: " << arg << " | BASE: 2\n";

	
    for(unsigned x = 0; x != arg.length(); ++x)
	{
		if (arg.length <= x+4)
		{
			var = arg.
		}
		ans += hex_to_bin(arg[x]);
	}
	cout.precision(18);
	cout << ans << "\n";
}
void OutHex(int arg)
{
	cout << hex << arg << endl;
	system("pause");
	string ans;

	cout << "INPUT: " << arg << " | BASE: 16 | ANSWER: " << hex << arg << endl;

}
void OutHex(string arg)
{
	// binary
	string ans;
	cout << "INPUT: " << arg << " | BASE: 16\n";

	
    for(unsigned x = 0; x != arg.length(); ++x)
	{
       ans += hex_to_bin(arg[x]);
	}

	cout << ans << "\n";
}







/*

	char buffer [33];
	itoa(arg,buffer,16);
	cout << buffer << endl;

	system("pause");

	while (arg > 0) {

		ans += arg%16;
		arg /= 16;

	}


	cout << ans << "\n";

	*/