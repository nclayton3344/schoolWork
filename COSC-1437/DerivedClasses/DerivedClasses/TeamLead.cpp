//Nathan Clayton
//Class Inheritance Project
//10/30/17
#include "TeamLead.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Default Constructors
//Pre-Conditon: Called when an object of type TeamLead is created
//Post-Conditon: Object is given default values
TeamLead::TeamLead() {
	leadBonus = 0;
	trainingHours = 0;
	assignPW(1, 16, "Blank", 0000, "11/11/11");
}
//Constructor that assigns explicit values to members
//Pre-Condition: Called and given the parameters for leadBonus, trainingHours, shift, rate, name, idNum, and hireDate
//Post-Conditon: members are given values
TeamLead::TeamLead(double bonus, int train, int shift, double rate, string nam, int id, string hire) {

	leadBonus = bonus;
	trainingHours = train;
	assignPW(shift, rate, nam, id, hire);

}
//Function that assigns explicit values to members
//Pre-Condition: Called and given the parameters for leadBonus, trainingHours, shift, rate, name, idNum, and hireDate
//Post-Conditon: members are given values
void TeamLead::assignTeamLead(double bonus, int train, int shift, double rate, string nam, int id, string hire){

	leadBonus = bonus;
	trainingHours = train;
	assignPW(shift, rate, nam, id, hire);
}
//Function to return leadBonus value
//Pre-condition: attach to object to call
//Post-Condition: leadBonus is returned
double TeamLead::getLeadBonus() {
	return leadBonus;
}
//Function to return trainingHours value
//Pre-condition: attach to object to call
//Post-Condition: trainingHours is returned
int TeamLead::getTrainingHours() {
	return trainingHours;
}
//Function to output TeamLead object values to a txt file
//Pre-Conditon: Function must be called with ofstream object
//Post-Condition: Output is sent to file
void TeamLead::print(ofstream & out){
	out << fixed << showpoint << setprecision(2);
	out << right <<  setw(14) << (*this).getName() << right << setw(16) << (*this).getIDNum() << right << setw(15) << (*this).getHireDate() << right << setw(8) << (*this).getShift() << right << setw(10) << "$" << (*this).getPayRate() << right << setw(8) << "$" << leadBonus << right << setw(8) << trainingHours << " out of " << requiredTraining << endl << endl;
}
