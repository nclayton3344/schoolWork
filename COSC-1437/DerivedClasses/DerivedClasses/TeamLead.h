//Nathan Clayton
//Class Inheritance Project
//10/30/17
#ifndef TL
#define TL
#include "ProductionWorker.h"
#include <fstream>
using namespace std;

//Class Definition
class TeamLead : public ProductionWorker {

	static int const requiredTraining = 20;

public:
	//Constructors
	TeamLead();
	TeamLead(double, int, int, double, string, int, string);
	//Mutators
	void assignTeamLead(double, int, int, double, string, int, string);

	//Accessors
	double getLeadBonus();
	int getTrainingHours();
	void print(ofstream &);


private:
	double leadBonus;
	int trainingHours;

};
#endif