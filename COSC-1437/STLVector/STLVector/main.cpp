//Nathaniel Clayton
//STL Vector Program
//November 1, 2017
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//Function Prototypes
void prepWord(string&);
void printGlossary(vector<string>, ofstream &);
void printSource(ifstream &);

int main() {

	//variables and filestream declarations
	ifstream readfile, ignorefile;
	ofstream out;
	vector<string> glossary, ignoreList;
	string word, filename;
	int wordSize;
	char dateStr[9];  //C-string for Date
	_strdate_s(dateStr);

	out.open("result.txt");

	cout << "Please enter the filename for your .txt file. Example: filename.txt" << endl;
	cin >> filename;

	readfile.open(filename);
	//Check File Open Success
	if (!readfile) {
		cout << "Fission Mailed!" << endl;
		cin >> wordSize;
		return 1;	
	}

	ignorefile.open("ignorewords.txt");
	//Check File Open Success
	if (!ignorefile) {
		cout << "Fission Mailed! - Ignore File Did Not Load." << endl;
		cin >> wordSize;
		return 1;
	}

	//Load ignoreList Vector
	while (ignorefile >> word) {
		ignoreList.push_back(word);
	}

	sort(ignoreList.begin(), ignoreList.end()); //sort ignoreList

	//Load glossary Vector
	while (readfile >> word) {

		prepWord(word);
		wordSize = word.size();

		if (wordSize >= 4 && (!(binary_search(ignoreList.begin(), ignoreList.end(), word)) && !(binary_search(glossary.begin(), glossary.end(), word)))) {
			glossary.push_back(word);
			sort(glossary.begin(), glossary.end());
		}
		
	}
	//Prepare file to be read again
	readfile.clear();
	readfile.close();
	readfile.open(filename);
	//Send File Contents to Output File
	out << "Printed: " << dateStr << endl << endl;
	while (getline(readfile, word)) {
		out << word << endl;
	}

	printGlossary(glossary, out);

}
//Function to remove punctuation from end of string and set string to lower case
//Pre-Condition: argument is sent as reference to enable editiing
//Post-Condition: Punctuation is removed from end of string and set to lower case 
void prepWord(string & word) {

	int i = 0, strsize = word.size();

	if (ispunct(word[strsize - 1])) {

		word = word.substr(0, strsize - 1);
		strsize = word.size();

	}

	while (i < strsize) {
		word[i] = tolower(word[i]);
		i++;
	}


}
//Function to Output *list* contents in numbered order
//Pre-Condition: output file and string vector are open and given values respectively
//Post-Condition: Output is sent to ofstream
void printGlossary(vector<string> list, ofstream & out) {

	out << endl << endl << string(5, '-') << "Glossary " << string(5, '-') << endl << endl;

	vector<string>::iterator it;
	int i = 1;
	for (it = list.begin(); it < list.end(); it++) {
		out << i  << ": " << *it << endl;
		i++;
	}

}
