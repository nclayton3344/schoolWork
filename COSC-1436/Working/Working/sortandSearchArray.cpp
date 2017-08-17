//Nathaniel Clayton Array Sort/Search Project
//COSC1436-002
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//Function Prototypes
int binarySearch(string[], int, string);
void sortArray(string[], int);
void printArray(ifstream&, ofstream&, string[], int);
int loadArray(ifstream&, int, string[]);

//Function to perform binary search on string array
//Precondition: string array is filled with count elements and 
// - search has been given a value
//Post conditon: returns index if the search value is found in 
// - the array, otherwise returns -1
int binarySearch(string a[], int count, string search) {

	int top, bottom, mid;
	top = 0; bottom = count - 1;
	while (top <= bottom) {

		mid = (top + bottom) / 2;

		if (a[mid] == search)
			return mid;
		else if (a[mid] > search)
			bottom = mid - 1;
		else
			top = mid + 1;
	}

	return -1;

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

//Function to print values of the array in order of index
//Precondition: ifstream & ofstream declared and opened, string array given values,
// - count given value of indexes in array
//Postcondition: values of the array are output in order of index
void printArray(ifstream & input, ofstream & out, string array[], int count) {

	int i;
	for (i = 0; i < count; i++)
		out << setw(3) << i + 1 << ". " << setw(12) << array[i] << endl;

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

int main() {

	const int MAX = 50;
	int oneElements, twoElements, searchIndex, search2Index;
	string search;

	ifstream infile1, infile2, infile3;
	ofstream outfile;

	infile1.open("wordlist1.txt");
	infile2.open("wordlist2.txt");
	infile3.open("searchvaluelist.txt");

	outfile.open("searchResults.txt");

	string wordsOne[MAX], wordsTwo[MAX];



	if (!infile1 || !infile2 || !infile3) {
		cout << "Something went wrong opening the files. Check your input files, son!" << endl;
		return -1;
	}

	oneElements = loadArray(infile1, MAX, wordsOne);
	twoElements = loadArray(infile2, MAX, wordsTwo);

	outfile << "******* UNSORTED LIST ONE**************" << endl << endl;

	printArray(infile1, outfile, wordsOne, oneElements);

	outfile << endl << endl;

	outfile << "******* UNSORTED LIST TWO**************" << endl << endl;

	printArray(infile1, outfile, wordsTwo, twoElements);

	outfile << endl << endl;

	outfile << "********** SORTED LIST ONE ***********" << endl << endl;

	sortArray(wordsOne, oneElements);
	sortArray(wordsTwo, twoElements);

	printArray(infile1, outfile, wordsOne, oneElements);

	outfile << endl << endl;

	outfile << "********** SORTED LIST TWO ***********" << endl << endl;


	printArray(infile2, outfile, wordsTwo, twoElements);

	outfile << endl << endl;

	outfile << "*************** SEARCH RESULTS **************" << endl << endl;

	while (getline(infile3, search)) {

		searchIndex = binarySearch(wordsOne, oneElements, search);
		search2Index = binarySearch(wordsTwo, twoElements, search);
		
		if (searchIndex >= 0)
			outfile << "The word " << search << " was found in array 1 at position " << searchIndex << " ";
		else
			outfile << "The word " << search << " was not found in array 1 ";

		if (search2Index >= 0)
			outfile << "and was found in array 2 at position " << search2Index << "." << endl << endl;
		else
			outfile << "and was not found in array 2." << endl << endl;


	}


}

