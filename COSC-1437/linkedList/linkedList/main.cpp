//Nathaniel Clayton
//LinkedList Program
//November 18, 2017
#include <iostream>
#include <string>
#include "SortedList.h"
#include <fstream>
using namespace std;

//Function Prototypes
void displayMenu();

int main() {

	int menuOption;
	string word;
	char reply = 'y';
	SortedList<string> list;

	//Display Header
	cout << string(65, '*') << endl << endl;
	cout << "Welcome to the List Maker App! - What Would You Like to Do?" << endl
		<< "Enter One of the Options Below to Continue." << endl << endl;;
	cout << string(65, '*')  << endl;

	do {
		displayMenu();
		cout << endl << endl;

		cin >> menuOption;

		switch (menuOption) {
		case 1:
			cout << "What would you like to add to the list?" << endl;
			cin >> word;
			list.insert(word);
			break;
		case 2:
			cout << "What value would you like to check?" << endl;
			cin >> word;
			if (list.find(word))
				cout << "We found " << word << " in the list!" << endl;
			else
				cout << "Sorry, we did not find " << word << " in the list." << endl;
			break;
		case 3:
			cout << "What Item Would You Like to Remove from the List?" << endl;
			cin >> word;
			list.remove(word);
			break;
		case 5:
			if (list.size() > 0) {
				cout << endl << "***** ASCENDING LIST *****" << endl;
				list.ascending();
			}
			else
				cout << "Sorry, the List is Empty." << endl;
			break;
		case 4:
			cout << "Number of Items in the List: " << list.size() << endl;
			break;
		case 6:
			if (list.size() > 0) {
				cout << endl << "***** DESCENDING LIST *****" << endl;
				list.descending();
			}
			else
				cout << "Sorry, the List is Empty." << endl;
			break;
		case 7:
			list.deleteList();
			break;
		default:
			break;
		}

		cout << endl << "Would you like to continue? Enter Y/N" << endl;
		cin >> reply;
		cin.ignore(40, '\n');
		tolower(reply);
	} while (reply == 'y');
	return 0;
}

//Function to display user menu to console
//Pre-Condition: iostream must be included
//Post-Condition: menu is displayed on console
void displayMenu(){


	cout << endl << "1.) Add Item to List" << endl;
	cout << "2.) Find an Item in The List" << endl;
	cout << "3.) Remove an Item from The List" << endl;
	cout << "4.) Display Number of Items in the List" << endl;
	cout << "5.) Display The List in Ascending Order" << endl;
	cout << "6.) Display the List in Descending Order" << endl;
	cout << "7.) Delete List" << endl;




}