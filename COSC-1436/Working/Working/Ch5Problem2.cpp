//Nathan Clayton
//Interger Table Ch. 5 Programs
<iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main() {
	int i, numTotal = 0, squareTotal = 0, cubeTotal = 0; 
	double rootTotal = 0.0;
	string table;
	ofstream outline;
	outline.open("Ch5Problem2Results.txt");

	table = "------------------------------------------";
	outline << setw(10) << "Number:" << setw(10) << "Sqaured" << setw(10) << "Cubed" << setw(10) << "Sq Root" << endl;
	outline << table << endl;
	outline << fixed << showpoint << setprecision(2) << endl;

	for (i = 50; i <= 75; i++) {
		numTotal += i;
		squareTotal += (i*i);
		cubeTotal += (i*i*i);
		rootTotal += sqrt(i);
		outline << setw(10) << i << setw(10) << i*i << setw(10) << i*i*i << setw(10) << sqrt(i) << endl << endl;
		outline << table << endl;
	}
	outline << "Totals: \n" << setw(10) << numTotal << setw(10) << squareTotal << setw(10) << cubeTotal << setw(10) << rootTotal << endl << endl;
}