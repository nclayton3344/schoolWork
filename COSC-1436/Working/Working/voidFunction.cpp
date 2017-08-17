#include <iostream>
#include <string>
using namespace std;

void testFunction(int, int, char);

int main() {
	string name;
	int count;
	testFunction(4,9, '?');
	cout << "Enter your first name. " << endl;
	cin >> name;

	cout << "enter the number of semesters you have been at SPC: " << endl;
	cin >> count;

	testFunction(1,2, name[0]);
	cout << "Proceed to first registration station: " << endl;
	testFunction(count, count, '[');
	
	return 0;
}

void testFunction(int a, int b, char symbol) {
	
	int row, col;
	for (row = 1; row <= a; row++) {
		for (col = 1; col <= b; col++)
			cout << symbol;
		cout << endl;
	}
}