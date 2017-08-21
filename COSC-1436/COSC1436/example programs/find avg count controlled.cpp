//Finding an average using a count controlled loop
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int num, grade, total;
	int i;
	double avg;

	cout << "Enter number of grades to average: ";
	cin >> num;
	total = 0;
	i = 1;
	while (i <= num) {
		cout << "Enter grade " << setw(2) << i << " :";
		cin >> grade;
		total = total + grade;
		i++;
	}
	cout << endl << endl;
	if (num > 0) {
		avg = double(total) / num;
		cout << "For " << num << " grades, the average is: "
			<< fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		cout << "No data to average." << endl;

	return 0;
}