//Nathaniel Clayton Headline Generator
//COSC 1436: 4/29/2017
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

//Function Prototype
int loadArray(ifstream&, string[]);

//Function to load string array with values from input file
//Precondition: ifstream declared and opened, string array declared
//Postconditon: string array given values from input file
// - returns number of elements in array
int loadArray(ifstream& in, string a[]){

    int i = 0;



    while(getline(in, a[i])){

        i++;
    }

    return i;

}


int main(){

    int headline1count, headline2count, headline3count;

    string headlines1[50], headlines2[50], headlines3[50];

    ifstream infile1, infile2, infile3;
    ofstream out;
    out.open("WeeklyNarrative.txt");
    infile1.open("h1.txt");
    infile2.open("h2.txt");
    infile3.open("h3.txt");

    if(!infile1 || !infile2 || !infile3){

        cout << "You're input files didn't open. Fission Mailed." << endl;
        return -1;
    }

    srand(unsigned(time(0)));

    headline1count = loadArray(infile1, headlines1);
    headline2count = loadArray(infile2, headlines2);
    headline3count = loadArray(infile3, headlines3);


    out << "************** The Weekly Narrative **************" << endl << endl;

    for(int i = 0; i < 10; i++){


        out << headlines1[rand() % headline1count] << " " << headlines2[rand() % headline2count] << endl;
        out << headlines3[rand() % headline3count] << endl << endl;

    }

	out << "** At The Weekly Narrative, we don't just report the news, we write it too. Now get out there and get to spinning." << endl;


    return 0;

}
