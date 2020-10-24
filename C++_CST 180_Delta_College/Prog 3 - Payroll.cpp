// Payroll
// Brett Kriz
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>		//FILE I/O header file	
#include <cmath>

using namespace std;

void Payroll();


int main(){
	
	system("color 0A");
	system("Title Payroll!");

	Payroll();

	system("Pause");
	return 0;
}
void Payroll(){
		//Declare an input file stream 
	//		Fin is just a name, it can be anything
	ifstream fin("payroll.txt");

	//Declare an output file stream
	ofstream fout("out.txt"); 





	//Read the name and score, compute pass/fail, output
	double hourlypayrate, salary, gross, tax, overtime, net = 0.00;
	int hoursworked;
	char classifi;
	string ID = "", ot = "";

	
	// Header
	cout << "Employee ID\t" << "Gross\t\t" << "Tax\t\t" << "Net\n";

	if (!fin.is_open()){
		cout << "file error" << endl;
		system("Pause");
		return ; //end
	}

	

	while (!fin.eof()){					//Loop while NOT the end of file
		fin >> ID >> classifi;		//Same operator used with cin
		
		if (classifi == char('S')){ // IF SALARY, then read it like this
			fin >> salary;
			if (salary < 0){cout << "\n! BAD IN !\n\n"; return;}

			gross = double(salary/26.00);


		}else if (classifi == char('H')){ // IF Hourly
			fin >> hoursworked >> hourlypayrate;
			if (hoursworked < 0||hourlypayrate < 0){cout << "\n! BAD IN !\n\n"; return;}

			overtime = 0;
			ot = ""; // just for fun

			if (hoursworked > 40){
				overtime = (0.5 * hourlypayrate);
				//cout << "Overtime!\n";
				ot = " & Overtime!";
				// Its going to be added
			}

			gross = (hoursworked*hourlypayrate+overtime); // What a gross calculation


		}else{cout << "\n! BAD Classification code !\n\n"; return;} // Num Error checking
		// End If

		// GROSS CALCS
			
			if (gross <= 0){cout << "! BAD MATH !\t" << gross << "\n"; return;} //Num Checking

			if (gross < 935){
				tax = double(0.15 * gross);

			}else if (gross >= 935 && gross <= 2880){
				tax = double(0.28 * gross) + 140.25;

			}else if (gross > 2880 && gross < 4200){
				tax = double(0.33 * gross) + 680.55;


			}else if (gross >= 4200){
				tax = double(0.40 * gross);

			}
			// END GROSS

			net = gross - tax; // Calculate NET


			// WRITE OUT, because its good :D
			//							ID											GROSS											TAX											NET			//
			cout << fixed << right << setw(6) << ID << "\t\t" << setw(7) << setprecision(2) << gross << "\t\t" << setw(7) << setprecision(2) <<  tax << "\t\t" << setw(7) << setprecision(2) << net <<  ot << endl;

			fout << fixed << right << setw(6) << ID << "\t" << setw(7) << setprecision(2) << gross << "\t" << setw(7) << setprecision(2) <<  tax << "\t" << setw(7) << setprecision(2) << net << "\t" << ot << endl;



	}// END WHILE


	cout << "\nDONE!\n";


	//Close the input file
	fin.close();
	//Close output file
	fout.close();
	
	//Open the output file (optional)
	system("notepad.exe out.txt");

}
