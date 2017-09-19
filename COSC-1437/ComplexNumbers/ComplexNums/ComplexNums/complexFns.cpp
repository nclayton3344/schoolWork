#include "complex.h"
#include <iostream>
using namespace std;

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