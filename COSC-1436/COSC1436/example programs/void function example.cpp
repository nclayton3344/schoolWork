//C Young 3/20/2017
//First example of a void function 

#include <iostream>
#include <string>

using namespace std;

void printlines(int,int,char);       //function prototype

int main() {
	string name;  //local variables for main
	int count;

	printlines(2,40,'*');   //function call with arguments

	cout << "Enter your first name: ";
	cin >> name;

	cout << "How many semesters have you been enrolled at SPC?: ";
	cin >> count;

	printlines(count,50,name[0]);   //function call with arguments

	cout << name << ", Please procede to first registration station." << endl;

	printlines(count*2,15,'$');   //function call with arguments

	return 0;

}

//function definition for printlines
//

void printlines(int numlines, int numsyms, char symbol) {  //formal parameters
	int row, col;  //local variables

	for (row = 1; row <= numlines; row++) {
		for (col = 1; col <= numsyms; col++)
			cout << symbol;
		cout << endl;
	}


}