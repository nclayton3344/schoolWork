//******************************************************************
// Starship program
// This program computes the total weight and center of gravity
// of a Beechcraft Starship-1, given the number of crew members
// and passengers, weight of closet and baggage compartment cargo,
// and gallons of fuel loaded.  It assumes that each person
// weighs 170 pounds, and that the fuel weighs 6.7 pounds per
// gallon.  Thus, the output is approximate and should be hand-
// checked if the Starship is loaded near its limits
//******************************************************************
#include <iostream>
#include <iomanip>    // For setw() and setprecision()

using namespace std;

const float PERSON_WT = 170.0;          // Average person weighs
                                        //   170 lbs.
const float LBS_PER_GAL = 6.7;          // Jet-A weighs 6.7 lbs.
                                        //   per gal.
const float EMPTY_WEIGHT = 9887.0;      // Standard empty weight
const float EMPTY_MOMENT = 3153953.0;   // Standard empty moment

float CargoMoment( int, int );
float CrewMoment( int );
float FuelMoment( int );
void  GetData( int&, int&, int&, int&, int& );
float PassengerMoment( int );
void  PrintWarning();

int main()
{
    int   crew;            // Number of crew on board (1 or 2)
    int   passengers;      // Number of passengers (0 through 8)
    int   closet;          // Weight in closet (160 lbs. maximum)
    int   baggage;         // Weight of baggage (525 lbs. max.)
    int   fuel;            // Gallons of fuel (10 through 565 gals.)
    float totalWt;         // Total weight of the loaded Starship
    float centerOfGravity; // Center of gravity of loaded Starship

    cout << fixed << showpoint                // Set up floating pt.
         << setprecision(2);                  //   output format

    GetData(crew, passengers, closet, baggage, fuel);

    totalWt = EMPTY_WEIGHT + float(passengers + crew) * PERSON_WT +
			float(baggage + closet) + float(fuel) * LBS_PER_GAL;
    centerOfGravity = (CrewMoment(crew) + PassengerMoment(passengers) +
			CargoMoment(closet, baggage) + FuelMoment(fuel) +
			EMPTY_MOMENT) / totalWt;

    cout << "Total weight is " << totalWt << " pounds." << endl;
    cout << "Center of gravity is " << centerOfGravity
         << " inches from the front of the plane." << endl;
    PrintWarning();
    return 0;
}

//******************************************************************
// Prompts for the input of crew, passengers, closet, baggage, and
// fuel values and returns the five values after echo printing them
void GetData(   int& crew,int& passengers,int& closet,int& baggage,int& fuel) 
{
    cout << "Enter the number of crew members." << endl;
    cin >> crew;
    cout << "Enter the number of passengers." << endl;
    cin >> passengers;
    cout << "Enter the weight, in pounds, of cargo in the" << endl
         << " closet, rounded up to the nearest whole number."
         << endl;
    cin >> closet;
    cout << "Enter the weight, in pounds, of cargo in the" << endl
         << " aft baggage compartment, rounded up to the" << endl
         << " nearest whole number." << endl;
    cin >> baggage;
    cout << "Enter the number of U.S. gallons of fuel" << endl
         << " loaded, rounded up to the nearest whole number."
         << endl;
    cin >> fuel;
    cout << endl;
    cout << "Starship loading data as entered:" << endl
         << "   Crew:          " << setw(6) << crew << endl
         << "   Passengers:    " << setw(6) << passengers << endl
         << "   Closet weight: " << setw(6) << closet << " pounds"
         << endl
         << "   Baggage weight:" << setw(6) << baggage << " pounds"
         << endl
         << "   Fuel:          " << setw(6) << fuel << " gallons"
         << endl << endl;
}

//******************************************************************
// Computes the crew moment arm in inch-pounds from the number of
// crew members.  Global constant PERSON_WT is used as the weight
// of each crew member
float CrewMoment( int crew )   
{
    const float CREW_DISTANCE = 143.0;  // Distance to crew seats from front

    return float(crew) * PERSON_WT * CREW_DISTANCE;
}

