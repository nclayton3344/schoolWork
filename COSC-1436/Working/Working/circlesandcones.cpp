//Nathaniel Clayton Section 2
//Circles and Cones Program
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.1416;

int main() {
	string div = "-------------------------";
	double h, r, r2, area, circum, volsph, volcon, surfareasph, slanth,surfareacon;
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Enter the radius of the circle in cenimeters." << endl;
	cin >> r;
	r2 = r * r;
	area = PI * r2; // calculates area
	circum = 2 * PI * r; //calculates circumference
	volsph = (4.0 / 3)*PI*(r*r*r); //calculates volume of a sphere
	surfareasph = 4 * PI * r2; //calculates surface area of a sphere
	
	cout << "What is the height of the cone in cenimeters? " << endl;
	cin >> h;

	volcon = (1 / 3.0)* PI * r2 *h; //calculates volume of cone
	slanth = sqrt(r2 + (h * h)); // calculates slant height
	surfareacon = (PI * r2) + (PI * r * slanth); //calculates surface area of cone

	//Displays all calculations 
	cout << "Circle" << endl;
	cout << div << endl;
	cout << "Area: " << setw(19) << area << " sq. cm" <<  endl;
	cout << "Circumference: " << setw(10) << circum << " cm" << endl;
	cout << " " << endl;
	cout << "Sphere" << endl;
	cout << div << endl;
	cout << "Volume: " << setw(16) << volsph << " cubic cm" << endl;
	cout << "Surface Area: " << setw(10) << surfareasph << " cubic cm" << endl;
	cout << " " << endl;
	cout << "Cone" << endl;
	cout << div << endl;
	cout << "Volume: " << setw(16) << volcon << " cubic cm" << endl;
	cout << "Slant Height: " << setw(10) << slanth << " cm"  << endl;
	cout << "Surface Area: " << setw(10) << surfareacon << " cubic cm" << endl;
}