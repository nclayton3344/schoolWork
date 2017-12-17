//Nathaniel Clayton
//COSC-1437 10/18/2017
//Check Writing Program
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "employee.h"
using namespace std;

//Default Constructor
//Pre-Conditon: called implicitly when Employee object is created
//Post-Conditon: Employee data is given empty values
Employee::Employee() {
	employeeName = "Nothing Entered";
	payAmount = 0.00;
	curNot = "Nothing Entered";
	wordAmount = "Nothing Entered";
}

//Constructor - initializes Employee data base on string and double parameters
//Pre-Conditon: called when Employee object is created and given arguments
//Post-Conditon: Employee data is given all values based on string and double
Employee::Employee(string name, double pay) {

	employeeName = name;
	payAmount = pay;
	curNot = currencyNotation(pay);
	wordAmount = wordFormat(pay);

}

//Function to assign data values to Employee object
//Pre-Conditon: object musted be created and attached to function
//---and given values for Employee Name and Pay
//Post-Condition: Employee data is given all values based on string and double

void Employee::assign(string name, double pay) {

	employeeName = name;
	payAmount = pay;
	curNot = currencyNotation(pay);
	wordAmount = wordFormat(pay);
}


//Function that converts a double value into a dollar amount 
//---- with commas and dollar sign inserted
//Pre-Conditon: function must be called with double argument for payment amount
//Post-Conditon: string of double value in currency form is returned
string Employee::currencyNotation(double pay) {

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


//Function that converts 9 digit int into word form
//Pre-Conditon: function must be called with double (Employee object payAmount) argument
//Post-Condition: word format of up to 9 digit(not counting decimal) double is returned as string
string Employee::wordFormat(double pay) {

	int num = int(pay), millions, thousands, hundreds;
	string wordForm, payToString, cents;

	ostringstream oss;
	oss << fixed << showpoint << setprecision(2);
	oss << pay;
	payToString = oss.str();
	cents = "Dollars and " + payToString.substr(payToString.length() - 2) + " cents";


	if (pay < 1) {
		wordForm = "Zero " + cents;
		return wordForm;
	}


	millions = num / 1000000;
	num = num % int(pow(10, 6));
	thousands = num / 1000;
	num = num % int(pow(10, 3));
	hundreds = num - (num / 1000);


	if (millions > 0) {
		wordForm = wordForm + convertIntToWords(millions) + "Million ";
	}
	if (thousands > 0) {
		wordForm = wordForm + convertIntToWords(thousands) + "Thousand ";
	}
	if (hundreds > 0)
		wordForm = wordForm + convertIntToWords(hundreds);

	return wordForm + cents;
}

//Function that converts 3 digit int into word form
//Pre-Conditon: function must be called with int argument
//Post-Condition: word format of 3 digit int is returned as string
string Employee::convertIntToWords(int pay) {

	string ones[] = { "", "One", "Two","Three","Four","Five","Six","Seven","Eight","Nine",
		"Ten","Eleven","Tweleve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen ","Eighteen","Nineteen" };

	string tens[] = { "", "Ten", "Twenty ", "Thirty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };

	int num = pay;
	string wordForm, temp;

	int i = 3;

	while (i > 0) {

		int index = num / int(pow(10, i - 1)), a;

		switch (i) {

			case 1:
				if (index == 0)
					temp = "";
				else
					temp = ones[index] + " ";
				break;

			case 2:
				if (index == 1) {
					a = num / int(pow(10, i - 2));
					temp = ones[a];
					i--;
				}
				else
					temp = tens[index];
				break;

			case 3:
				if (index > 0)
					temp = ones[index] + " Hundred ";
				break;

			default:
				break;

		}

		wordForm = wordForm + temp;
		num = num % int(pow(10, i - 1));

		if (num == 0) {
			return wordForm;
			break;
		}

		i--;
	}

	return wordForm;

}

//Function to output digital pay check for Employee to file
//Pre-Conditon: Employee object must have all data elements intialized
//-----must be called with ofstream passed as argument
//Post-Conditon: digital check is printed to file
void Employee::printCheck(ofstream & out) {

	char dateStr[9];  //C-string for Date
	_strdate_s(dateStr);

	out << string(80, '=')<< endl;
	out << "| DigiSoft Company                                             Date: " << dateStr << "  |" << endl;
	out << "| 1400 New Way Ave                                                             |" << endl;
	out << "| Lubbock, Tx 79424                                                            |" << endl;
	out << "|                                                                              |" << endl;
	out << "|      Pay to the Order Of: " << left << setw(25) << employeeName << setw(25) << right << curNot << " |" << endl;
	out << "|                                                                              |" << endl;
	out << "|      " << setw(72) << left << wordAmount << "|" << endl;
	out << "|                                                                              |" << endl;
	out << "|                                                                              |" << endl;
	out << "|                                           Murphy S. Law, CEO                 |" << endl;
	out << "|                                                                              |" << endl;
	out << string(80, '=') << endl;

}







