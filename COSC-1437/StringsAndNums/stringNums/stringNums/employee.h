//Nathaniel Clayton
//COSC1437 10/18/2017
//Check Writing Program
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Employee {

	public:
		//Function Prototypes
		Employee(); //default constructor
		Employee(string, double); //constructor
		void printCheck(ofstream&);
		void assign(string, double);

	private:
		//Data
		string employeeName; //Employee Name
		double payAmount; //Employee Pay Amount
		string curNot; //Employee Pay in Currency Notation
		string wordAmount; //Employee Pay in Words
		//Function Prototypes
		string currencyNotation(double);
		string wordFormat(double);
		string convertIntToWords(int);

};