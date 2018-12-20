//Nathan Clayton
//Class Inheritance Project
//10/30/17
#ifndef PROD
#define PROD
#include <string>
#include <fstream>
#include "Employee.h"

//Class Definition
class ProductionWorker : public Employee {

private:
	int shift;
	double payRate;

public:
	//Constructors
	ProductionWorker();
	ProductionWorker(int, double, string, int, string);
	//Mutators
	void assignPW(int, double, string, int, string);
	//Accessors
	void print(ofstream &);
	int getShift();
	double getPayRate();

};

#endif
