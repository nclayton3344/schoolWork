//Nathan Clayton - Grade Average Calculator
//Chapter 5 Program Problem 1
#include <iomanip>
#include <fstream> 
#include <iostream>
using namespace std;

int main() {
	int grade, low, i, total;
	char gradeLetter;
	float avg;
	 
	cout << fixed << showpoint << setprecision(1);
	cout << "Grade Average Calculator" 
		 << endl << "----------------------------" << endl;
	cout << "Enter a Grade or Enter -1 to Quit." << endl;
	cin >> grade;


	i = 0, total = 0, low = 100;
	while (grade != -1) {
		total += grade;
		if (grade < low)
			low = grade;
		cout << "Enter a Grade or Enter -1 to Quit. " << endl;
		cin >> grade;
		i++;
	}
	if (i < 2)
		avg = total / float(i);
	else
		avg = (total - low) / float(i-1);

	if (avg < 60)
		gradeLetter = 'F';
	else if (avg < 70)
		gradeLetter = 'D';
	else if (avg < 80)
		gradeLetter = 'C';
	else if (avg < 90)
		gradeLetter = 'B';
	else
		gradeLetter = 'A';

	cout << "The average for " << i << " grades is: " << avg << " which is a letter grade of \"" << gradeLetter << "\" " << endl;
}