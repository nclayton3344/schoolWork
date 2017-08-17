//Finding an Average using Flag Controlled Loops
//Nathan Clayton
// In C++, the input stream name can be tested like a bool variable 
// If the last input was successful, the value of the stream variable will be true
//If the last input was unsuccessful, the value will be false
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int grade, total;
	double avg;
	int i;
	i = 0;
	cout << "Enter grades to average. Enter Q to quit. " << endl;
	cout << "Enter grade " << i+1 << ":" << endl;
	cin >> grade;
	total = 0;

	while (cin){
		total += grade;
		i++;
		cout << "Enter a grade " << i+1 << ":" << endl;
		cin >> grade;
}
	if ( i > 0) {
		avg = total / double(i);
		cout << "For " << i << " grades, the average is: " << fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		cout << "No data to average." << endl;

	return 0;
}