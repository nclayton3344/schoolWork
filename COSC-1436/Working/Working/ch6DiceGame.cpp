#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//FUNCTION DEFINITIONS
void keepRolling(int);
void firstRoll(int);
void printCraps();
void printRules();
void displayDice(int, int);
int rollDice();

//Function with logic for after first roll
//Precondition: Player Did not win on first roll and point has been given a value
//Postcondition: Player has won or lost by matching point or rolling 7
void keepRolling(int point){
    int sum;

    do{

       sum = rollDice();

    }while(sum!=point && sum!=7);

     if(sum == point)
        cout << "You made your point! Great job, YOU WIN!" << endl;
     else
        cout << "Sorry, you didn't make your point. You LOSE!" << endl;

}

//Function with logic for winning on first roll
//Precondition: a has been given the value of the sum of dice on first roll
//Postcondition: Player won, lost, or moves on further into game
void firstRoll(int a){


    if (a == 7 || a ==11)
        cout << "You WIN! Great Roll!" << endl;
    else if (a == 2 || a == 3 || a ==12){
        cout << "What a horrible roll, you lose." << endl << endl;
        printCraps(); //Function Call
        }
    else{
        cout << "All you have to do is match your roll of " << a << ". Just keep rolling." << endl;
        keepRolling(a); //Function Call
    }
}

//Function that prints a large visual of the word CRAPS!
//Precondition: It has been called by another function
//Postcondition: does nothing until called again
void printCraps(){

    cout << " ######     ########        ###       ########      ######     #### " << endl
         << "##    ##    ##     ##      ## ##      ##     ##    ##    ##    #### " << endl
         << "##          ##     ##     ##   ##     ##     ##    ##          #### " << endl
         << "##          ########     ##     ##    ########      ######      ##  " << endl
         << "##          ##   ##      #########    ##                 ##         " << endl
         << "##    ##    ##    ##     ##     ##    ##           ##    ##    #### " << endl
         << " ######     ##     ##    ##     ##    ##            ######     #### " << endl<<endl;
}

//Function to display rules of the game to the user
//Precondition: It has to be called by another function to print
//Postcondition: does nothing until called again
void printRules() {

	cout << "***************************************************************" << endl << endl
		<< "A player begins by rolling two dice. If the sum is 7 or 11 on " << endl
		<< "the first throw, the player wins. If the sum is 2, 3, or 12 on " << endl
		<< "the first throw (called \"craps\"), the player loses." << endl
		<< "If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then " << endl
		<< "that sum becomes the player's \"point\". If you don't win or " << endl
		<< "lose on the first roll, you must continue rolling the dice until " << endl
		<< "you win or lose. If you \"make your point\", you win; if you " << endl
		<< "roll a 7, you lose." << endl << endl
		<< "***************************************************************" << endl << endl;

}

//Function that displays dice face to console
//Precondition: rollDice() has been called and each die (d1 & d2) has been given values
//Postcondition: After displaying die faces it returns to calling function
void displayDice(int d1, int d2){
	char a, b, c, d, e, f, g, h, i, j, k, l, m, n;
    int total = d1 + d2;

	switch (d1){
    case 1:
        f = 'O', a = ' ', e = ' ', k = ' ', b = ' ', g = ' ', l = ' ';
        break;
    case 2:
        f = ' ', a = 'O', e = ' ', k = ' ', b = ' ', g = ' ', l = 'O';
        break;
    case 3:
        f = 'O', a = 'O', e = ' ', k = ' ', b = ' ', g = ' ', l = 'O';
        break;
    case 4:
        f = ' ', a = 'O', e = ' ', k = 'O', b = 'O', g = ' ', l = 'O';
        break;
    case 5:
        f = 'O', a = 'O', e = ' ', k = 'O', b = 'O', g = ' ', l = 'O';
        break;
    case 6:
        f = ' ', a = 'O', e = 'O', k = 'O', b = 'O', g = 'O', l = 'O';
        break;
    default:
        f = 'O', a = 'O', e = 'O', k = 'O', b = 'O', g = 'O', l = 'O';
        break;
	}

	switch (d2){
    case 1:
        i = 'O', c = ' ', h = ' ', m = ' ', d = ' ', j = ' ', n = ' ';
        break;
    case 2:
        i = ' ', c = 'O', h = ' ', m = ' ', d = ' ', j = ' ', n = 'O';
        break;
    case 3:
        i = 'O', c = 'O', h = ' ', m = ' ', d = ' ', j = ' ', n = 'O';
        break;
    case 4:
        i = ' ', c = 'O', h = ' ', m = 'O', d = 'O', j = ' ', n = 'O';
        break;
    case 5:
        i = 'O', c = 'O', h = ' ', m = 'O', d = 'O', j = ' ', n = 'O';
        break;
    case 6:
        i = ' ', c = 'O', h = 'O', m = 'O', d = 'O', j = 'O', n = 'O';
        break;
    default:
        i = 'O', c = 'O', h = 'O', m = 'O', d = 'O', j = 'O', n = 'O';
        break;
	}

   cout << " -----------    ----------- " << endl
	     << " | "<<a<<"     "<<b<<" |    | "<<c<<"     "<<d<<" | " << endl
	     << " |         |    |         | " << endl
	     << " | "<<e<<"  "<<f<<"  "<<g<<" |    | "<<h<<"  "<<i<<"  "<<j<<" | " << endl
	     << " |         |    |         | " << endl
	     << " | "<<k<<"     "<<l<<" |    | "<<m<<"     "<<n<<" | " << endl
	     << " -----------    ----------- " << endl<< endl << endl
	     << "You Rolled a " << total << "!" << endl;

}

//Function that assigns random values to die1 and die2 similar
//Precondition: must be called to serve it's purpose and has necessary include files for srand and time
//Postcondition: returns sum of die1 and die2 to calling function
int rollDice() {

    char ch;
	int sum, die1, die2;

	cout << "Press Enter to Roll the Dice: " << endl;
	cin.get(ch);

	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	sum = die1 + die2;

	displayDice(die1,die2); //Function Call
	return sum;


}

//First function, this is where the game starts
//Precondition: Code compiles properly
//Postcondition: Program is terminated
int main(){
    char reply = 'y';
    int sum;
	srand(unsigned(time(0)));

    printCraps(); //Function Call
	printRules(); //Function Call

	do{
    cout << "Let's Begin!" << endl;
	sum = rollDice(); // Function Call
	firstRoll(sum); //Function Call

	cout << "Would you like to play again? Y/N"  << endl;
	cin.get(reply);
    cin.ignore(40,'\n');
	}while(reply == 'y' || reply == 'Y');

	return 0;
}

