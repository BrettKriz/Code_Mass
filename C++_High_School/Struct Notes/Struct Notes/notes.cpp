#include <iostream>
#include <string>
#include <vector>

using namespace std;
//		Name
struct item{
	// cending machine item data type
	int inum;
	string desc;
	int qty;
	double cost;
};
// MUST end with semi colon

int main(){
	// Create an item
	item x;
	// set data for item 1 (x)
	x.inum = 1;
	x.desc = "Milk 2-percent";
	x.qty = 200;
	x.cost = 2.99;

	// Output item info
	cout << x.desc << endl;
	//cout << x << endl; - Error, you Can't output a whole struct

	// input data w/ loop
	vector<item> inventory;
	for (int i = 0; i < 5; i++){
		item it;
		cout << "" << endl;
}