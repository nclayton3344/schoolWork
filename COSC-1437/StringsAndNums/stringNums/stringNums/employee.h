#include <string>
using namespace std;
class Employee {

	public:
		Employee();
		Employee(string, double);
		string currencyNotation(double);
		string wordFormat(double);
		void printCheck(Employee);
		void assign(string, double);
		void printName();

	private:
		string employeeName;
		double payAmount;
		string curNot;
		string wordAmount;


};