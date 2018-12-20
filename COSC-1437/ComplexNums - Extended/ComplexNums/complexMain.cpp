//Nathaniel Clayton - COSC 1437
//Using Classes Program - Complex Numbers
// ------  9/19/207
#include <iostream>
#include <string>
#include <iomanip>
#include "complex.h"
#include <ctime>
using namespace std;

void printInfo(); //function prototype

int main()
{

	char reply = 'y';
	Complex c1, c2, answer;

	printInfo();

	do {
		cout << fixed << showpoint << setprecision(2);

		//Get 2 Complex Number Sets from User
		cout << "Please enter the values for complex number Set 1:" << endl;		
		cin >> c1;
		
		cout << endl << "Please enter the values for complex number Set 2:" << endl;
		cin >> c2;

		
		//This displays the user input in Complex Number standard form
		cout << endl << endl << "************************************************************"
			<< endl << endl << "For Complex Number Set 1, You Entered: ";
		cout << c1;
		cout << endl << "For Complex Number Set 2, You Entered: ";
		cout << c2;

		//Complex Number Calculation Output
		cout << endl << endl << "Here are your calculations: ";

		//This displays the sum of c1 and c2
		answer = c1 + c2;
		cout << endl << endl;
		cout << c1 << " + " << c2 << " = " << answer << endl;

		//This displays the difference of c1 and c2
		answer = c1 - c2;
		cout << endl << endl;
		cout << c1 << " - " << c2 << " = " << answer << endl;

		//This displays the product of c1 and c2
		answer = c1 * c2;
		cout << endl << endl;
		cout << c1 << " * " << c2 << " = " << answer << endl;

		//This displays the quotient of c1 and c2
		cout << endl << endl;
		cout << c1 << " / " << c2 << " = ";
		try {
			answer = c1 / c2;
			cout << c1 / c2 << endl;
		}
		catch (string msg) {
			cout << msg << endl;
		}

		//This checks c1 and c2 for equality
		cout << endl << endl;
		if (c1 == c2)
			cout << c1 << " and " << c2 << " are EQUAL." << endl;
		else if (c1 != c2)
			cout << c1 << " and " << c2 << " are NOT EQUAL." << endl;

		cout << endl << endl << "************************************************************" << endl;

		//User input to continue or terminate program
		cout << endl << endl << "Enter 'y' (case sensitive) to add/multiply more complex numbers. To exit, enter any other key." << endl;
		cin >> reply;
		reply = tolower(reply);

		cout << endl << endl;

	} while (reply == 'y'); // Repeats until user says otherwise

	cout << endl << "\"Program Terminated\" - Arnold Schwarzenegger" << endl; //Arnold Is The Man
}

//Function that outputs Complex Calculator information with current date/time
//Pre-Conditon: ctime included, iostream included, 
//Post-Conditon: text based information is printed to console
void printInfo() {

	//Retreives current date/time and 
	//assigns it to a char array
	char dateStr[9];
	char timeStr[9];
	_strdate_s(dateStr);
	_strtime_s(timeStr);

	//Outputs Text based info to Console
	cout << "*************************************************************************" << endl <<endl;
	cout << "Welcome to the Complex Number Calculator. This is a handy tool that" << endl
		<< "allows you to add and multiply different sets of complex numbers until" << endl
		<< "your heart's content. A complex number is a set of numbers, real and" << endl
		<< "imaginary, that look like (4 + 7i) or (-1 - 9i).This calculator will" << endl 
		<< "automagically add and multipy two sets of complex numbers for you." << endl << endl
		<< "Today's Date & Time: " << dateStr << " " << timeStr << endl
		<< " -- Now we can begin calculating." << endl
		<< "**************************************************************************" << endl << endl;

}

