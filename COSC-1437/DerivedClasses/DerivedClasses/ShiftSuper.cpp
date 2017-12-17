//Nathan Clayton
//Class Inheritance Project
//10/30/17
#include "ShiftSuper.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Default Constructors
//Pre-Conditon: Called when an object of type ShiftSuper is created
//Post-Conditon: Object is given default values
ShiftSuper::ShiftSuper(){
	superBonus = 0;
	salary = 0;
	assignEmp("Blank", 0000, "11/11/11");
}

//Constructor that assigns explicit values to members
//Pre-Condition: Called and given the parameters for salary, bonus, name, idNum, and hireDate
//Post-Conditon: members are given values
ShiftSuper::ShiftSuper(double s, double b, string n, int id, string h){
	salary = s;
	superBonus = b;
	assignEmp(n, id, h);
}
//Function that assigns explicit values to members
//Pre-Condition: Called and given the parameters for salary, bonus, name, idNum, and hireDate
//Post-Conditon: members are given values
void ShiftSuper::assignSS(double s, double b, string n, int id, string h){
	salary = s;
	superBonus = b;
	assignEmp(n, id, h);
}
//Function to return superBonus value
//Pre-condition: attach to object to call
//Post-Condition: superBonus is returned
double ShiftSuper::getBonus() {
	return superBonus;
}
//Function to return salary value
//Pre-condition: attach to object to call
//Post-Condition: salary is returned
double ShiftSuper::getSalary() {
	return salary;
}
//Function to output ShiftSuper object values to a txt file
//Pre-Conditon: Function must be called with ofstream object
//Post-Condition: Output is sent to file
void ShiftSuper::print(ofstream & out){
		out << fixed << showpoint << setprecision(2);
		out << right << setw(15) << (*this).getName() << setw(23) << (*this).getIDNum() << setw(24) << (*this).getHireDate() << setw(16) << "$" << salary << setw(7) << "$" << superBonus << endl << endl;

}
