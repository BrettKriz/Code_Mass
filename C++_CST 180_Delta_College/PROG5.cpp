// Program (and design) 5
// Brett Kriz
// Typed in Notepad (hastely on someone elses computer)

#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

// Define functions here
void Read_IN(string des, int& size);
double Average (int A[500], int size);
double STDDev(int A[500], int size, double avg);
void Quartiles (int A[500], int size);
void MaxNMin(int A[500], int size, double& max, double& min);

int scores [500]; // READ_IN was giving me so much hell over arrays

int main() {
system("title Program 5: Test Scores");
system("color 0A");


int x = 0;
int size = 0;

// Clean the new array
while (x < 500){
    scores[++x] = -1; // -1 for unused spaces

    }// end while

Read_IN("prg5data.txt", size); // oh look modularity

cout << "Checks\n";


// Create all other variables
// average
double avg = Average(scores, size);
// max and min
double max;
double min;
MaxNMin(scores, size, max, min);
// Standard Deviation
double stddev = STDDev(scores, size, avg);

// Display report
char N = '\n';

cout << "Number of Elements:\t" << fixed << size << N;
cout << "Mean:\t" << fixed <<  avg << N;
cout << "Max:\t" << fixed <<  max << N;
cout << "Min:\t" << fixed <<  min << N;
cout << "Standard Deviation:\t" << fixed <<  stddev << N;
// And show quartiles
Quartiles(scores, size);

system("pause");
return 0;
} // End Main


// Average
double Average (int A[500], int size){
int x = 0;
double ans = 0.0;

while (x<size){
    ans += A[++x]; 
    //Adds one after, should return a value similar to the DIM

}// end while

return double(ans/size);
}// end func


void MaxNMin(int A[250], int size, double& max, double& min){
int x=0; 
double cur;
max = 0;
min = -1; // lower than able value ;D


while (x<size){ // size = dim
    cur = A[++x];
    // MIN
        if (min == -1 || cur<min){
            min = cur;
        }
    // MAX
        if (cur>max){
            cur = max;
        }
    }// end loop
// void return
}// end function

// Standard Deviation
double STDDev(int A[500], int size, double avg){
int x = 0;
double ans = 0.0; // 0.0" lol

while (x<size){ // size = dim
    ans += double(pow(A[++x] - avg, 2)); // what a mouthfull
    // so its the xth value - average, quantity squared
    
    } // end loop
// return the sqrt of ans divided by size - 1
return sqrt(ans/(size - 1));
} // end func


//now, quartiles
void Quartiles (int A[500], int size){
	// vars
int x = 0;
int Q1 = 0;
int Q2 = 0;
int Q3 = 0;
int Q4 = 0;
int cur = 0;

while (x<size){ // size = dim
    cur = A[++x];
    if (cur >=75 && cur <= 100){
        Q4++;
    }else if(cur >=50 && cur < 75){
        Q3++;
    }else if(cur >= 25 && cur < 50){
        Q2++;
    }else if(cur >= 0 && cur < 25){
        Q1++;
    }else{
		int z = x-1;
        cout << fixed << "\nBad # @" << z << "! With value:\t" << A[z] << "\a";
    }
} // end while

cout << "\nQ1:\t" << fixed <<  Q1;
cout << "\nQ2:\t" << fixed <<  Q2;
cout << "\nQ3:\t" << fixed <<  Q3;
cout << "\nQ4:\t" << fixed <<  Q4 << endl;

}// end func


// READ IN FILE
void Read_IN(string des, int& size){
	//int AA[500];
	ifstream IN;
	int x = 0;



	IN.open(des); // Modularity >:3

if (IN.is_open()){
    system("color 09");
    while(!IN.eof()){
        IN >> scores[++x]; // Load items
		//system("echo + ");
		int prev = scores[x-1];
		// Something for checks
		//if (prev == 
        cout << prev << ","; // for fun
        } // end loop
	cout << "\nRead in complete!\n";
	
    system("pause");
    system("cls");
    system("color 0A");
    size = x; // Will equal dim of A[]
    
// not open?
}else{
    cout << "\n\nInput File is empty! Check path!\a";
	//cout << des << endl; //This wont work... idk
	//  '<<' : no operator found which takes a right-hand operand of type 'std::string' (or there is no acceptable conversion)
    system("color CA");
    system("pause");
    system("color 0A");
}// end if

IN.close();// Better close that...
//return AA[500];
}// end func
