//Nathaniel Clayton - COSC1437
//Word List Program - 8-29-2017

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

void sortArray(string[], int);
void checkPattern(string&, int);

int main() {

	string word;
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
			checkPattern(word, length);
		}

		wordCount++;

	}

	cin >> word;
	

}

void checkPattern(string & word, int length) {

	bool isCat1 = true, isCat2 = true;

	//Sets 'word' to lower case
	for (int i = 0; i < length; i++) {
		word[i] = tolower(word[i]);
	}

	for (int j = 0; j < length - 1; j++) {
		if (word[j] > word[j + 1]) {
			isCat1 = false;
			break;
		}
	}

	for (int j = length-1; j > 0; j--) {
		if (word[j] > word[j - 1]) {
			isCat2 = false;
			break;
		}
	}

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