//Nathaniel Clayton 9-7-17
//Array of Structs Assignment
//Program to print reports for class grade information
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Data Type Student
//This holds multiple types of data related to a single student
struct Student{

	int studentID;
	string lname, fname;
	int exams[3];
	double examAvg;
	
};

//Function Prototypes
int loadArray(Student[], ifstream&, int);
void sortbyID(Student[], int);
void sortbyLast(Student[], int);
void printPostedGrades(Student[], ofstream&, int);
void printTeacherReport(Student[], ofstream&, int);
double calculateFinalAverage(Student[], int);
double calculateClassAvgExam(Student[], int, int);
int calculateHighestAvg(Student[], int);
int calculateLowestAvg(Student[], int);

int main() {

	int studentCount;
	const int MAX = 50;
	string filename;
	ifstream infile;
	ofstream outfile, outfile2;
	Student stuInfo[MAX];
	outfile.open("Report3.txt");
	outfile2.open("Report4.txt");

	do {

		cout << "Enter the name of the input file: (Example: \"filename.txt\")" << endl;
		cin >> filename;
		infile.open(filename);

		if (!infile) {
			cout << "Fission Mailed! Something went horribly wrong." << endl;
			return 1;
		}

	} while (!infile);

	studentCount = loadArray(stuInfo, infile, MAX);

	//Sort stuInfo array by studentID
	//and Print info for posting grades
	sortbyID(stuInfo, studentCount);
	printPostedGrades(stuInfo, outfile, studentCount);

	//Sort stuInfo array by lname
	//and print info for teacher report
	sortbyLast(stuInfo, studentCount);
	printTeacherReport(stuInfo, outfile2, studentCount);

}

//Function to load array of structs with data
//Pre-Condtion: Student Struct array defined, ifstream defined, MAX size of array defined
//Post-Conditon: Student struct array given values and the number of entries is returned
int loadArray(Student stuInfo[], ifstream& in, int MAX) {

	int i = 0;

	while (!in.eof()) {

		in >> stuInfo[i].studentID;
		in >> stuInfo[i].lname;
		in >> stuInfo[i].fname;
		in >> stuInfo[i].exams[0];
		in >> stuInfo[i].exams[1];		
		in >> stuInfo[i].exams[2];

		stuInfo[i].examAvg = (stuInfo[i].exams[0] + stuInfo[i].exams[1] + stuInfo[i].exams[2]) / 3.0;

		i++;
	}

	return i;


}

//Function to sort struct array by studentID 
//Pre-Conditon: Student struct array defined and number of elements is known
//Post-Conditon: Struct array is sorted by studentID 
void sortbyID(Student unsorted[], int numElements) {
	int i, j, minIndex;

	Student minValue;

	for (i = 0; i < numElements - 1; i++) {

		minIndex = i;
		minValue = unsorted[i];

		for (j = i + 1; j < numElements; j++) {

			if (unsorted[j].studentID < minValue.studentID) {
				minValue = unsorted[j];
				minIndex = j;
			}
		}

		unsorted[minIndex] = unsorted[i];
		unsorted[i] = minValue;

	}


}

//Function to sort struct array by student last name 
//Pre-Conditon: Student struct array defined and number of elements is known
//Post-Conditon: Struct array is sorted by student last name
void sortbyLast(Student unsorted[], int numElements) {
	int i, j, minIndex;

	Student minValue;

	for (i = 0; i < numElements - 1; i++) {

		minIndex = i;
		minValue = unsorted[i];

		for (j = i + 1; j < numElements; j++) {

			if (unsorted[j].lname < minValue.lname) {
				minValue = unsorted[j];
				minIndex = j;
			}
		}

		unsorted[minIndex] = unsorted[i];
		unsorted[i] = minValue;

	}


}

//Function to Output Grades along with Student ID - then class average
//Pre-Conditon: Student struct array defined, ofstream defined, number of elements is known
//Post-Conditon: Output is generated to a txt file
void printPostedGrades(Student student[], ofstream& out, int count) {

	out << fixed << showpoint << setprecision(2);

	out << setw(20) << left << "Student ID:" << setw(20) << left << "Final Average" << endl << endl;

	for (int i = 0; i < count; i++) {
		out << setw(20) << left << student[i].studentID << setw(20) << student[i].examAvg << endl;
	}

	out << endl << endl << "Class Average: " << calculateFinalAverage(student, count) << endl;

}

