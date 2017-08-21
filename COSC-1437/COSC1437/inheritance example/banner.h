#ifndef BANNER
#define BANNER
//#include <string>
//using namespace std;


class BaseBanner{
public:
	BaseBanner();
	void set(int);
	virtual void print();  //virtual function in the base class
	int getvalue();
	void greeting();
private:
	int value;
protected:
	int protect;
};

class DeriveBanner : public BaseBanner {      //DeriveBanner class inherits from BaseBanner
public:
	DeriveBanner();
	void set(int,string);  //redefines base class function set
	void print();   //overrides and redefines base class function print
private:
	string label;
};






#endif
