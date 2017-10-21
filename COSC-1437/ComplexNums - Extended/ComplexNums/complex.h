//Nathaniel Clayton - COSC 1437
//Using Classes Program - Complex Numbers
// ------  9/19/207
#include <iostream>
using namespace std;
//Class Definition for Complex Numbers
class Complex {

public:
	//Function Prototypes
	Complex(); //constructor default
	Complex(double, double);
	void assign(double, double);
	Complex operator+(Complex);
	Complex operator*(Complex);
	Complex operator-(Complex);
	bool operator==(Complex);
	bool operator!=(Complex);
	Complex operator/(Complex);

	friend istream&operator>>(istream & in, Complex & c);
	friend ostream&operator<<(ostream & in, Complex & c);


private:
	double real;
	double imag;

};

