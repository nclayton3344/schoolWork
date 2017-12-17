//Nathan Clayton
//Class Inheritance Project
//10/30/17
#include <string>
#include <fstream>
#include <iostream>
#include "Employee.h"
using namespace std;

//Default Constructors
//Pre-Conditon: Called when an object of type Employee is created
//Post-Conditon: Object is given default values
Employee::Employee() {
	name = "blank";
	idNum = 0;
	hireDate = "not entered";
}

//Constructor that assigns explicit values to members
//Pre-Condition: Called and given the parameters for name, idNum, and hireDate
//Post-Conditon: members are given values
Employee::Employee(string a, int id, string hire) {
	name = a;
	idNum = id;
	hireDate = hire;
}

//Mutators function that assigns values to members
//Pre-Conditon: Called and given parameters for name, idNum, and hireDate
//Post-Conditon: members are given values
void Employee::assignEmp(string a, int id, string hire){
	name = a;
	idNum = id;
	hireDate = hire;
}

//Function to return name value
//Pre-condition: attach to object to call
//Post-Condition: name is returned
string Employee::getName() {
	return name;
}
//Function to return idNum value
//Pre-condition: attach to object to call
//Post-Condition: idNum is returned
int Employee::getIDNum() {
	return idNum;
}
//Function to return hireDate value
//Pre-condition: attach to object to call
//Post-Condition: hireDate is returned
string Employee::getHireDate() {
	return hireDate;
}

//Function to output Employee object values to a txt file
//Pre-Conditon: Function must be called with ofstream object
//Post-Condition: Output is sent to file
void Employee::print(ofstream & out) {
	out << "Employee Name: " << name << " Employee ID: " << idNum << " Date of Hire: " << hireDate << endl;
}