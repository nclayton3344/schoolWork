//Nathaniel Clayton - COSC 1437
//Using Classes Program - Complex Numbers
// ------  9/19/207
#include "complex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Function to Assign values to object of type Complex
//Pre-Conditon: Complex class defined and calling file includes complex.h
//Post-Conditon: Complex variable is intialized with r for real and i for imaginary number
void Complex::assign(double r, double i) {

	real = r;
	imag = i;

}

//Constructor function that assigns real and imag the value of 0
//Pre-Conditon: Complex class is defined and Complex variable is defined
//Post-Conditon: Declared complex variable is assigned real and imag values of 0
Complex::Complex() : real(0), imag(0) {

}
//Constructor that takes real and imaginary number as parameter
//Pre-Conditon: Complex class is defined and complex variable is defined 
//-----with arguments passed for real and imag number
//Post-Conditon: Complex variable is initialized with given real and imag num
Complex::Complex(double r, double i) {
	real = r;
	imag = i;
}
//Function to overload addition operator to handle adding Complex Numbers
//Pre-Conditon: Complex class defined and calling file includes complex.h
//------ and Complex variables are given values
//Post-Conditon: Complex a is added to left operand and the Complex answer is returned
Complex Complex::operator+(Complex a) {

	Complex ans;
	ans.real = real + a.real;
	ans.imag = imag + a.imag;

	return ans;

}
//Function to overload subtraction operator to handle Complex Numbers
//Pre-Conditon: Complex class defined and calling file includes header
//-----and Complex variables are given values
//Post-Conditon: right operand is subtracted from left operand
//---and answer(Complex type) is returned
Complex Complex::operator-(Complex right) {

	Complex ans;
	ans.real = real - right.real;
	ans.imag = imag - right.imag;

	return ans;

}

//Function to overload multiplication operator to handle complex numbers
////Pre-Conditon: Complex class defined and calling file includes complex.h
//------ and Complex variables are given values
//Post-Conditon: left operand is multiplied by right operand and answer is returned
Complex Complex::operator*(Complex a) {
	
	Complex ans;

	ans.real = (real * a.real) + ((-1)*(imag * a.imag));
	ans.imag = (real * a.imag) + (imag * a.real);

	return ans;

}

//Function to compare two Complex numbers for equality
//Pre-Conditon: Complex class defined and 2 Complex numbers given values
//Post-Conditon: true or false is returned based on equality
bool Complex::operator==(Complex a) {

	return ((real == a.real) && (imag == a.imag));
	

}

//Function to compare two Complex numbers for equality
//Pre-Conditon: Complex class defined and 2 Complex numbers given values
//Post-Conditon: true or false is returned based on equality
bool Complex::operator!=(Complex a) {

	return ((real != a.real) || (imag != a.imag));
		
}

Complex Complex::operator/(Complex c){

	Complex answer, conjugate;
	double denom;
	string msg = "MATH ERROR - CANNOT DIVIDE BY ZERO!";

	if (c.real == 0 && c.imag == 0)
		throw(msg);
	

	denom = (c.real*c.real) + (c.imag * c.imag);
	conjugate.real = c.real;
	conjugate.imag = -(c.imag);
	answer = (*this) * conjugate;
	answer.real /= denom;
	answer.imag /= denom;

	return answer;

}


//Function that overloads insertion operator to receive values for 
//-----complex variables
//Pre-Condition: Complex class defined and header file included in client code
//Post-Condition: values are assigned to Complex variable and istream is returned
istream& operator>>(istream & in, Complex & c) {

	cout << "Enter the real value: " << endl;
	in >> c.real;
	cout << endl << "Enter the imaginary value: " << endl;
	in >> c.imag;

	return in;
}

//Function that overloads extraction operator to display values of a complex number
//Pre-Condition: Complex class defined and header file included in client code
//Post-Condition: values of the complex variable are displayed and ostream is returned
ostream&operator<<(ostream & out, Complex & c) {
	
	char op; //Character used to display +/-

			 //Determines which operation character to display based on imag value
	if (c.imag > 0)
		op = '+';
	else
		op = '-';

	//Controls the Logic for displaying Complex Numbers
	//---in standard form based on real/imag values
	if (c.real == 0 && c.imag == 0)
		cout << "0";
	else if (c.real == 0 && c.imag != 0) {
		if (abs(c.imag) != 1)
			cout << c.imag << "i";
		else
			cout << "i";
	}
	else if (c.real != 0 && c.imag == 0)
		cout << c.real;
	else {
		if (abs(c.imag) != 1)
			cout << "(" << c.real << op << abs(c.imag) << "i)";
		else
			cout << "(" << c.real << op << "i)";
	}

	return out;
}





