//C Young Oct 3, 2013
//example of using class inheritance

#include <iostream>
#include <string>
using namespace std;
#include "banner.h"

void display(BaseBanner & );

int main(){
	BaseBanner b1;
	DeriveBanner d1,d2;

	b1.set(100);
	display(b1);
	cout <<endl <<endl;

	d1.set(222,"Happy Birthday");
	display(d1);

	d2 = d1;
	cout << endl << "Printing the copied d2 object: " << endl;
	d2.print();

	return 0;
}

void display(BaseBanner &b){
	cout <<"display function: " << endl;
	b.print();

}