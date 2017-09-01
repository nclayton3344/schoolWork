//Nathaniel Clayton - COSC1437
//Word List Program - 8-29-2017

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

void sortArray(string[], int);
bool checkCat1(string&, int);
bool checkCat2(string&, int);
void printExplan();


int main() {

	string word;
	bool isCat1, isCat2;
	int wordCount = 0;
	int cat1Count = 0, cat2Count = 0;
	const int MAX = 10000;
	string category1[MAX], category2[MAX];

	ifstream infile;
	ofstream outfile;
	infile.open("wordList.txt");

	if (!infile) {
		cout << "Something went wrong." << endl;
	}

	while (infile >> word) {

		int length = word.length();

		if (length > 4){
			isCat1 = checkCat1(word, length);
			isCat2 = checkCat2(word, length);

			if (isCat1) {
				category1[cat1Count] = word;
				cat1Count++;
			}
			else if (isCat2) {
				category2[cat2Count] = word;
				cat2Count++;
			}
		}

		wordCount++;

	}

	sortArray(category1, cat1Count);
	sortArray(category2, cat2Count);

	cout << "Date/Time: " << __TIMESTAMP__ << endl << endl;
	printExplan();

	cout << endl << " ----- Category 1 -----" << endl << endl;

	for (int i = 0; i < cat1Count; i++) {
		cout << setw(3) << i+1 << ": " <<  category1[i] << endl;
	}

	cout << fixed << showpoint << setprecision(4);
	cout << endl << "I found " << cat1Count << " words out of " << wordCount << " words that fit in Category 1. That's a total of " << float(cat1Count) / wordCount << "%!" << endl;

	cout << endl << "----- Category 2 -----" << endl << endl;

	for (int i = 0; i < cat2Count; i++) {
		cout << setw(3) << i+ 1 << ": " << category2[i] << endl;
	}

	cout << endl << "I found " << cat2Count << " words out of " << wordCount << " words that fit in Category 2. That's a total of " << float(cat2Count) / wordCount << "%!" << endl;

	cin >> word;
	

}

bool checkCat1(string & word, int length) {

	//Sets 'word' to lower case
	for (int i = 0; i < length; i++) {
		word[i] = tolower(word[i]);
	}

	for (int j = 0; j < length - 1; j++) {
		if (word[j] > word[j + 1]) {
			return false;
		}
	}
	return true;
}

bool checkCat2(string & word, int length) {

	//Sets 'word' to lower case
	for (int i = 0; i < length; i++) {
		word[i] = tolower(word[i]);
	}

	for (int j = length - 1; j > 0; j--) {
		if (word[j] > word[j - 1]) {
			return false;
		}
	}
	return true;
}

void printExplan() {

	cout << "----CATEGORIES EXPLANATION-----------------------------------------------------------------------------------------" << endl << endl;
	cout << "Category 1: a group of words whose indiviudal characters are in alphabetically increasing order from left to right." << endl;
	cout << "Category 2: a group of words whose indiviudal characters are in alphabetically increasing order from right to left." << endl;
	cout << "                          *Note: Both categories allow for consecutive repeating letters." << endl;
	cout << endl << "-------------------------------------------------------------------------------------------------------------------" << endl;
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
