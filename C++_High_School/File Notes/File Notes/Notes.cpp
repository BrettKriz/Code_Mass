//DEMO FILE I/O
#include <iostream>
#include <string>
#include <fstream>		//FILE I/O header file	

using namespace std;

int main(){
	cout << "Grading, son" << endl;
	//Declare an input file stream
	//		Fin is just a name, it can be anything
	ifstream fin("u:\\test.txt");//Need double backslaches

	//Declare an output file stream
	ofstream fout("u:\\out.txt"); //file will be created for you

	//Note: fin and fout are variable names - 
	//you can call them what you want

	//Make sure file opened correctly b/c it won't tell 
	//you otherwise
	if (!fin.is_open()){
		cout << "file error" << endl;
		system("Pause");
		return 0; //end main
	}

	//Read the name and score, compute pass/fail, output
	double score = 0;
	string name = "";
	
	while (!fin.eof()){					//Loop while NOT the end of file
		fin >> name >> score;			//Same operator used with cin
		double s = score / 50 * 100; 

		//Determine pass/fail, then output
		if(s >= 60){
			fout << name << ": PASS" <<endl; //Same as cout
		}else{
			fout << name << ": FAIL" <<endl;
		}
	}

	//Close the input file
	fin.close();
	//Close output file
	fout.close();
	
	//Open the output file (optional)
	system("notepad.exe u:\\out.txt");
	//system("ping www.google.com");
	system("Pause");
	return 0;
}
