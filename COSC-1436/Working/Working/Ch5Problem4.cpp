//Nathan Clayton Chapter 5 Program
//Unsigned Binary Conversion Input from File
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	int  input, max, j;
	ifstream infile;
	ofstream outfile;
	infile.open("binaryConversions.txt");
		if (!infile) {
			cout << "An error has occured while opening the file. Sorry. " << endl;
			return 1;
		}

		outfile.open("binaryConversionsResults.txt");

		while (infile >> input) {
			max = 32768;
			outfile << input << " converted to binary is: ";
			if (input >= 0 && input <= 65535) {
				while (max >= 1) {
					for (j = 16; (j <= 16 && j >= 1); j--) {

						if (input >= max) {
							outfile << "1";
							input = input - max;
							max = max / 2;
						}

						else {
							outfile << "0";
							max = max / 2;
						}

						if (j % 4 == 1)
							outfile << " ";
					}
				}
			}

			else
				outfile << "ERROR! The number you enter was not in the proper range." << endl;
			outfile << endl << endl;
		}

}