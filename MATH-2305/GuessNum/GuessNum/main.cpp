//Nathan Clayton
//MATH-2305 2-14-18
//Number Guess Program
#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
void printRules();
void printSet(int);

int main() {
	
	int myGuess = 0;
	char reply, confirm;

	do {
		//Begin Game sequence
		printRules();
		cout << "Press Enter to begin." << endl;
		cin.ignore(40, '\n');

		//Cycles through 6 Sets of Numbers
		for (int i = 0; i < 6; i++) {

			//Prints Number Set and Get Confirmation from User
			printSet(i+1);
			cout << endl << "Is your number in the set above? " << endl;
			cin.get(confirm);
			cin.ignore(40, '\n');
			//Increment Guess
			if (confirm == 'y')
				myGuess += pow(2, i);
		}

		//Predict Number
		cout << endl << "I predict that your number is " << myGuess << "! How did I do?" << endl;

		//Asks user to play again
		cout << "Would you like to play again?" << endl;
		cin.get(reply);
		cin.ignore(40, '\n');
		reply = tolower(reply);
		myGuess = 0;

		}while (reply == 'y');
		
		//Terminate
		cout << endl << "Thanks for playing!" << endl;
		cin.get(reply);
		reply = tolower(reply);
		cin.ignore(40, '\n');

	return 0;

}

//Function to display the rules of the game to the console
//Pre-Condition: string must be included 
//Post-Condition: Rules are displayed to console
void printRules() {

	cout << string(65, '*') << endl << endl;
	cout << "In this game, you will pick a number between 1-50. Once you " << endl << 
		"have selected your number, I will display a set of numbers. You" << endl <<
		"will then indicate whether your selected number is among those" << endl <<
		"being displayed. I will guess your number after displaying only" << endl <<
		"6 sets of numbers." << endl << endl;
	cout << string(65, '*') << endl << endl;

}

//Function to display one of 6 sets of numbers
//Pre-Condition: desired set number must be passed as num
//Post-Condition: The set number is output to console
void printSet(int num) {

	cout << "SET NUMBER : " << num << endl << endl;

	switch (num) {

	case 1:
		cout << " 1   3   5   7   9" << endl <<
			"11  13  15  17  19" << endl <<
			"21  23  25  27  29" << endl <<
			"31  33  35  37  39" << endl <<
			"41  43  45  47  49" << endl; 
		break;
	case 2:
		cout << " 2   3   6   7  10" << endl <<
			"11  14  15  18  19" << endl <<
			"22  23  26  27  30" << endl <<
			"31  34  35  38  39" << endl <<
			"42  43  46  47  50" << endl;
		break;
	case 3:
		cout << " 4   5   6   7  12" << endl <<
			"13  14  15  20  21" << endl <<
			"22  23  28  29  30" << endl <<
			"31  36  37  38  39" << endl <<
			"44  45  46  47" << endl;
		break;
	case 4:
		cout << " 8   9  10  11  12" << endl <<
			"13  14  15  24  25" << endl <<
			"26  27  28  29  30" << endl <<
			"31  40  41  42  43" << endl <<
			"44  45  46  47" << endl;
		break;
	case 5:
		cout << "16  17  18  19  20" << endl <<
			"21  22  23  24  25" << endl <<
			"26  27  28  29  30" << endl <<
			"31  48  49  50" <<  endl;
		break;
	case 6:
		cout << "32  33  34  35  36" << endl <<
			"37  38  39  40  41" << endl <<
			"42  43  44  45  46" << endl <<
			"47  48  49  50" << endl;
		break;
	default:
		break;

	}


}