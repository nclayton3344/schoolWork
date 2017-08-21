//experimenting with count controlled loops

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int age, i;

	cout << "Enter your age in years: ";
	cin >> age;
	i = 1;
	while (i <= age){
		cout << setw(2) << i << " Happy Birthday." << endl;
		i = i + 1;
	}
	for (int j = 1; j <= age; j++) {
		for (i = 1; i <= 50; i++)
			cout << "#";
		cout << endl;
	}
	cout << endl << endl;
	//accomplish the same thing using a for loop:
	for(i = 1; i <= age; i++)
		cout << setw(2) << i << " Happy Birthday." << endl;


	return 0;
}