#include <iostream>
#include <fstream>
using namespace std;

int main() {

	double *ptr;
	int size;
	ofstream out;
	out.open("pointerlab.txt");

	cout << "How many entries do you want?" << endl;
	cin >> size;
	out << "You chose " << size << " entries." << endl;
	
	ptr = new double[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter Value number " << i + 1 << endl;
		cin >> ptr[i];
	}

	out << "The values you entered are: " << endl;
	for (int j = 0; j < size; j++) {
		out << ptr[j] << endl;
	}

	delete ptr;

}