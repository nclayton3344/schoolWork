//C Young printing current DATE and TIME 

#include <iostream>
#include <ctime>

using namespace std;

int main(){



	cout << time(NULL) << endl;  //Large number representing seconds since Jan 1, 1970

	
          char dateStr [9];  //C-string
          char timeStr [9];  //
          _strdate_s( dateStr);
         cout << "The current date is  " << dateStr << endl;
         _strtime_s( timeStr );
         cout <<  "The current time is   "<<  timeStr<< endl << endl;
 
		 cout << __TIMESTAMP__ << endl;  //Or, you can use this pre-defined constant like this


	return 0;
}


/*Output example:
1411592860
The current date is  08/24/16
The current time is   16:07:40

Wed Aug 24 16:07:35 2016
Press any key to continue . . .
*/
