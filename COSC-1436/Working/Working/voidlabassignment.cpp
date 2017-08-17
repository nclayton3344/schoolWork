#include <iostream>
using namespace std;

void binaryConversion();
void symbolPrint(int,int,char);


int main() {
	int ans2 = 1;
	while (ans2 == 1) {
		int ans, row, col;
		char symbol;

		cout << "What would you like to do? " << endl << "1. Convert a number to binary" << endl << "2. Print a field of symbols" << endl;
		cin >> ans;

		switch (ans) {

		case 1:
			binaryConversion();
			break;

		case 2:
			cout << "Enter number of rows, columns and which symbol in that specific order." << endl;
			cin >> row >> col >> symbol;

			symbolPrint(row, col, symbol);
		}

		cout << "Would you like to try something else? Press 1 for Yes and 2 for No." << endl;
		cin >> ans2;
	}
	return 0;

}



void binaryConversion(){
	int  input, max, j;
	char reply;

	do {
		cout << "Unsigned Binary Conversion" << endl;
		cout << "Enter a number between 0-65,535 with commas: " << endl;
		cin >> input;
		max = 32768;
		cout << input << " converted to binary is: ";
		if (input >= 0 && input <= 65535) {
			while (max >= 1) {
				for (j = 16; (j <= 16 && j >= 1); j--) {

					if (input >= max) {
						cout << "1";
						input = input - max;
						max = max / 2;
					}

					else {
						cout << "0";
						max = max / 2;
					}

					if (j % 4 == 1)
						cout << " ";
				}
			}
		}

		else
			cout << "ERROR! The number you enter was not in the proper range." << endl;
		cout << endl << endl;
		cout << "Would you like to convert another number? y/n" << endl;
		cin >> reply;
	} while (reply == 'y' || reply == 'Y');

	if (reply != 'y' || reply != 'Y')
		cout << "Program Terminated" << endl << endl << endl;
}

void symbolPrint(int a, int b, char symbol) {

	int row, col;
	for (row = 1; row <= a; row++) {
		for (col = 1; col <= b; col++)
			cout << symbol;
		cout << endl;
	}
}