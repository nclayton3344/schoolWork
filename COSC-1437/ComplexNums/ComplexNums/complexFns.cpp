#include "complex.h"
#include <iostream>
using namespace std;

//Function to Assign values to object of type Complex
//Pre-Conditon: Complex class defined and calling file includes complex.h
//Post-Conditon: Complex variable is intialized with r for real and i for imaginary number
void Complex::assign(double r, double i) {

	real = r;
	imag = i;

}


void Complex::print() {

	cout << real << endl;
	cout << imag << endl;

}

Complex Complex::addto(Complex a) {

	return a;

}
Complex Complex::multiplyby(Complex a) {

	return a;

}
Complex::Complex() {

	real = 0;
	imag = 0;

}