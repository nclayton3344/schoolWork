//Nathan Clayton 
//4-13-17 Arrays in Functions
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 50;
int loadArray(ifstream &, int[]);
void printArray(int[], int);
int sumValues(int[], int);
void selectionSort(int[], int);

//*Selection Sort* Function that sorts an array in ascending order
//Precondition: elements have n values 
//Postcondition: array elements have been sorted to ascending order
void selectionSort(int a[], int n) {
	int i, j, lowIndex; // hold index values ALWAYS type int
	int temp; // Holds value for swapping

	for (i = 0; i < n-1; i++) {

		lowIndex = i; // Sets 'top' index to be min index to start sorting

		for (j = i + 1; j < n; j++) { // find index of smallest value left

			if (a[j] < a[lowIndex])
				lowIndex = j;
		}
		//swap smallest value with the 'top' value
		if (lowIndex != i) {
			temp = a[lowIndex];
			a[lowIndex] = a[i];
			a[i] = temp;

		}

	}
	

}

int main(){
	int grades001[MAX], grades002[MAX];
	int count1, count2, sum1 = 0, sum2 = 0;
	double classAvg1, classAvg2;
	cout << fixed << showpoint << setprecision(2);
	ifstream infile1, infile2;
	infile1.open("section001.txt");
	infile2.open("section002.txt");
	if (!infile1 || !infile2) {
		cout << "Problem opening at least one file. Fission Mailed." << endl;
		return 1;
	}

	count1 = loadArray(infile1, grades001);
	count2 = loadArray(infile2, grades002);

	cout << "Grades from Section 001 in original order: " << endl;
	printArray(grades001, count1);
	cout << "Grades from Section 001 in asecending order: " << endl;
	selectionSort(grades001, count1);
	printArray(grades001, count1);
	sum1 = sumValues(grades001, count1);
	classAvg1 = double(sum1) / count1;
	cout << "For " << count1 << " Students, the Class Average for Section 001: " << classAvg1 << endl<<endl;
	cout << "******************************************************" << endl<<endl;
	cout << "Grades from Section 002 in original order: " << endl;
	printArray(grades002, count2);
	cout << "Grades from Section 002 in asecending order: " << endl;
	selectionSort(grades002, count2);
	printArray(grades002, count2);
	sum2 = sumValues(grades002, count2);
	classAvg2 = double(sum2) / count2;
	cout << "For " << count2 << " Students, the Class Average for Section 002: " << classAvg2 << endl << endl;
	cout << "******************************************************" << endl << endl;

	return 0;

}

int loadArray(ifstream &, int[]);
void printArray(int[], int);
int sumValues(int[], int);

//Function that display values in an array, one per line
//Precondtion: array is filled with count values
//Postcondition: values have been displayed
void printArray(int array[], int a) {

	for (int i = 0; i < a; i++)
		cout << setw(4) << array[i] << endl;

	cout << endl;

}
//Function to sum all valid values in array
//Precondtion: array is filled with count values
//Postcondition: sum of values is returned
int sumValues(int grades[], int num) {
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum += grades[i];
	return sum;
}
//Function to put values from a file into an Array
//Precondition: infile stream opened successfully, array has been declared and Max set
//Postconditon: the array will be filled with count values cout < = MAX; function returns count (num of elements)
int loadArray(ifstream & in, int grades[]) {
	int count = 0;
	while (count < MAX && in >> grades[count]) {
		count++;
	}
		
	return count;
}