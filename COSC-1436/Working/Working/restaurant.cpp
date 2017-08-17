// Nathan Clayton Section 2
// Restaurant Billing Program
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

int main() {
	cout << fixed << showpoint << setprecision(2);
	double meal, tax, tip, tiprate, beforetip, total, taxamt;
	string server = "Nathan";
	tax = 0.0825;
	tiprate = 0.15;
	cout << "What is the pre-tax cost of the meal? ";
	cin >> meal;
	taxamt = meal*tax;
	if (meal > 0.0) { // Calculates Bill as long as there is a cost
		beforetip = (meal * tax) + meal;
		tip = beforetip * tiprate;
		total = beforetip * tiprate + beforetip;
		cout << "McDougal's Burger Joint" << endl;
		cout << "-------------------------------" << endl;
		cout << "Server: " << setw(14) << server << endl;
		cout << '\n' << "Meal Charge: " << setw(9) << meal << endl;
		cout << "Tax Amount: " << setw(10) << taxamt << endl;
		cout << "Tip Amount: " << setw(10) << tip << endl;
		cout << "Total Bill: " << setw(10) << total << endl;
	}
	else {
		cout << "You didn't even eat!" << endl;
	}
}