//Function to Output Teacher Report with all student info and class statistics
//Pre-Conditon: Student struct array defined, ofstream defined, number of elements is known
//Post-Conditon: Output is generated to a txt file
void printTeacherReport(Student student[], ofstream& out, int count) {

	out << fixed << showpoint << setprecision(2);

	int acount, bcount, ccount, dcount, fcount, lowIndex, highIndex;
	acount = bcount = ccount = dcount = fcount = 0;
	lowIndex = calculateLowestAvg(student, count);
	highIndex = calculateHighestAvg(student, count);

	for (int i = 0; i < count; i++) {

		if (student[i].examAvg < 60)
			fcount++;
		else if (student[i].examAvg < 70)
			dcount++;
		else if (student[i].examAvg < 80)
			ccount++;
		else if (student[i].examAvg < 90)
			bcount++;
		else
			acount++;
	}

	out << left << setw(20) << "Student Name" << setw(20) << "Student ID #" << setw(20) << "Exam 1" << setw(20) << "Exam 2"
		<< setw(20) << "Exam 3" << setw(20) << "Final Average" << endl << endl;

	for (int j = 0; j < count; j++) {

		out << left << setw(20) << student[j].fname + " " + student[j].lname << setw(20) << student[j].studentID << setw(20) << student[j].exams[0] << setw(20) << student[j].exams[1]
			<< setw(20) << student[j].exams[2] << setw(20) << student[j].examAvg << endl << endl;

	}
	
	out << endl << endl << endl;
	out << "****** CLASS STATISTICS: ******" << endl << endl;
	out << "Total Number of Students in Class: " << count << endl << endl;
	out << "The Class Average for Exam 1 is: " << calculateClassAvgExam(student, count, 0) << endl << endl;
	out << "The Class Average for Exam 2 is: " << calculateClassAvgExam(student, count, 1) << endl << endl;	
	out << "The Class Average for Exam 3 is: " << calculateClassAvgExam(student, count, 2) << endl << endl;
	out << acount << " students finished the class with an A. That's " << (double(acount) / count) * 100 << "% of the class." << endl << endl;
	out << bcount << " students finished the class with a B. That's " << (double(bcount) / count) * 100 << "% of the class." << endl << endl;
	out << ccount << " students finished the class with a C. That's " << (double(ccount) / count) * 100 << "% of the class." << endl << endl;
	out << dcount << " students finished the class with a D. That's " << (double(dcount) / count) * 100 << "% of the class." << endl << endl;
	out << fcount << " students finished the class with an F. That's " << (double(fcount) / count) * 100 << "% of the class." << endl << endl;
	out << "The Class' Final Average: " << calculateFinalAverage(student, count) << endl << endl;
	out << student[highIndex].fname + " " + student[highIndex].lname + " (" << student[highIndex].studentID << ") had the highest final average of " << student[highIndex].examAvg << endl << endl;
	out << student[lowIndex].fname + " " + student[lowIndex].lname + " (" << student[lowIndex].studentID << ") had the lowest final average of " << student[lowIndex].examAvg << endl << endl;

}

//Function that calculates the class' final average
//Pre-Condtion: Student struct array defined with count elements
//Post-Condition: final average for entire class is returned
double calculateFinalAverage(Student student[], int count) {

	double gradeTotals = 0;

	for (int i = 0; i < count; i++) {

		gradeTotals += student[i].examAvg;

	}

	return (gradeTotals / count);

}

//Function to calculate the class' average for exam at struct data -> exams[index]
//Pre-Conditon: Struct array defined with count elements and given index value for exam
//Post-Conditon: class average for exam at index is returned
double calculateClassAvgExam(Student student[], int count, int index) {

	int total = 0;

	for (int i = 0; i < count; i++) {

		total += student[i].exams[index];

	}

	return (total / double(count));

}

//Function to Calculate Highest Final Average
//Pre-Conditon: Student struct is defined with count elements
//Post-Conditon: index of student in s array (with highest average) is returned
int calculateHighestAvg(Student s[], int count) {

	double high = 0.0;
	int highIndex = 0;

	high = s[0].examAvg;
	for (int i = 0; i < count; i++) {

		if (s[i].examAvg > high) {
			high = s[i].examAvg;
			highIndex = i;
		}
		
	}

	return highIndex;

}

//Function to Calculate Lowest Final Average
//Pre-Conditon: Student struct is defined with count elements
//Post-Conditon: index of student in s array (with lowest average) is returned
int calculateLowestAvg(Student s[], int count) {

	double low = 0.0;
	int lowIndex;

	low = s[0].examAvg;
	for (int i = 0; i < count; i++) {

		if (s[i].examAvg < low) {
			low = s[i].examAvg;
			lowIndex = i;
		}

	}

	return lowIndex;

}