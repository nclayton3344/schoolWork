//Nathaniel Clayton
//Recursive Program One
//November 8, 2017
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Function Prototypes
template<class T>
T iterativeFactorial(T);
template<class T>
T recursiveFactorial(T);
void printFactorials(ofstream &);

int main() {

	int a = 12;
	double b = 170.6;
	cout << fixed << showpoint << setprecision(2) << endl;
	ofstream out;
	out.open("factorial.txt");
	
	printFactorials(out);

	cin >> a;

	return 0;
}

//Templated Function to Compute Factorial Iteratively
//Pre-Condition: T must be of a data type that can use * arithmetically
//----for (num < 13), if num>=13 - out of range
//Post-Condition: the factorial answer is returned
template<class T>
T iterativeFactorial(T num) {
	T test = num;
	T factorial = 1;

	for (num; num > 0; num--) {
		factorial *= num;
	}
	return factorial;
}
//Templated Function to Compute Factorial Recursively
//Pre-Condition: T must be of a data type that can use * arithmetically
//----for (num <= 171.6), if num>170.6 - out of range
//Post-Condition: the factorial answer is returned
template<class T>
T recursiveFactorial(T num) {
	
	if (num == 0)
		return 1;
	else
		return num * recursiveFactorial(num - 1);
}
//Function to print factorials of double and int values
//Pre-Condition: iterativeFactorial and recursiveFactorial must be defined
//Post-Condition: 3 column chart is output to console
void printFactorials(ofstream & out) {

	out << string(40, '*') << " TYPE INT " << string(40, '*') << endl << endl;
	out << setw(30) << "FACTORIAL: " << setw(30) << "ITERATIVE FACTORIAL: " << setw(30) << "RECURSIVE FACTORIAL: " << endl << endl;

	for (int i = 1; i < 13; i++) 
		out << setw(25) << i << "!" << setw(30) << iterativeFactorial(i) << setw(30) << recursiveFactorial(i) << endl;
	
	out << endl << endl << string(40, '*') << " TYPE DOUBLE " << string(40, '*') << endl << endl;
	out << setw(30) << "NUMBER: " << setw(30) << "ITERATIVE FACTORIAL: " << setw(30) << "RECURSIVE FACTORIAL: " << endl << endl;
	out << scientific;
	for(double i = 1; i < 171; i++)
		out << fixed << setprecision(0) << noshowpoint << setw(25) << i << "!" << setw(30) << scientific << setprecision(2) << iterativeFactorial(i) << setw(30) << recursiveFactorial(i) << endl;
	
}