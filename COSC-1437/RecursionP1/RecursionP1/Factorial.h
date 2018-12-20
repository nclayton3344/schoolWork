#include <iostream>
#include <string>
using namespace std;

template <class T>
class Factorial {

public:
	Factorial();
	Factorial(T);
	void assign(T);
	T getIterativeFactorial();
	T getRecursiveFactorial();

private:
	T iterativeFactorial(T);
	T recursiveFactorial(T);
	T recursive, iterative;


};