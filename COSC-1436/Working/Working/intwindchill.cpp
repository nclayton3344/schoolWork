// Nathaniel Clayton
// International Windchill Calculator 2-4-17
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	cout << "International Wind Chill Calculator" << endl;
	cout << "-----------------------------" << endl;

	cout << fixed << showpoint << setprecision(2);
	double temp, velocity, wc, c, v,wcc;
	
	cout << "What is the velocity of the wind in KPH? " << endl;
	cin >> v;
	cout << " " << endl;

	cout << "What is the temperature in Celsius?" << endl;
	cin >> c;

	temp = (9.0 / 5)*c + 32; //converts Celsius to Fahrenheit
	velocity = (v * 0.621); //converts kph to mph

	// wc calculates windchill in Fahrenheit, wcc converts wc to Celsius
	wc = 35.74 + (0.6215 * temp) - (35.75 * pow(velocity, 0.16)) + (0.4275*temp*pow(velocity, 0.16));
	wcc = (5.0 / 9)*(wc - 32);
	cout << '\n' << "The wind chill is: " << wc << " degrees Farhenheit or " << wcc << " degrees Celsius." << endl;

}