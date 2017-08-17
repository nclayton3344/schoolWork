#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
	string firstName, lastName;
	int i, j, grade, gradeTotal;
	double studentAvg, classAvg, avgTotal;
	ifstream infile;
	ofstream outfile;
	infile.open("coursegrades.txt");
	if (!infile) {
		cout << "Something went wrong. File did not open." << endl;
		return 1;
	}
	avgTotal = 0, j = 0;
	cout << fixed << showpoint << setprecision(1);
	cout << "Class Grade Average Calculator - Nathaniel Clayton - 03/09/2017" << endl << endl;
	cout << setw(18) << std::left << "Name: " << std::right << setw(7) << "Exam 1:" << setw(7) << " Exam 2:" << setw(7) << " Exam 3:" << setw(7) << " Exam 4:" << setw(7) << " Exam 5:" << setw(7) << " Exam 6:   Average: " << endl << endl;

	while (infile >> lastName) {
		cout << setw(9) << std::left << lastName;
		infile >> firstName;
		cout << setw(9)<< std::left << firstName;
		gradeTotal = 0;
		for (i = 1; i <= 6; i++) {
			infile >> grade;
			gradeTotal = gradeTotal + grade;
			cout << setw(7) << std::right << grade << " ";
			
		}

		

		studentAvg = gradeTotal / 6.0;
		cout << setw(10) << std::right << studentAvg << endl << endl;
		avgTotal += studentAvg;

		
		j++;
	}

	classAvg = avgTotal / double(j);
	cout << "The class has a total of " << j << " students. The final class average is: " << classAvg << endl << endl;
	return 0;
}