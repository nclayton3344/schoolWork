//Nathaniel Clayton 
//Recursion Program 2
//November 11, 2017
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//Function Prototypes
int selectionSort(int[], int);
int partition(int[], int, int, int&);
int quickSort(int[], int, int);

int main() {

	srand(time(NULL));

	int original[200], copy[200];
	int complexComparisons, simpleComparisons;
	ofstream out;
	out.open("results.txt");

	//Load Array with Random Values in Range 1-1000
	for (int i = 0; i < 200; i++) {
		original[i] = rand() % 1000 + 1;
	}
	
	//Copy Arrays
	for (int i = 0; i < 200; i++) {
		copy[i] = original[i];
	}

	//Print Unsorted Array to Console
	out << "Here is the array before sorting: " << endl << endl;
	for (int i = 0; i < 200; i++) {
		out << setw(3) << i + 1 << ": " << original[i] << endl;
	}
	//Print Sorted(complex) Array to Console
	out << endl << "Here is the array sorted using Recursion: " << endl << endl;
	complexComparisons = quickSort(original, 0, 199);
	for (int i = 0; i < 200; i++) {
		out << setw(3) << i + 1 << ": " << original[i] << endl;
	}
	//Print Sorted(simple) Array to Console
	out << endl << "Here is the array sorted using the Selection Sort: " << endl << endl;
	simpleComparisons = selectionSort(copy, 200);
	for (int i = 0; i < 200; i++) {
		out << setw(3) << i + 1 << ": " << copy[i] << endl;
	}	

	out << endl << endl << string(30, '*') << "Algorithm Efficiency: " << string(30, '*') << endl << endl;
	
	out << "Predicted Comparisons for O(NlogN): " << 1528.8 << endl;
	out << "Actual Comparisons using Quicksort: " << complexComparisons << endl << endl;

	out << "Predicted Comparisons for O(N^2): " << 40000 << endl;
	out << "Actual Comparisons using Selection Sort: " << simpleComparisons << endl << endl;

	if (simpleComparisons < 40000)
		out << "The Simple Sort was more Efficient than expected." << endl << endl;

	if (complexComparisons < 1528.8)
		out << "The Complex Sort Was more Efficient than expected. " << endl << endl;

	if (simpleComparisons > complexComparisons)
		out << "The Complex Sort algorithm was the most efficient of the 2 algorithms." << endl;
	else
		out << "The Simple Sort algorithm was more efficient than the Complex Sort. " << endl;



	cin >> original[1];

	return 0;
}
//Function to sort an array
//Pre-Condition: Array must be given values with known num or elements
//Post-Condition: array is sorted, number of comparisons is returned
int selectionSort(int a[], int elements) {

	int i, j, minIndex, compareCount = 0;

	int minValue;

	for (i = 0; i < elements - 1; i++) {

		minIndex = i;
		minValue = a[i];

		for (j = i + 1; j < elements; j++) {
			compareCount++;
			if (a[j] < minValue) {
				minValue = a[j];
				minIndex = j;
			}
		}

		a[minIndex] = a[i];
		a[i] = minValue;

	}
	return compareCount;
}
//Function to place a pivot in middle of an array
//Pre-Condition: Array is given values
//Post-Condition: the index for the pivot is returned
int partition(int a[], int start, int end, int& compare) {

	int pivotValue, pivotIndex, mid;

	mid = (start + end) / 2;
	swap(a[start], a[mid]);
	pivotIndex = start;
	pivotValue = a[start];

	for (int i = start + 1; i <= end; i++) {

		compare++;
		if (a[i] < pivotValue) {
			pivotIndex++;
			swap(a[pivotIndex], a[i]);
		}

	}

	swap(a[start], a[pivotIndex]);
	return pivotIndex;
}
//Function to sort an array
//Pre-Condition: Array must be given values with known num or elements
//Post-Condition: array is sorted, number of comparisons is returned
int quickSort(int a[], int start, int end) {

	int compareCount = 0;
	int pivotpoint;

	if (start < end) {
		pivotpoint = partition(a, start, end, compareCount);
		quickSort(a, start, pivotpoint - 1);
		quickSort(a, pivotpoint + 1, end);
	}
	return compareCount;
}
