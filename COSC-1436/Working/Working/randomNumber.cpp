// Nathan Clayton
// Guessing Game Program
// Demonstrates the use of reference parameters and RNG functions
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void symbolPrint(int, int, char); // function prototypes
void setSecret(int&, int&);
bool guessOne(int, int);

int main() {
	int secret, high, count;
	bool done;

	count = 0;
	srand(unsigned(time(0))); // seed the RNG with system clock
	setSecret(secret, high);

	do {
		done = guessOne(secret, high);
		count++;
	} while (!done);

	symbolPrint(1, 60, '^');
	cout << "The secret number was " << secret << endl;
	cout << "You made " << count << " guesses." << endl;

	return 0;
}

	// setSecret sets the range and secret number using reference parameters
	//Precondition: RNG has been seeded
	//Postcondition: Range is set by user and secret number established
	void setSecret(int& secret, int& high) {
		do {
			cout << "Enter the value for highest number in desired range. " << endl;
			cout << "Choose a high value between 50 - 30,000." << endl;
			cin >> high;

		} while (high < 50 || high > 30000);

		secret = rand() % high + 1;
	}
	
	//This function handles everything for one guess by the user
	//Precondition: Secret is set and high given by user 
	//Postcondition: User is informed if guess is high, low or correct. Function returns true if correct answer, false otherwise.
	bool guessOne(int secret, int high) {
		int guess;
		symbolPrint(1, 60, '^');
		cout << "Guess my number between 1 and " << high << ": " << endl;
		cin >> guess;

		if (guess < secret)
			cout << "Too Low!" << endl;
		else if (guess > secret)
			cout << "Too High!" << endl;
		else
			cout << "Correct!" << endl;

		return secret == guess;
	}

void symbolPrint(int a, int b, char symbol) {

	int row, col;
	for (row = 1; row <= a; row++) {
		for (col = 1; col <= b; col++)
			cout << symbol;
		cout << endl;
	}
}
