//Finding an Average 
//Nathan Clayton

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int grade, total, low;
	double avg;
	char gradeavg;
	int i;
	i = 0;
	cout << "Enter grades to average. Enter Q to quit. " << endl;
	cout << "Enter grade " << i + 1 << ":" << endl;

	total = 0;
	low = 100;
	while (cin >> grade) {

		if (grade < low)
			low = grade;

		total += grade;
		i++;
		cout << "Enter a grade " << i + 1 << ":" << endl;

	}
	if (i >= 2) {
		avg = (total - low) / (double(i) - 1);
		cout << "For " << i << " grades, the average is: " << fixed << showpoint << setprecision(1) << avg << endl;
	}
	else {
		avg = total / double(i);
		cout << "For " << i << " grades, the average is: " << fixed << showpoint << setprecision(1) << avg << endl;
	}
		

	if (avg < 60)
		gradeavg = 'F';
	else if (avg < 70)
		gradeavg = 'D';
	else if (avg < 80)
		gradeavg = 'C';
	else if (avg < 90)
		gradeavg = 'B';
	else
		gradeavg = 'A';

	cout << "Letter Grade: " << gradeavg << endl;
	return 0;
}