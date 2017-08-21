//Finding an average using a flag controlled loop
//In C++, the input stream name can be tested like a bool variable
//If the last input was successful, the value of the stream variable will be true.
//If the last input was unsuccessful, the value will be false.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int grade, total;
	int i;  //holds number of valid grades so far
	double avg;

	cout << "Enter grades to average; enter Q to quit. "<<endl;
	
	total = 0;
	i = 0;
	cout << "Enter grade " << setw(2) << i+1 << " :";
	cin >> grade;   //a priming read
	while (cin) {
		total = total + grade;
		i++;
		cout << "Enter grade " << setw(2) << i+1 << " :";
		cin >> grade;  //read the next input

	}
	cout << endl << endl;
	if (i > 0) {
		avg = double(total) / i;
		cout << "For " << i << " grades, the average is: "
			<< fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		cout << "No data to average." << endl;

	return 0;
}