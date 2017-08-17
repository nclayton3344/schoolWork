// Nathan Clayton, Xabier Mendoza, Janae Coleman
//Selection Structures Group Project
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	cout << fixed << showpoint << setprecision(2);
	double a, b, c, x1, x2, z;
	// Takes input from user
	cout << "What is the value of a? " << endl;
	cin >> a;
	cout << "What is the value of b? " << endl;
	cin >> b;
	cout << "What is the value of c?" << endl;
	cin >> c;
	
	z = ((b*b) - (4 * a * c)); // Calculation to determine number of solutions

	cout << a << "x^2 + " << b << "x + " << c << endl; // prints general form to console


	if (z < 0) { // For no real solutions
		cout << "This polynomial has NO real solutions." << endl;
	}


	else	if (z > 0) { // Calculations for 2 solutions
			x1 = ((-1 * b) + sqrt(z)) / (2 * a);
			x2 = ((-1 * b) - sqrt(z)) / (2 * a);
			cout << "This polynomial has 2 real solutions. They are x = " << x1 << " and x = " << x2 << endl;

		}
	
	else	 { // Calculates for one solution since z == 0 
				x1 = (-1 * b) / (2 * a);
				cout << "This polynomial has one unique solution. The solution is x = " << x1 << endl;
			}

}
		