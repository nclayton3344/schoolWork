//Finding an Average using Flag Controlled Loops
//Nathan Clayton
// In C++, the input stream name can be tested like a bool variable 
// If the last input was successful, the value of the stream variable will be true
//If the last input was unsuccessful, the value will be false
#include <iostream>
#include <iomanip>
#include <fstream> // include file for file streams
using namespace std;

int main() {
	int grade, total;
	double avg;
	int i;
	ifstream infile;
	infile.open("mygrades.txt");
	if (!infile) {
		cout << "Cannot open input file. Program Aborted!" << endl;
		return 1;
	}
	ofstream outfile;
	outfile.open("resultsforgradeprogram.txt");
	i = 0;
	total = 0;
	

	outfile << "Grades Section 2 Spring 2017" << endl;
	while (infile>>grade){
		outfile << setw(3) << grade << endl;
		total += grade;
		i++;
		
}
	if ( i > 0) {
		avg = total / double(i);
		outfile << "For " << i << " grades, the average is: " << fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		outfile << "No data to average." << endl;

	return 0;
}