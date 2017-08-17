//Nathaniel Clayton COSC-1436-002
//Museum Attendance Report Program
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAX = 14;
const int ATTENDMAX = 32000;

//FUNCTION PROTOTYPES*********
void displayHeader(ofstream&);
void printAttendance(int[], ofstream&);
void maxandMin(int[], ofstream&);
double avgAttendance(int, int, int[]);
int readAttendance(ifstream&, int[]);

//Function that Displays Report Header with current date
//PreCondition: ofstream has been declared and opened
//Post: output sent to file
void displayHeader(ofstream& output){

	char date[9];
	_strdate_s(date);


output << "*************************************************************" << endl;
output << "|  Nathan Clayton                                 " << date << "  |"<< endl;
output << "|                                                           |" << endl;
output << "|                    Attendance Report                      |" << endl;
output << "|                                                           |" << endl;
output << "*************************************************************" << endl;
output << endl << endl;


}

//Function that outputs daily attendance to file
//Pre: dailyAttend has been filled with MAX values, ofstream declared and opened
//Post: outputs daily attendance to file
void printAttendance(int dailyAttend[], ofstream& out){
    string lines = "-------------------------------------------------------------";


    out << "Daily Attendance: " << endl << endl;
    out << lines << endl;

    for (int i = 0; i < MAX; i++){
        out << "Day " << setw(3) <<  i+1 << ": " << setw(52) << dailyAttend[i] << endl << endl;
        out << lines << endl;
    }

}

//Function that calculates the min and max attendances
//Pre: attendance has been intialized and given values, ofstream declared and opened
//Post: Sends output to file
void maxandMin(int attendance[], ofstream& out){
    int minAttend = ATTENDMAX, maxAttend = 0, minDay, maxDay;

    for(int i = 0; i < MAX; i++){

        if(attendance[i]>maxAttend){
            maxAttend = attendance[i];
            maxDay = i+1;
        }
        if(attendance[i]<minAttend){
            minAttend = attendance[i];
            minDay = i+1;
        }
    }

    out << "Maximum Attendance: " << maxAttend << " on day: " << setw(28) << maxDay << endl << endl;
    out << "-------------------------------------------------------------" << endl;
    out << "Minimum Attendance: " << minAttend << " on day: " << setw(28) << minDay << endl << endl;

}

//Function that calculates the average attendance
//Pre: attend is given values and start and stop are valid indexes of attend
//Post: returns avg attendance to calling function
double avgAttendance(int start, int stop, int attend[]){

    int sum, counter;
    sum = 0;
    counter = 0;
    double avg;

    for(start; start<=stop; start++){

            sum+= attend[start];
            counter++;
    }

    avg = double(sum) / counter;

    return avg;

}

//Function that reads values from input file to an array
//Pre: ifstream initialized and opened, dA has been declared
//Post: dA filled with values from input file
int readAttendance(ifstream&input, int dA[]){

    int sum = 0;

    for (int i = 0; i < MAX; i++){

        input >> dA[i];
        sum += dA[i];

    }

    return sum;

}

int main(){

    string lines;
    lines = "-------------------------------------------------------------";

    int dailyAttendance[MAX];
    
	ifstream infile;
	ofstream outfile;
	outfile.open("attendanceReport.txt");
    infile.open("testfile");
    if(!infile)
        cout << "Something Went Wrong! Fission Mailed!" << endl;

	outfile << fixed << showpoint << setprecision(1) << endl;

    displayHeader(outfile); //Function call
	                                                                                 
    outfile << "The Total Attendance for " << MAX << " Days is: " << setw(24) << readAttendance(infile, dailyAttendance) << endl << endl; //Function Call
    outfile << lines << endl;                                                        
    outfile << "Average Attendance for " << MAX << " Days: " << setw(29) << avgAttendance(0, (MAX-1), dailyAttendance) << endl << endl; //Function Call
    outfile << lines << endl;

    maxandMin(dailyAttendance, outfile); //Function Call

    outfile << lines << endl;
    outfile << "Average Attendance for First 3 Days: " << setw(24) <<avgAttendance(0, 2, dailyAttendance) << endl << endl; //Function Call
    outfile << lines << endl;
    outfile << "Average Attendance for Last 3 Days: " << setw(25) << avgAttendance((MAX-3), (MAX-1), dailyAttendance) << endl << endl; //Function Call
    outfile << lines << endl << endl;

    printAttendance(dailyAttendance, outfile); //Function Call

    }

