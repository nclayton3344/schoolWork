//Nathan Clayton
//Class Inheritance Project
//10/30/17
#include "Employee.h"
#include "TeamLead.h"
#include "ShiftSuper.h"
#include "ProductionWorker.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void leadHeader(ofstream &);
void pwHeader(ofstream &);
void supHeader(ofstream &);
void print(Employee&, ofstream &);
void loadPWArray(ProductionWorker[], int);
void loadTLArray(TeamLead[], int);
void loadSupArray(ShiftSuper[], int);

int main() {
	ofstream out;
	out.open("Report.txt");
	ProductionWorker prodWorkers[20];
	ShiftSuper supervisiors[10];
	TeamLead leaders[10];
	
	int superCount, leadCount, pwCount;

	
	cout << "Welcome to the Employee Roster Builder. Let's Begin!" << endl;
	cout << "Please Enter the Number(10 max) of Shift Supervisors: " << endl;
	cin >> superCount;
	cout << "Please Enter the Number(10 max) of Team Leaders: " << endl;
	cin >> leadCount;
	cout << "Please Enter the Number(20 max) of Production Workers: " << endl;
	cin >> pwCount;
	
	loadPWArray(prodWorkers, pwCount);
	loadTLArray(leaders, leadCount);
	loadSupArray(supervisiors, superCount);

	supHeader(out);
	for (int i = 0; i < superCount; i++)
		print(supervisiors[i], out);



	leadHeader(out);
	for (int i = 0; i < leadCount; i++)
		print(leaders[i], out);



	pwHeader(out);
	for (int i = 0; i < pwCount; i++)
		print(prodWorkers[i], out);




}

//Function to out header for Team Leaders to file
//Pre-Condition: Takes ofstream object as argument
//Post-Condition: Header is output to file
void leadHeader(ofstream & out) {
	out << string(100, '*') << endl << endl;
	out << string(48, ' ') << "Team Leaders" << endl << endl;
	out << string(100, '*') << endl << endl;
	out << left << setw(20) << "Team Leader Name: "  << setw(10) << " Employee ID: " << setw(10) << " Date of Hire: " << setw(10) << " Shift: "  << setw(10) << " Pay Rate: "  << setw(10) << " Bonus Amount: " << setw(15) <<" Training Hours: " << endl << endl;

}

//Function to out header for Production Workers to file
//Pre-Condition: Takes ofstream object as argument
//Post-Condition: Header is output to file
void pwHeader(ofstream & out) {
	out << string(100, '*') << endl << endl;
	out << string(45, ' ') << "Production Workers" << endl << endl;
	out << string(100, '*') << endl << endl;
	out << left << "Production Employee Name: " << setw(20) << " Employee ID: " << setw(20) << " Date of Hire: " << setw(20) << " Shift: " << setw(20) << " Pay Rate: "  << endl << endl;
}

//Function to out header for Shift Supervisors to file
//Pre-Condition: Takes ofstream object as argument
//Post-Condition: Header is output to file
void supHeader(ofstream & out) {
	out << string(100, '*') << endl << endl;
	out << string(45, ' ') << "Shift Supervisors" << endl << endl;
	out << string(100, '*') << endl << endl;
	out << left << setw(30) << "Shift Supervisor Name: " << setw(20) << " Employee ID: " << setw(27) << " Date of Hire: " << setw(15) << " Salary: " << setw(15) << " Bonus: " << endl << endl;

}

//Function to load array of Production Workers with user defined values
//Pre-Condition: Requires ProductionWorker array and int as arguments
//Post-Condition: array is loaded with user defined values
void loadPWArray(ProductionWorker arr[], int count) {
	string name, doh;
	int id, shift;
	double pay;
	
	for (int i = 0; i < count; i++) {
		cout << "Enter Production Worker Name: " << endl;
		cin.ignore(40, '\n');
		getline(cin, name);
		cout << "Enter Worker ID Num: " << endl;
		cin >> id;
		cout << "Enter Employee Date of Hire (Ex. 10/17/87): " << endl;
		cin.ignore(40, '\n');
		getline(cin, doh);
		cout << "Enter Worker Shift Number(1 or 2): " << endl;
		cin >> shift;
		cout << "Enter Worker Pay: " << endl;
		cin >> pay;
		arr[i].assignPW(shift, pay, name, id, doh);
	}

}

//Function to load array of TeamLead with user defined values
//Pre-Condition: Requires TeamLead array and int as arguments
//Post-Condition: array is loaded with user defined values
void loadTLArray(TeamLead arr[], int count) {
	string name, doh;
	int id, shift, train;
	double pay, bonus;

	for (int i = 0; i < count; i++) {
		cout << "Enter Team Leader Name: " << endl;
		cin.ignore(40, '\n');
		getline(cin, name);
		cout << "Enter Worker ID Num: " << endl;
		cin >> id;
		cout << "Enter Employee Date of Hire (Ex. 10/17/87): " << endl;
		cin.ignore(40, '\n');
		getline(cin, doh);
		cout << "Enter Worker Shift Number(1 or 2): " << endl;
		cin >> shift;
		cout << "Enter Number of Training Hours Worked: " << endl;
		cin >> train;
		cout << "Enter Hourly Wage: " << endl;
		cin >> pay;
		cout << "Enter Bonus Pay:" << endl;
		cin >> bonus;
		
		arr[i].assignTeamLead(bonus, train, shift, pay, name, id, doh);
	}
	

}

//Function to load array of Shift Supervisors with user defined values
//Pre-Condition: Requires ShiftSuper array and int as arguments
//Post-Condition: array is loaded with user defined values
void loadSupArray(ShiftSuper arr[], int count) {

	string name, doh;
	int id;
	double pay, bonus;

	for (int i = 0; i < count; i++) {
		cout << "Enter Supervisor Name: " << endl;
		cin.ignore(40, '\n');
		getline(cin, name);
		cout << "Enter Supervisor ID Num: " << endl;
		cin >> id;
		cout << "Enter Employee Date of Hire (Ex. 10/17/87): " << endl;
		cin.ignore(40, '\n');
		getline(cin, doh);
		cout << "Enter Supervisor Salary: " << endl;
		cin >> pay;
		cout << "Enter Bonus Pay:" << endl;
		cin >> bonus;
		arr[i].assignSS(pay, bonus, name, id, doh);
	}


}

//Function to bind member function
//Pre-Condition: Requires Employee Base Class and ofstream object as arguments
//Post-Condition: virtual function print is called
void print(Employee & employee, ofstream & out) {

	employee.print(out);

}