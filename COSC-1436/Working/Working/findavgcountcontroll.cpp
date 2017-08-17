//Finding an Average using Count Controlled Loops
//Nathan Clayton
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int num, grade, total;
	double avg;
	int i;
	cout << "Enter number of grades to average. ";
	cin >> num;
	i = 1;
	total = 0;
	while (i <= num){
		cout << "Enter a grade: " << endl;
		cin >> grade;
		total += grade;
		i++;
}
	if (num > 0) {
		avg = total / double(num);
		cout << "For " << num << " grades, the average is: " << fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		cout << "No data to average.";

	return 0;
}