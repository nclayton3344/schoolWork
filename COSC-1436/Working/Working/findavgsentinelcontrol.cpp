//Finding an Average using Sentinel Controlled Loops
//Nathan Clayton
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int grade, total;
	double avg;
	int i;
	i = 0;
	cout << "Enter grades to average. Enter -1 to quit. " << endl;
	cout << "Enter grade " << i+1 << ":" << endl;
	cin >> grade;
	
	total = 0;
	while (grade != -1){
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