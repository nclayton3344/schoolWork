//Example program that uses functions and arrays
//C Young 4/13/2017
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 50;

int LoadArray(ifstream&, int[]);
void PrintArray(int[], int);
int SumValues(int[], int);
void SelectionSort(int[], int);

int main() {
	int section1[MAX], section2[MAX];
	int count1, count2, sum1, sum2;
	double cavg1, cavg2;
	ifstream infile1, infile2;

	//open input file streams and test for success
	infile1.open("section001.txt");
	infile2.open("section002.txt");
	if (!infile1 || !infile2) {
		cout << "Problem opening at least one input file. Abort program." << endl;
		return 1;
	}

	count1 = LoadArray(infile1, section1);
	count2 = LoadArray(infile2, section2);
	cout << fixed << showpoint << setprecision(2);
	cout << "Grades from section 001 in original order:" << endl;
	PrintArray(section1, count1);
	cout << "Grades from section 001 in ascending order:" << endl;
	SelectionSort(section1, count1);
	PrintArray(section1, count1);
	sum1 = SumValues(section1, count1);
	cavg1 = double(sum1) / count1;
	cout << "For " << count1 << " students, ";
	cout << "Class Average for section1: " << cavg1 << endl << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Grades from section 002:" << endl;
	PrintArray(section2, count2);
	sum2 = SumValues(section2, count2);
	cavg2 = double(sum2) / count2;
	cout << "For " << count2 << " students, ";
	cout << "Class Average for section2: " << cavg2 << endl << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	return 0;
}

//function to put values from a file into an array
//Preconditions: input file stream is successfully opened
//Postconditions: the array is filled with count values. count is <= MAX.
//                function returns count which is # of elements, NOT the last index!
int LoadArray(ifstream& infile, int a[]) {
	int count=0;

	while (count < MAX && infile >> a[count]) {
		count++;
	}
	return count;

}

//function to display values in an array, one per line
//Preconditions: array is filled with count values
//Postconditions: values have been displayed to screen
void PrintArray(int a[], int count) {
	for (int i = 0; i < count; i++)
		cout << setw(4) << a[i] << endl;

	cout << endl;
}

//function to sum all valid values in the array
//Preconditions: array is filled with count values
//Postconditions: sum of values is returned
int SumValues(int a[], int count) {
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += a[i];
	return sum;
}
//function to sort all valid values in the array in ASCENDING order
//Selection Sort algorithm is used
//Preconditions: array is filled with count values
//Postconditions: array elements have been changed to be in ascending order
void SelectionSort(int a[], int count) {
	int i, j, min; //these all hold index values, will ALWAYS be type int
	int temp;      //this local varaible is for swapping values, must be
	               // of same type as the array!!

	for (i = 0; i < count - 1; i++) {

		min = i;   //setting the "top" index i to be the min index to begin

		for (j = i + 1; j < count; j++) //find index of "smallest" value left
			if (a[j] < a[min])
				min = j;

		//swap smallest value with the "top" value
		if (min != i) //check that small value is not already at "top"
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		} //end swap

	}//end of outside for loop
}// end function body