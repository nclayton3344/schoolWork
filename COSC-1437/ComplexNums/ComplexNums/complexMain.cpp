//Nathaniel Clayton - COSC 1437
//Using Classes Program - Complex Numbers
// ------  9/19/207
#include <iostream>
#include "complex.h"
#include <ctime>
using namespace std;

void printInfo(); //function prototype

int main()
{

	double r1, i1, r2, i2;
	char reply = 'y';
	Complex c1, c2, answer;

	printInfo();

	do {

		//This retrieves real and imaginary number from user input
		//---and assigns it to c1 using assign member function
		cout << "Please enter the value of the real number in Set 1:" << endl;		
		while (!(cin >> r1)) { //Verifies that user inputs a double number
			cout << "You Must Enter a Number. Try Again." << endl;
			cin.clear();
			cin.ignore();
		}

		cout << "Please enter the value of the imaginary number in Set 1:" << endl;
		while (!(cin >> i1)) { //Verifies that user inputs a double number
			cout << "You Must Enter a Number. Try Again." << endl;
			cin.clear();
			cin.ignore();
		}

		c1.assign(r1, i1); //assigns c1 values of r1 and i1 using member function

		//This retrieves real and imaginary number from user input
		//---and assigns it to c2 using assign member function
		cout << endl << endl << "Please enter the value of the real number in Set 2:" << endl;
		while (!(cin >> r2)) { //Verifies that user inputs a double number
			cout << "You Must Enter a Number. Try Again." << endl;
			cin.clear();
			cin.ignore();
		}

		cout << "Please enter the value of the imaginary number in Set 2:" << endl;
		while (!(cin >> i2)) { //Verifies that user inputs a double number
			cout << "You Must Enter a Number. Try Again." << endl;
			cin.clear();
			cin.ignore();
		}

		c2.assign(r2, i2); //assigns c2 values of r2 and i2 using member function
		
		//This displays the user input in Complex Number standard form
		cout << endl << endl << "************************************************************"
			<< endl << endl << "For Complex Number Set 1, You Entered: ";
		c1.print();
		cout << endl << "For Complex Number Set 2, You Entered: ";
		c2.print();

		//Complex Number Calculation Output
		cout << endl << endl << "Here are your calculations: ";
		
		//This displays the product of c1 and c2
		answer = c1.multiplyby(c2);
		cout << endl << endl;
		c1.print();
		cout << " * ";
		c2.print();
		cout << " = ";
		answer.print();

		//This displays the sum of c1 and c2
		answer = c1.addto(c2);
		cout << endl << endl;
		c1.print();
		cout << " + ";
		c2.print();
		cout << " = ";
		answer.print();

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
	cout << "***************************************************************************************" << endl <<endl;
	cout << "Welcome to the Complex Number Calculator. This is a handy tool that allows you to add" << endl
		<< "and multiply different sets of complex numbers until your heart's content. A complex " << endl
		<< "number is a set of numbers, real and imaginary, that look like (4 + 7i) or (-1 - 9i)." << endl
		<< "This calculator will automagically add and multipy two sets of complex numbers for you." << endl << endl
		<< "Today's Date & Time: " << dateStr << " " << timeStr << " -- Now we can begin calculating." << endl
		<< "***************************************************************************************" << endl << endl;

}

