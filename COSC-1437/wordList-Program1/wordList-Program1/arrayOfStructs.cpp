#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student{

	int studentID;
	string lname, fname;
	int exam1, exam2, exam3;
	double examAvg;
	
};

int loadArray(Student[], ifstream&, int);
void sortbyID(Student[], int);
void sortbyLast(Student[], int);
void printPostedGrades(Student[], ofstream&, int);
void printTeacherReport(Student[], ofstream&, int);
double calculateFinalAverage(Student[], int);
double calculateClassAvgExam1(Student[], int);
double calculateClassAvgExam2(Student[], int);
double calculateClassAvgExam3(Student[], int);
int calculateHighestAvg(Student[], int);
int calculateLowestAvg(Student[], int);

int main() {

	int studentCount;
	const int MAX = 50;
	ifstream infile;
	ofstream outfile, outfile2;
	Student stuInfo[MAX];
	infile.open("STURECS2.txt");
	outfile.open("Report3.txt");
	outfile2.open("Report4.txt");

	if (!infile) {
		cout << "Fission Mailed! Something went horribly wrong." << endl;
		return 0;
	}
	
	studentCount = loadArray(stuInfo, infile, MAX);

	sortbyID(stuInfo, studentCount);
	printPostedGrades(stuInfo, outfile, studentCount);

	sortbyLast(stuInfo, studentCount);
	printTeacherReport(stuInfo, outfile2, studentCount);


}

int loadArray(Student stuInfo[], ifstream& in, int MAX) {

	int i = 0;

	while (!in.eof()) {

		in >> stuInfo[i].studentID;
		in >> stuInfo[i].lname;
		in >> stuInfo[i].fname;
		in >> stuInfo[i].exam1;
		in >> stuInfo[i].exam2;		
		in >> stuInfo[i].exam3;

		stuInfo[i].examAvg = (stuInfo[i].exam1 + stuInfo[i].exam2 + stuInfo[i].exam3) / 3.0;

		i++;
	}

	return i;


}

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

void printPostedGrades(Student student[], ofstream& out, int count) {

	out << fixed << showpoint << setprecision(2);

	out << setw(20) << left << "Student ID:" << setw(20) << left << "Final Average" << endl << endl;

	for (int i = 0; i < count; i++) {
		out << setw(20) << left << student[i].studentID << setw(20) << student[i].examAvg << endl;
	}

	out << endl << endl << "Class Average: " << calculateFinalAverage(student, count) << endl;

}

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

		out << left << setw(20) << student[j].fname + " " + student[j].lname << setw(20) << student[j].studentID << setw(20) << student[j].exam1 << setw(20) << student[j].exam2
			<< setw(20) << student[j].exam3 << setw(20) << student[j].examAvg << endl << endl;

	}
	
	out << endl << endl << endl;
	out << "****** CLASS STATISTICS: ******" << endl << endl;
	out << "Total Number of Students in Class: " << count << endl << endl;
	out << "The Class Average for Exam 1 is: " << calculateClassAvgExam1(student, count) << endl << endl;
	out << "The Class Average for Exam 2 is: " << calculateClassAvgExam2(student, count) << endl << endl;	
	out << "The Class Average for Exam 3 is: " << calculateClassAvgExam3(student, count) << endl << endl;
	out << acount << " students finished the class with an A. That's " << (double(acount) / count) * 100 << "% of the class." << endl << endl;
	out << bcount << " students finished the class with a B. That's " << (double(bcount) / count) * 100 << "% of the class." << endl << endl;
	out << ccount << " students finished the class with a C. That's " << (double(ccount) / count) * 100 << "% of the class." << endl << endl;
	out << dcount << " students finished the class with a D. That's " << (double(dcount) / count) * 100 << "% of the class." << endl << endl;
	out << fcount << " students finished the class with an F. That's " << (double(fcount) / count) * 100 << "% of the class." << endl << endl;
	out << "The Class' Final Average: " << calculateFinalAverage(student, count) << endl << endl;
	out << student[highIndex].fname + " " + student[highIndex].lname + " (" << student[highIndex].studentID << ") had the highest final average of " << student[highIndex].examAvg << endl << endl;
	out << student[lowIndex].fname + " " + student[lowIndex].lname + " (" << student[lowIndex].studentID << ") had the lowest final average of " << student[lowIndex].examAvg << endl << endl;

}

double calculateFinalAverage(Student student[], int count) {

	double gradeTotals = 0;

	for (int i = 0; i < count; i++) {

		gradeTotals += student[i].examAvg;

	}

	return (gradeTotals / count);

}

double calculateClassAvgExam1(Student student[], int count) {

	int total = 0;

	for (int i = 0; i < count; i++) {

		total += student[i].exam1;

	}

	return (total / double(count));

}

double calculateClassAvgExam2(Student student[], int count) {

	int total = 0;

	for (int i = 0; i < count; i++) {

		total += student[i].exam2;

	}

	return (total / double(count));

}

double calculateClassAvgExam3(Student student[], int count) {

	int total = 0;

	for (int i = 0; i < count; i++) {

		total += student[i].exam3;

	}

	return (total / double(count));

}

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