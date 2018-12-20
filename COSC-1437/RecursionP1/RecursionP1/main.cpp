#include "Factorial.h"
#include <iostream>
using namespace std;

int main() {
	Factorial<int> fInt(5);
	Factorial<double> fDouble;

	cout << fInt.getIterativeFactorial() << endl;

	return 0;
}