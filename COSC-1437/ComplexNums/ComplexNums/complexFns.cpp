#include "complex.h"
#include <iostream>
#include <cmath>
using namespace std;

//Function to Assign values to object of type Complex
//Pre-Conditon: Complex class defined and calling file includes complex.h
//Post-Conditon: Complex variable is intialized with r for real and i for imaginary number
void Complex::assign(double r, double i) {

	real = r;
	imag = i;

}

//Function that prints the Complex Numbers in standard form
//Pre-Conditon: Complex class defined and calling file includes complex.h
//----- and the calling Complex variable has been given values
//Post-Conditon: The Complex number is output in standard form
void Complex::print() {

	char op;

	if (imag > 0)
		op = '+';
	else
		op = '-';

	if (real == 0 && imag == 0)
		cout << "0";
	else if (real == 0 && imag != 0){

		if (abs(imag) != 1)
			cout << imag << "i";
		else
			cout << "i";
	}
	else if (real != 0 && imag == 0)
		cout << real;
	else {
		if (abs(imag) != 1)
			cout << "(" << real << op << abs(imag) << "i)";
		else
			cout << "(" << real << op << "i)";
	}
}

//Function that adds Complex Numbers a to self
//---- self meaning the complex variable that is calling the member function
//Pre-Conditon: Complex class defined and calling file includes complex.h
//------ and Complex variables are given values
//Post-Conditon: Complex a is added by self and the Complex answer is returned
Complex Complex::addto(Complex a) {

	Complex ans;
	ans.real = real + a.real;
	ans.imag = imag + a.imag;

	return ans;

}

//Function that multiplies Complex Numbers a to self
//---- self meaning the complex variable that is calling the member function
//Pre-Conditon: Complex class defined and calling file includes complex.h
//------ and Complex variables are given values
//Post-Conditon: Complex a is multiplied by self and the Complex answer is returned
Complex Complex::multiplyby(Complex a) {
	
	Complex ans;

	ans.real = (real * a.real) + ((-1)*(imag * a.imag));
	ans.imag = (real * a.imag) + (imag * a.real);

	return ans;

}
Complex::Complex() : real(0), imag(0) {

}

