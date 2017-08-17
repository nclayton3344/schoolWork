// Nathaniel Clayton
// Windchill Calculator 2-4-17
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() { 
	cout << "Wind Chill Calculator" << endl;
	cout << "-----------------------------" << endl;

	cout << fixed << showpoint << setprecision(2);
	double temp, velocity,wc;
	
	cout << "What is the velocity of the wind in MPH? " << endl;
	cin >> velocity;
	cout << " " << endl;

	cout << "What is the temperature in Fahrenheit?" << endl;
	cin >> temp;

	// wc calculates windchill
	wc = 35.74 + (0.6215 * temp) - (35.75 * pow(velocity, 0.16)) + (0.4275*temp*pow(velocity, 0.16));
	cout << '\n' << "The wind chill is: " << wc << " degrees Fahrenheit." << endl;

}