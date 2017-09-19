class Complex {

public:
	Complex();
	void assign(double, double);
	void print();
	Complex addto(Complex);
	Complex multiplyby(Complex);

private:
	double real;
	double imag;
	
};