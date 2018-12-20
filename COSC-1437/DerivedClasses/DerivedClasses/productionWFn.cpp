//Nathan Clayton
//Class Inheritance Project
//10/30/17
#include "ProductionWorker.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

//Default Constructors
//Pre-Conditon: Called when an object of type ProductionWorker is created
//Post-Conditon: Object is given default values
ProductionWorker::ProductionWorker(){
	shift = 0;
	payRate = 0.00;
	assignEmp("Blank", 0000, "11/11/11");
}

//Constructor that assigns explicit values to members
//Pre-Condition: Called and given the parameters for shift, payRate, name, idNum, and hireDate
//Post-Conditon: members are given values
ProductionWorker::ProductionWorker(int s, double p, string n, int id, string h){
	shift = s;
	payRate = p;
	(*this).assignEmp(n, id, h);
}

//Funtion to assign values to Production Worker Object
//Pre-Condition: Called and given the parameters for shift, payRate, name, idNum, and hireDate
//Post-Conditon: members are given values
void ProductionWorker::assignPW(int s, double p, string n, int id, string h){
	shift = s;
	payRate = p;
	(*this).assignEmp(n, id, h);
}
//Function to return shift value
//Pre-condition: attach to object to call
//Post-Condition: shift is returned
int ProductionWorker::getShift(){
	return shift;
}
//Function to return payRate value
//Pre-condition: attach to object to call
//Post-Condition: payRate is returned
double ProductionWorker::getPayRate(){
	return payRate;
}

//Function to output Production Worker object values to a txt file
//Pre-Conditon: Function must be called with ofstream object
//Post-Condition: Output is sent to file
void ProductionWorker::print(ofstream & out){
	out << fixed << showpoint << setprecision(2);
	out << right << setw(18) << (*this).getName() << setw(16) << (*this).getIDNum() << setw(24) << (*this).getHireDate() << setw(12) << shift  << setw(19) << "$" << payRate << endl << endl;

}