#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	string firstName, lastName, grade, gradeTotal, avgTotal;
	int i,j; 
	double studentAvg, classAvg;
	ifstream infile;
	ofstream outfile;
	infile.open("coursegrades.txt");
	if (!infile) {
		cout << "Something went wrong. File did not open." << endl;
		return 1;
	}
	gradeTotal = 0; 
	avgTotal = 0;

	cout << "Class Grade Average Calculator - Nathaniel Clayton - 03/09/2017" << endl << endl;
	cout << "Name: " << setw(6) << "Exam 1" << setw(6) << "Exam 2" << setw(6) << "Exam 3" << setw(6) << "Exam 4" << setw(6) << "Exam 5" << setw(6) << "Exam 6" << setw(7) << "Average" <<endl << endl;


	while (infile >> lastName) {
		cout << lastName << ",";
		infile >> firstName;
		cout << firstName;
		for (i = 1; i <= 6; i++) {
			infile >> grade;
			cout << setw(6) <<grade;
			gradeTotal += grade;
		}

		studentAvg = gradeTotal / double(i);
		cout << studentAvg << endl << endl;
		avgTotal += studentAvg;

		gradeTotal = 0;
		j++;
	}

	classAvg = avgTotal / 6.0;
	cout << "The class has a total of " << j << " students. The final class average is: " << classAvg << endl;
	return 0;
}