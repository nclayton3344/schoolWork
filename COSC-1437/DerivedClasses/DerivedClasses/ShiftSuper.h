//Nathan Clayton
//Class Inheritance Project
//10/30/17
#ifndef SUPER
#define SUPER
#include "Employee.h"
#include <string>
#include <fstream>
using namespace std;

//Class Definition
class ShiftSuper : public Employee {


public:
	//Constructors
	ShiftSuper();
	ShiftSuper(double, double, string, int, string);
	//Mutators
	void assignSS(double, double, string, int, string);
	//Accessors
	double getSalary();
	double getBonus();
	void print(ofstream &);

private:
	double salary, superBonus;
};

#endif