//Nathaniel Clayton - COSC 1437
//Using Classes Program - Complex Numbers
// ------  9/19/207
#include <iostream>
#include "complex.h"
#include <ctime>
using namespace std;

void printInfo();

int main()
{

	int r1, i1, r2, i2;
	char reply = 'y';
	Complex c1, c2, answer;

	printInfo();

	do {
		cout << "Please enter the value of the real number in Set 1:" << endl;
		cin >> r1;
		cout << "Please enter the value of the imaginary number in Set 1:" << endl;
		cin >> i1;
		c1.assign(r1, i1);

		cout << endl << endl << "Please enter the value of the real number in Set 2:" << endl;
		cin >> r2;
		cout << "Please enter the value of the imaginary number in Set 2:" << endl;
		cin >> i2;
		c2.assign(r2, i2);
		
		cout << endl << endl << "************************************************************"
			<< endl << endl << "For Complex Number Set 1, You Entered: ";
		c1.print();
		cout << endl << "For Complex Number Set 2, You Entered: ";
		c2.print();

		cout << endl << endl << "Here are your calculations: ";
			
		answer = c1.multiplyby(c2);
		cout << endl << endl;
		c1.print();
		cout << " * ";
		c2.print();
		cout << " = ";
		answer.print();

		answer = c1.addto(c2);
		cout << endl << endl;
		c1.print();
		cout << " + ";
		c2.print();
		cout << " = ";
		answer.print();

		cout << endl << endl << "************************************************************" << endl;

		cout << endl << endl << "Enter 'y' (case sensitive) to add/multiply more complex numbers. To exit, enter any other key." << endl;
		cin >> reply;
		reply = tolower(reply);

		cout << endl << endl;

	} while (reply == 'y');

	cout << endl << "\"Program Terminated\" - Arnold Schwarzenegger" << endl;
}

void printInfo() {

	char dateStr[9];
	char timeStr[9];
	_strdate_s(dateStr);
	_strtime_s(timeStr);

	cout << "***************************************************************************************" << endl <<endl;
	cout << "Welcome to the Complex Number Calculator. This is a handy tool that allows you to add" << endl
		<< "and multiply different sets of complex numbers until your heart's content. A complex " << endl
		<< "number is a set of numbers, real and imaginary, that look like (4 + 7i) or (-1 - 9i)." << endl
		<< "This calculator will automagically add and multipy two sets of complex numbers for you." << endl << endl
		<< "Today's Date & Time: " << dateStr << " " << timeStr << " -- Now we can begin calculating." << endl
		<< "***************************************************************************************" << endl << endl;

}

