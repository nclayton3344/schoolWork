#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//Function Prototypes
void printHeader();
void printResults(int[], int, double);
void denomCounter(int, int[]);
void zeroCount(int[], int);
string currencyNotation(double pay);

int main() 
{
	//data creation
	char reply = 'y';
	double userAmount;
	int domCount[10];

	zeroCount(domCount, 10);
	printHeader(); 

	//Do While User Wants To
	do{
		//Gets Dollar Amount from User		
		cout << endl << "Enter a dollar amount with decimals but without adding dollar sign." << endl;
		cout << "Example: For $123.45, you would simply enter 123.45." << endl << "Example 2: For $23.00, you would enter 23.00." << endl;
		cin >> userAmount;

		//Function calls to count denominations and print results. It then sets all domCount values to zero
		denomCounter(int(userAmount*100), domCount);
		printResults(domCount, 10, userAmount);
		zeroCount(domCount, 10);

		//Repeats program based on user input
		cout << "Would you like to enter another dollar amount?" << endl;
		cin >> reply;
		cin.ignore(40, '\n');
		reply = tolower(reply);

	} while (reply == 'y');

	//Terminate
	cout << endl << "Thanks for being greedy!" << endl;
	cin.get(reply);
	reply = tolower(reply);
	cin.ignore(40, '\n');

	return 0;
}

//Function to count number of denominations required for given dollar amount
//Pre-Conditon: must be given dollar amount in pennies and given an array of size 10
//Post: array is loaded with the denomination counts required for change
void denomCounter(int amount, int count[]) {

	while (amount - 10000 >= 0) {
		count[0]++;
		amount -= 10000;
	}
	while (amount - 5000 >= 0) {
		count[1]++;
		amount -= 5000;
	}
	while (amount - 2000 >= 0) {
		count[2]++;
		amount -= 2000;
	}
	while (amount - 1000 >= 0) {
		count[3]++;
		amount -= 1000;
	}
	while (amount - 500 >= 0) {
		count[4]++;
		amount -= 500;
	}
	while (amount - 100 >= 0) {
		count[5]++;
		amount -= 100;
	}
	while (amount - 25 >= 0) {
		count[6]++;
		amount -= 25;
	}
	while (amount - 10 >= 0) {
		count[7]++;
		amount -= 10;
	}
	while (amount - 5 >= 0) {
		count[8]++;
		amount -= 5;
	}
	while (amount - 1 >= 0) {
		count[9]++;
		amount -= 1;
	}

}

//Function to print a header to display information about program
//Pre: Function must be called with no param
//Post: Output is displayed to console
void printHeader() {
	cout << string(100, '*') << endl << endl;
	cout << "Welcome to the greedy algorithm. This algorithm was designed to assist you in making change." << endl;
	cout << "If you need to know the most efficient way of giving change with the least amount of coins/bills," << endl;
	cout << "then this program is definitely what you've been looking for." << endl << endl;
	cout << string(100, '*') << endl;
}

//Function to print number of bills/coins to give each 
//Pre-Conditon: values in results array must represent number of USD denominations counted
//Post-Conditon: results are displayed to console
void printResults(int results[], int size, double amount) {

	string dollarForm = currencyNotation(amount);

	cout << endl << "The most efficient way to give " << dollarForm << " in cash/coin would be: " << endl << endl;

	for (int i = 0; i < size; i++) {
		if (results[i] > 0) {
			cout << " " << results[i];

			switch (i)
			{
			case 0:
				if(results[i] > 1)
					cout << " $100 Dollar Bills" << endl;
				else
					cout << " $100 Dollar Bill" << endl;
				break;
			case 1:
				if (results[i] > 1)
					cout << " $50 Dollar Bills" << endl;
				else
					cout << " $50 Dollar Bill" << endl;
				break;
			case 2:
				if (results[i] > 1)
					cout << " $20 Dollar Bills" << endl;
				else
					cout << " $20 Dollar Bill" << endl;
				break;
			case 3:
				if (results[i] > 1)
					cout << " $10 Dollar Bills" << endl;
				else
					cout << " $10 Dollar Bill" << endl;
				break;
			case 4:
				if (results[i] > 1)
					cout << " $5 Dollar Bills" << endl;
				else
					cout << " $5 Dollar Bill" << endl;
				break;
			case 5:
				if (results[i] > 1)
					cout << " $1 Dollar Bills" << endl;
				else
					cout << " $1 Dollar Bill" << endl;
				break;
			case 6:
				if (results[i] > 1)
					cout << " Quarters" << endl;
				else
					cout << " Quarter" << endl;
				break;
			case 7:
				if (results[i] > 1)
					cout << " Dimes" << endl;
				else
					cout << " Dime" << endl;
				break;
			case 8:
				if (results[i] > 1)
					cout << " Nickles" << endl;
				else
					cout << " Nickle" << endl;
				break;
			case 9:
				if (results[i] > 1)
					cout << " Pennies" << endl;
				else
					cout << " Penny" << endl;
				break;
			default:
				break;
			}
			cout << endl;
		}
	}

}

//Function to set all values in array to zero
//Pre-Condition: array must be defined with size number of elements
//Post-Condition: All values in array will be set to value zero
void zeroCount(int data[], int size) {
	//Sets array values to zero
	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}
}
//Function that converts a double value into a dollar amount 
//---- with commas and dollar sign inserted
//Pre-Conditon: function must be called with double argument for payment amount
//Post-Conditon: string of double value in currency form is returned
string currencyNotation(double pay) {

	int length, i;
	string payString, curFormat;
	ostringstream oss;
	oss << fixed << showpoint << setprecision(2);
	oss << pay;
	payString = oss.str();

	length = payString.length();

	if (length > 6) {
		for (i = length - 6; i >= 0; i -= 3)
			if (i > 0)
				curFormat = ',' + payString.substr(i, 3) + curFormat;
			else
				curFormat = payString.substr(i, 3) + curFormat;
		if (i < 0)
			curFormat = payString.substr(0, 3 + i) + curFormat;

		curFormat = "$" + curFormat + payString.substr(length - 3, length - 1);
	}
	else
		curFormat = "$" + payString;

	return curFormat;

}