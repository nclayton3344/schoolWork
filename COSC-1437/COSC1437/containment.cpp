#include <iostream>
#include <string>
using namespace std;

//Note: All code is given in one file, but could be separated into include files,
//      class implementation files, and main.

class DateType {
public:
	void Initialize(int,int,int);
	void Print();
private:
	int year;
	int month;
	int day;
};

class StudentType{
public:
	void Initialize (string,int,int,int);
	void Print();
private:
	string name;
	DateType birthday;
};

int main(){
	StudentType stu;
	stu.Initialize("Stewart Min", 10, 7, 1985);
	stu.Print();
	return 0;
}

void DateType::Initialize(int y,int m,int d){
	year = y;
	month = m;
	day = d;
}

void DateType::Print(){
	cout<<" "<<month<<" / "<<day<<" / "<<year<<" "<<endl;
}

void StudentType::Initialize (string nm,int m,int d ,int y){

	name = nm;
	birthday.Initialize(y,m,d);
}

void StudentType::Print(){
	cout<<"Student's name is: "<<name<<endl;
	birthday.Print();
	cout<<endl;
}


