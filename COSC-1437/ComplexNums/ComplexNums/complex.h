//Nathaniel Clayton - COSC 1437
//Using Classes Program - Complex Numbers
// ------  9/19/207

//Class Definition for Complex Numbers
class Complex {

public:
	//Function Prototypes
	Complex(); //constructor default
	void assign(double, double);
	void print();
	Complex addto(Complex);
	Complex multiplyby(Complex);

private:
	double real;
	double imag;	
};