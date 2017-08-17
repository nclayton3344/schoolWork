//Nathaniel Clayton 4/6/2017
//Ch6 Calendar Program
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void printDays(int, int &, ofstream&); //Function 
int printHeader(int, int, ofstream&); //  Prototypes
int janFirst(int);//Function
bool isLeap(int);// Prototypes

//Function that prints days of the month in calendar style structure to outfile
//Precondition: daysInMonth & dow have been given value and outfile declared
//Postcondition: prints days in month to outfile
void printDays(int daysInMonth, int & dow, ofstream& outfile){

	int j,tab;

	outfile << "|";
	for (j=1; j <= daysInMonth; j++){

		if(j==1)
			tab = (4*(dow+1));
		else
			tab = 4;
		
		outfile << setw(tab) << j;
		dow ++;
		if (dow > 6 && j!=daysInMonth){

			dow = 0;
			outfile << " |" << endl;
			
			
			}
	}
		if (dow != 7)
		outfile << setw((7-dow)*tab) << "|" << endl;

}

//Function that prints header with month and year to outfile
//Precondition: month and year have been give values and outfile declared
//Postcondition: returns number of days in month to calling function
int printHeader(int month, int year, ofstream& outfile){
    string monthName;
    int daysInMonth;
    int spaceValue = 15;


    switch(month){

    case 0:
        monthName = "January";
        daysInMonth = 31;
        break;
    case 1:
        monthName = "February";
        if (isLeap(year))    //Function call as condition
            daysInMonth = 29;
        else
            daysInMonth = 28;
        break;
    case 2:
        daysInMonth = 31;
        monthName = "March";
        break;
    case 3:
        daysInMonth = 30;
        monthName = "April";
        break;
    case 4:
        daysInMonth = 31;
        monthName = "May";
        break;
    case 5:
        daysInMonth = 30;
        monthName = "June";
        break;
    case 6:
        daysInMonth = 31;
        monthName = "July";
        break;
    case 7:
        daysInMonth = 31;
        monthName = "August";
        break;
    case 8:
        daysInMonth = 30;
        monthName = "September";
        break;
    case 9:
        daysInMonth = 31;
        monthName = "October";
        break;
    case 10:
        daysInMonth = 30;
        monthName = "November";
        break;
    case 11:
        daysInMonth = 31;
        monthName = "December";
        break;
    default:
        break;
    }

    outfile << "===============================" << endl;
    outfile << "#" << setw(spaceValue) << monthName << "  " << year <<"        #" << endl;
    outfile << "#                             #" << endl;
    outfile << "#  S   M   T   W   T   F   S  #" << endl;
    outfile << "===============================" << endl;

    return daysInMonth;

}

//Function that determines which day of the week Jan 1st is on
//Precondition: year has been given value by user
//Post condition: return first's day of the week to calling function
int janFirst(int year) {
    year = year - 1;
    int firstOnDay;
    firstOnDay = (1 + year + (year / 4) - (year / 100) + (year / 400)) % 7;

    return firstOnDay;
}

//Function that determines if a year is a Leap year
//Precondition: year has been given value by user
//postcondition: returns true if year is leap year
bool isLeap(int year) {

    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));

}

int main() {
    int year, i, dayofWeek;
    ofstream outfile;
    outfile.open("calendar.txt");

    cout << "Enter Year of the Calendar You Wish to View. It must be greater than 1600: " << endl;
    cin >> year;

    if (year < 1600) {
        cout << "You Entered an Invalid Year. Please Enter a Year Greater than 1600." << endl;
        cin >> year;
    }

    dayofWeek = janFirst(year); //Function call

    for (i = 0; i <=11; i++){

            printDays (printHeader(i, year, outfile), dayofWeek, outfile); //Function call within function call

    }




    return 0;
}
