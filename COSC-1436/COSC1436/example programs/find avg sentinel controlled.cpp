//Finding an average using a sentinel controlled loop
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int grade, total;
	int i;  //holds number of valid grades so far
	double avg;

	cout << "Enter grades to average; enter -1 to quit. "<<endl;
	
	total = 0;
	i = 0;
	cout << "Enter grade " << setw(2) << i+1 << " :";
	cin >> grade;
	while (grade != -1) {
		total = total + grade;
		i++;
		cout << "Enter grade " << setw(2) << i+1 << " :";
		cin >> grade;

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