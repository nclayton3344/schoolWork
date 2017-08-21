//Test code written 9/13/16 by C Young
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const int MAX = 10;

int main() {

	string temp, word[MAX];
	bool room = true;
	int count = 0;


	ifstream infile;
	infile.open("sample.txt");  
	if (!infile) {
		cout << "cannot open input file" << endl;
		return 1;
	}
	// All this error checking is necessary for this code to work when:
	// 1. file has no words. Reports count as 0.
	// 2. file has any number of words less than MAX. Reports count correctly
	// 3. file has exactly MAX words. Reports count as MAX.
	// 4. file has > MAX words and you want program to abort with an appropriate message

	infile >> word[count];

	while ( infile && room  ) {
		count++;
		if (count == MAX)
			room = false;
		else
			infile >> word[count];
				
	}

	if (count == MAX) {
		infile >> temp;
		if (infile) {
			cout << "Data file is too large for this program. Reset MAX higher. Program is aborted." << endl;
			return 1;
		}

	}
		

	for (int i = 0; i < count; i++)
		cout << setw(3) << i + 1 << "  " << word[i] << endl;

	cout << "total words: " << count << endl;

	return 0;

}