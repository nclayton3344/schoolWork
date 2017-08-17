//Nathan Clayton Chapter 4 Program
//Speed of Sound Calculator
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	char reply, reply2;
	double distance,seconds;
	cout << fixed << showpoint << setprecision(2);

	do {
		cout << "Are you calculating the speed of sound in air, water, or steel? Select by typing A, W, or S" << endl;
		cin >> reply;
		
		if (reply != 'a' || reply != 'A' || reply != 'w' || reply != 'W' || reply != 'S' || reply != 's') {
			cout << "Type A for air, W for water, or S for steel: " << endl;
			cin >> reply;
		}

		cout << "Enter a distance in feet." << endl;
		cin >> distance;

		if (distance < 0) {
			cout << "Enter a positive value for distance in feet." << endl;
			cin >> distance;
		}

		if (reply == 'a' || reply == 'A') {
			seconds = distance / 1100;
			cout << "Through air, sound waves travel " << setprecision(1) << distance << " feet in " << setprecision(4) << seconds << " seconds." << endl;
		}
		else if (reply == 'w' || reply == 'W') {
			seconds = distance / 4900;
			cout << "Through water, sound waves travel " << setprecision(1) << distance << " feet in " << setprecision(4) << seconds << " seconds." << endl;
		}
		else  {
			seconds = distance / 16400;
			cout << "Through steel, sound waves travel " << setprecision(1) << distance << " feet in " << setprecision(4) << seconds << " seconds." << endl;
		}
		

		cout << "Would you like to check another distance? Y/N" << endl;
		cin >> reply2;
	} while (reply2 == 'y' || reply2 == 'Y');


}