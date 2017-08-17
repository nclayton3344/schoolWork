//Nathan Clayton Chapter 4 Program
//Unsigned Binary Conversion
#include <iostream>
using namespace std;

int main() {
	int base10, b1, b2, b3, b4, b5, b6, b7, b8, input;
	char reply;

	do {
		cout << "Unsigned Binary Conversion" << endl;
		cout << "Enter a number between 0-255: " << endl;
		cin >> input;
		base10 = input;

		if (base10 >= 0 && base10 <= 255) {
			if (base10 >= 128) {
				b1 = 1;
				base10 = base10 - 128;
			}
			else
				b1 = 0;

			if (base10 >= 64) {
				b2 = 1;
				base10 = base10 - 64;
			}
			else
				b2 = 0;
			if (base10 >= 32) {
				b3 = 1;
				base10 = base10 - 32;
			}
			else
				b3 = 0;

			if (base10 >= 16) {
				b4 = 1;
				base10 = base10 - 16;
			}
			else
				b4 = 0;

			if (base10 >= 8) {
				b5 = 1;
				base10 = base10 - 8;
			}
			else
				b5 = 0;

			if (base10 >= 4) {
				b6 = 1;
				base10 = base10 - 4;
			}
			else
				b6 = 0;

			if (base10 >= 2) {
				b7 = 1;
				base10 = base10 - 2;
			}
			else
				b7 = 0;

			if (base10 >= 1) {
				b8 = 1;
				base10 = base10 - 1;
			}
			else
				b8 = 0;

			cout << "The unsigned binary equivalent of " << input << " is: " << b1 << b2 << b3 << b4 << " " << b5 << b6 << b7 << b8 << endl;
		}
		else
			cout << "ERROR! Number is not within proper range." << endl;

		cout << "Would you like to convert another number? y/n" << endl;
		cin >> reply;
	} while (reply == 'y' || reply == 'Y');

	if (reply != 'y' || reply != 'Y')
		cout << "Program Terminated" << endl;
} 