//C Young 3/27/2017
//This program implements a guessing game.
//Examples of functions with value and/or reference parameters
//Learning how to use the RNG functions

#include <iostream>
#include <string>
#include <cstdlib>     //needed for RNG functions
#include <ctime>       //needed to seed rand with clock value

using namespace std;

void printlines(int, int, char);       //function prototypes
bool GuessOne(int, int);
void SetSecret(int&, int&);

int main() {
	int secret, high, count;
	bool done;
	char reply;

	srand(unsigned(time(0)));   //seed the RNG with system clock value in seconds
	do {
		count = 0;
		SetSecret(secret, high);

		do {
			done = GuessOne(secret, high);
			count++;
		} while (!done);
		printlines(1, 60, '#');
		cout << "The secret number was: " << secret << endl;
		cout << "You guessed it in " << count << " tries." << endl;
		printlines(1, 60, '#');

		cout << " Play another game? y/n ";
		cin >> reply;
		reply = tolower(reply);
		cin.ignore(40, '\n');
		system("CLS");

	} while (reply == 'y');
	cout << "Thanks for playing the GUESSING GAME!" << endl;
	return 0;

}

//function SetSecret asks user for high value of range and sets the secret number
//Preconditions: RNG has been seede in main
//Postconditions: using REFERENCE parameters, the function returns values for
//                secret and high value.

void SetSecret(int& secret, int& high) {

	do {
		cout << "Give the high value for range of numbers to guess: " << endl;
		cout << "Choose a high between 30 and 30,000." << endl;
		cin >> high;
	} while (high < 30 || high > 30000);

	secret = rand() % high + 1;
	printlines(2, 60, '=');
	cout << endl << endl;
}

//This function handles ONE user guess.
//Preconditions: secret and high have been set
//Postconditions: function tells user if correct, high, or low
//                function returns true if correct, false otherwise
bool GuessOne(int secret, int high) {
	int guess;
	cout << "Guess my number between 1 and " << high << ": ";
	cin >> guess;
	if (guess == secret)
		cout << "CORRECT!" << endl;
	else if (guess < secret) {
		cout << "TOO LOW." << endl;
		printlines(1, 60, '-');
	}
	else {
		cout << "TOO HIGH." << endl;
		printlines(1, 60, '+');
	}

	return secret == guess;
}






void printlines(int numlines, int numsyms, char symbol) {  //formal parameters
	int row, col;  //local variables

	for (row = 1; row <= numlines; row++) {
		for (col = 1; col <= numsyms; col++)
			cout << symbol;
		cout << endl;
	}


}