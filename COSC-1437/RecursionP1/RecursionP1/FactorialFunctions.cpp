#include "Factorial.h"
using namespace std;

template<class T>
Factorial<T>::Factorial(){
	recursive = 0;
	iterative = 0;
}

template<class T>
Factorial<T>::Factorial(T num){
	recursive = iterativeFactorial(num);
	iterative = recursiveFactorial(num);
}

template<class T>
void Factorial<T>::assign(T num){
	recursive = iterativeFactorial(num);
	iterative = recursiveFactorial(num);
}

template<class T>
T Factorial<T>::getIterativeFactorial(){
	return iterative;	
}

template<class T>
T Factorial<T>::getRecursiveFactorial(){
	return recursive;
}

template<class T>
T Factorial<T>::iterativeFactorial(T num){
	T factorial = 1;

	for (num; num > 0; num--) {

		factorial *= num;

	}
	

	return factorial;
}

template<class T>
T Factorial<T>::recursiveFactorial(T num){
	return num;
}


