#include <string>
#include <iostream>
#include <iomanip>
#include "employee.h"
using namespace std;

string Employee::currencyNotation(double pay) {

	return "Test";
}

string Employee::wordFormat(double pay) {

	return "test";
}

void Employee::printCheck(Employee emp) {


}

Employee::Employee() {
	employeeName = "Nothing Entered";
	payAmount = 0.00;
	curNot = "Nothing Entered";
	wordAmount = "Nothing Entered";
}

Employee::Employee(string name, double pay) {

	name = name;
	payAmount = pay;
	curNot = currencyNotation(pay);
	wordAmount = wordFormat(pay);

}

void Employee::assign(string name, double pay) {

	employeeName = name;
	payAmount = pay;
	curNot = currencyNotation(pay);
	wordAmount = wordFormat(pay);
}

void Employee::printName() {
		
		cout << fixed << showpoint << setprecision(2) << employeeName << " " << payAmount << endl;	

}