//******************************************************************
// Computes the passenger moment arm in inch-pounds from the number
// of passengers.  Global constant PERSON_WT is used as the weight
// of each passenger.  It is assumed that the first two passengers
// sit in row 2, the second two in row 1, the next two in row 3,
// and remaining passengers sit in row 4
float PassengerMoment( int passengers )  
{
    const float ROW1_DIST = 219.0;  // Distance to row 1 seats
                                    //   from front
    const float ROW2_DIST = 265.0;  // Distance to row 2 seats
    const float ROW3_DIST = 295.0;  // Distance to row 3 seats
    const float ROW4_DIST = 341.0;  // Distance to row 4 seats

    float moment = 0.0;             // Running total of moment as
                                    //   rows are added

    if (passengers > 6)                    // For passengers 7 and 8
    {
        moment = moment +
                 float(passengers - 6) * PERSON_WT * ROW4_DIST;
        passengers = 6;                    // 6 remain
    }
    if (passengers > 4)                    // For passengers 5 and 6
    {
        moment = moment +
                 float(passengers - 4) * PERSON_WT * ROW3_DIST;
        passengers = 4;                    // 4 remain
    }
    if (passengers > 2)                    // For passengers 3 and 4
    {
        moment = moment +
                 float(passengers - 2) * PERSON_WT * ROW1_DIST;
        passengers = 2;                    // 2 remain
    }
    if (passengers > 0)                    // For passengers 1 and 2
        moment = moment +
                 float(passengers) * PERSON_WT * ROW2_DIST;
    return moment;
}




//******************************************************************
// Computes the total moment arm for cargo loaded into the
// front closet and aft baggage compartment
float CargoMoment(  int closet,     // Weight in closet
                    int baggage )   // Weight of baggage
{
    const float CLOSET_DIST = 182.0;    // Distance from front
                                        //   to closet
    const float BAGGAGE_DIST = 386.0;   // Distance from front
                                        //   to bagg. comp.

    return float(closet) * CLOSET_DIST + float(baggage) * BAGGAGE_DIST;
}

//******************************************************************
// Computes the moment arm for fuel on board.  There are four
// different formulas for this calculation, depending on
// the amount of fuel, due to fuel tank layout.
// This function uses the global constant LBS_PER_GAL
// to compute the weight of the fuel
float FuelMoment(  int fuel )    // Fuel in gallons
{
    float fuelWt;           // Weight of fuel in pounds
    float fuelDistance;     // Distance from front of plane

    fuelWt = float(fuel) * LBS_PER_GAL;
    if (fuel < 60)
        fuelDistance = float(fuel) * 314.6;
    else if (fuel < 361)
        fuelDistance = 305.8 + (-0.01233 * float(fuel - 60));
    else if (fuel < 521)
        fuelDistance = 303.0 + ( 0.12500 * float(fuel - 361));
    else
        fuelDistance = 323.0 + (-0.04444 * float(fuel - 521));
    return fuelDistance * fuelWt;
}

//******************************************************************
// Warns the user of assumptions made by the program
// and when to double check the program's results
void PrintWarning()
{
    cout << endl
         << "Notice:  This program assumes that passengers" << endl
         << "  fill the seat rows in order 2, 1, 3, 4, and" << endl
         << "  that each passenger and crew member weighs "
         << PERSON_WT << " pounds." << endl
         << "  It also assumes that Jet-A fuel weighs "
         << LBS_PER_GAL << " pounds" << endl
         << "  per U.S. gallon.  The center of gravity" << endl
         << "  calculations for fuel are approximate.  If" << endl
         << "  the aircraft is loaded near its limits, the" << endl
         << "  pilot's operating handbook should be used" << endl
         << "  to compute weight and center of gravity" << endl
         << "  with more accuracy." << endl;
}
