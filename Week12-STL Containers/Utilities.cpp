/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"Utilities.h"
#include <functional>
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) //'in' is basically an object of file, that read a record from file(not full record but read a record till comma)
		                                      //which is basically a token extracted named 'tempTagStorage' and based on that string token a new vehicle(car or raceCar) is created
		                                      //if token is 'c or C' -> new Car is made and if string is 'R or r' -> new Racecar is made
		                                      //if token extracted is not c/C/R/r -> error is thrown -> "throw ("Unrecognized record type: [" + tempTagStorage + "]")"
	{
		string tempTagStorage;
		getline(in, tempTagStorage, ',');

		if (!tempTagStorage.empty()) {

			tempTagStorage.erase(tempTagStorage.begin(), find_if(tempTagStorage.begin(), tempTagStorage.end(), bind1st(not_equal_to<char>(), ' ')));
			tempTagStorage.erase(std::find_if(tempTagStorage.rbegin(), tempTagStorage.rend(), bind1st(not_equal_to<char>(), ' ')).base(), tempTagStorage.end());
			if (tempTagStorage == "c" || tempTagStorage == "C") {

				Vehicle* theVehicle = new Car(in); //sets the Vehicle* (theVehicle) to hold the new car(calls the one argument constructor of class Car)
				in.ignore(1000, '\n');
				return theVehicle; // returns the newly created Car object pointer to createInstance function
			}
			else if (tempTagStorage == "r" || tempTagStorage == "R") {
				Vehicle* theVehicle = new Racecar(in); //pass the rest of record() to the Car one argument constructor
				return theVehicle; // returns the newly created Racecar object pointer to createInstance function
			}
			else if (tempTagStorage != "c" && tempTagStorage != "C" && tempTagStorage != "r" && tempTagStorage != "R") {
				in.ignore(10000, '\n');
				throw ("Unrecognized record type: [" + tempTagStorage + "]");
			}
		}
		return nullptr;
		
	}
}