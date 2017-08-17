// This program calculates the user's pay.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Control how a double value is displayed
	cout << fixed << showpoint << setprecision(2);
	// These manipulators only affect float and double data types
	double hours, rate, pay;
	cout << "Wage Calculator by N Clayton 2017" << endl << endl << endl;

	// Get the number of hours worked.
	cout << "How many hours did you work? ";
	cin >> hours;

	// Get the hourly pay rate.
	cout << "How much do you get paid per hour? ";
	cin >> rate;
	if (hours > 40) {
		pay = (40 * rate) + ((hours - 40)*(rate * 1.5));
		cout << "Overtime Calculated." << endl;
	}
			// Calculate the pay.
	else{
			pay = hours * rate;
	}

	// Display the pay
	cout << "You have earned $" << pay << endl;
	return 0;

}