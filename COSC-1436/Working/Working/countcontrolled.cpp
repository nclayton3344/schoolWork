//Count Controlled Loops
//Nathan Clayton
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int age;
	int i;
	cout << "Enter your age in years. ";
	cin >> age;
	i = 1;
	while (i <= age){
		cout << setw(2) << i << " Happy Birthday!" << endl;
		i++;
}
	cout << endl << endl;

	int j;
	for (j = 1; j <= age; j++) {

		for (i = 1; i <= age; i++) {
			cout << "*" << endl;
			i++;
			j++;
		}
		
		
	}

	cout << endl << endl;

	for (i = 1; i <= age; i++)
		cout << setw(2) << i << " Happy Birthday!" << endl;
	return 0;
}