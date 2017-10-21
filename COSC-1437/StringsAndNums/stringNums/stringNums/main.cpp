#include <iostream>	
#include <ctime>
#include <string>
#include <fstream>
#include "employee.h"
using namespace std;

const int MAX = 50; //Maximum number of Employees allowed
int loadArray(Employee[], ifstream &);

int main() {
	int employeeCount;
	string filename;
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
	cout << "Loading Array" << endl;
	employeeCount = loadArray(employees, infile);
	cout << employeeCount << endl;
	for (int i = 0; i < employeeCount; i++) {
		employees[i].printName();
	}
	cin >> employeeCount;
	return 0;
}

int loadArray(Employee array[], ifstream & in) {

	int i = 0;
	double pay;
	string name;

	while (in) {
		in >> name;
		in.ignore(40, '\n');
		in >> pay;
		in.ignore(40, '\n');
		array[i].assign(name, pay);
		i++;
	}

	return i;

}