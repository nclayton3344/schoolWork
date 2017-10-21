#include <iostream>
#include <string>
using namespace std;
#include "banner.h"

BaseBanner::BaseBanner(){
	value = 0;
	protect = 0;
}

void BaseBanner::set(int s){
	value = s;
}
void BaseBanner::print(){
	cout << "**********************" << value <<
		"**********************" << endl;
}

int BaseBanner::getvalue(){
	return value;
}

void BaseBanner::greeting(){
	cout <<"//////////////////////Good Morning!//////////////////" << endl;
	cout <<"/////" << value << "/////////" << protect << "///////" << endl;
}

DeriveBanner::DeriveBanner() : BaseBanner() {   //calls base class constructor
	label = "NEW" ;
}

void DeriveBanner::set(int v,string s){ 
	BaseBanner::set(v);   //cannot directly access private element from base class!
	protect = v;
	label = s;
}

void DeriveBanner::print(){
	cout <<"===========================================================" << endl;
	BaseBanner::print();
	cout << "                       " << label << endl;
	cout << "protected value:       " << protect << endl;
	cout <<"===========================================================" << endl;
}
