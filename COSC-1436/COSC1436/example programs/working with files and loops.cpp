//using input from a file
//using an event controlled loop
//sending output to a file

#include <iostream>
#include <iomanip>
#include <fstream>   //new include file!!
using namespace std;

int main() {
	int  i, grade, total;
	double avg;
	ifstream infile;  //define new input file stream
	ofstream outfile; //define new output file stream

	infile.open("grades.txt");   //connect the stream to an actual file
	if (!infile) {  //check for successful open
		cout << "Cannot open input file! Program aborted." << endl;
		return 1;
	}

	outfile.open("gradeprogram Results");

	i = 0;
	total = 0;
	outfile << "Programmer: C Young" << endl;
	outfile << "Grade Report 3/1/2017" << endl;
	while (infile >> grade){  //shortcut method for testing cin
		outfile << setw(4) << grade << endl;
		total = total + grade;
		i = i + 1;
	}
	if (total > 0) {
		avg = double(total) / (i);
		outfile << "Your average for " << i << " grades is: " <<
			fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		outfile << "No valid grades to average." << endl;

	return 0;
}