//Nathaniel Clayton - COSC1437
//Word List Program - 8-29-2017

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	ifstream infile;
	ofstream outfile;

	int a;
	cout << "test" << endl;
	cin >> a;

}

//Function to load values from input file into a string array
//Precondition: ifstream declared and opened, maxElement and array given values
//Postcondition: i(number of elements in array) is returned
int loadArray(ifstream& in, int maxElements, string array[]) {

	int i;
	i = 0;

	while (getline(in, array[i])) {
		i++;
	}

	return i;
}


//Function to sort a string array alphabetically
//Precondition: string array has been given numElements # of values
//Postcondition: string array is now sorted
void sortArray(string unsorted[], int numElements) {
	int i, j, minIndex;

	string minValue;

	for (i = 0; i < numElements - 1; i++) {

		minIndex = i;
		minValue = unsorted[i];

		for (j = i + 1; j < numElements; j++) {

			if (unsorted[j] < minValue) {
				minValue = unsorted[j];
				minIndex = j;
			}
		}

		unsorted[minIndex] = unsorted[i];
		unsorted[i] = minValue;

	}


}
