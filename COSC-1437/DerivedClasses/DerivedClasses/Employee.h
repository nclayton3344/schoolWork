//Nathan Clayton
//Class Inheritance Project
//10/30/17
#ifndef EMPLOYEE
#define EMPLOYEE
#include <string>
#include <fstream>
using namespace std;

//Class Definition
class Employee {
public:
	//Constructors
	Employee();
	Employee(string, int, string);
	//Mutators
	void assignEmp(string, int, string);
	//Accessors
	string getName();
	int getIDNum(); 
	string getHireDate(); 
	virtual void print(ofstream &);

private:
	string name; 
	int idNum;
	string hireDate;

};

#endif
