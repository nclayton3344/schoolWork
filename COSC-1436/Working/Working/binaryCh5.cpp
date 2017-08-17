//Nathan Clayton Chapter 5 Program
//Unsigned Binary Conversion
#include <iostream>
#include <cmath>
using namespace std;

int main() {
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
		cout << "Program Terminated" << endl;
}