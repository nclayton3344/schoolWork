#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

int main() {
	int month, year,days;
	char reply;
	string mname;
	do {
		cout << "What is the number of the month (1-12)?" << endl;
		cin >> month;

		while (month < 1 || month > 12) {
			cout << "What is the number of the month (1-12)?" << endl;
			cin >> month;
		}


		if (month == 2) {
			cout << "What year is it?" << endl;
			cin >> year;
			if ((year % 400 == 0 || year % 100 != 0 ) && (year % 4 == 0))
				days = 29;
			else
				days = 28;
				
}

		switch (month) {
		case 1: days = 31; mname = "January";
			break;
		case 2: days = days; mname = "February";
			break;
		case 3: days = 31; mname = "March";
			break;
		case 4: days = 30; mname = "April";
			break;
		case 5: days = 31; mname = "May";
			break;
		case 6: days = 30; mname = "June";
			break;
		case 7: days = 31; mname = "July";
			break;
		case 8: days = 31; mname = "August";
			break;
		case 9: days = 30; mname = "September";
			break;
		case 10: days = 31; mname = "October";
			break;
		case 11: days = 30; mname = "November";
			break;
		case 12: days = 31; mname = "December";
			break;
		default: cout << "Invalid Input" << endl;
			break;
		}
		cout << "The month of " << mname << " has " << days << " days in it." << endl;

		cout << "Would you like to test another month? (y/n)" << endl;
		cin >> reply;
		reply = tolower(reply);
		cin.ignore(40, '\n');
	} while (reply == 'y');

		cout << "Program Terminated" << endl;
	return 0;
}