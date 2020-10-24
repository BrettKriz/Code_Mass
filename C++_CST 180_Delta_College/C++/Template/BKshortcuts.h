#include <algorithm>	// Algorithms >.>
#include <cmath>		// Basic Math Operations
#include <cstdlib>		// control of stdlib
#include <cstring>		// Maniplulation of strings
#include <ctime>		// Time stuff
#include <fstream>		// File stream (I/O)
#include <iomanip>		// Manipulation of I/O
#include <iostream>		// Input\Output
#include <sstream>		// String stream
#include <stdio.h>		// Stuff For random numbers
#include <stdlib.h>		// Standard Library
#include <string>		// String Stuff
#include <time.h>		// More time stuff
#include <vector>		// Vectors

using namespace std;

double STRtoDBL(string str)
{
	// Dear CPP, Nobody cares about this char
	char ** p = NULL;
	double ans = 0;

	ans = atod(str.c_str(), p);

	return ans;
}
bool INTtoBOOL(double arg)
{
	if (arg >= 1){ 
		return true;
	}else{ 
		return false;
	}
	cout << "\nData Error in INTtoBOOL!\a\n";
}
