//Nathaniel Clayton
//COSC-1437 10/18/2017
//Check Writing Program
#include <iostream>	
#include <ctime>
#include <string>
#include <fstream>
#include "employee.h"
using namespace std;

const int MAX = 50; //Maximum Number of Employees
int loadArray(Employee[], ifstream &);

int main() {

	int employeeCount;
	ifstream infile;
	ofstream outfile;
	const int MAX = 50;
	outfile.open("checkFile.txt");

	do {

		infile.open("stringNums.txt");

		if (!infile) {
			cout << "Fission Mailed! Something went horribly wrong." << endl;
			return 1;
		}

	} while (!infile);

	Employee employees[MAX];
	employeeCount = loadArray(employees, infile);
	for (int i = 0; i < employeeCount; i++) {
		employees[i].printCheck(outfile);
	}

	return 0;
}
//Function to load an array of up to 50 Employee Objects from a file
//Pre-Conditon: input file and array are passed as arguments
//Post-Condtion: Array is filled with data from input file for
//----each employee object
int loadArray(Employee array[], ifstream & in) {

	int i = 0;
	double pay;
	string name;

	while (in) {
		getline(in, name);
		in >> pay;
		in.ignore(40, '\n');
		array[i].assign(name, pay);
		i++;
	}

	return i;

}