/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in):Car(in) //the Racecar constructor initializes the Car part of the Racecar object by 
		                                       //invoking the Car constructor with the provided input stream. It then reads a 
		                                       //line from the input stream, removes the first character, converts the 
		                                       //remaining string into a double, and assigns it to the m_booster member variable of the Racecar object.
	{

		string tempBonusString;
		getline(in, tempBonusString, '\n');
		tempBonusString.erase(0, 1);
		m_booster = stod(tempBonusString);
	}
	void Racecar::display(std::ostream& out) const //the display function in the Racecar class calls the display function of 
		                                           //the Car base class to output information about the Car part of the Racecar
		                                           //object. It then adds an asterisk to the output stream to represent a 
		                                           //specific aspect of the Racecar object.
	{
		this->Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const //the topSpeed function in the Racecar class calculates the top speed of a Racecar object 
		                             //by considering the booster factor and the top speed of the Car part of the object. 
		// It incorporates the additional speed provided by the booster and the base speed of the Car to determine the overall top speed of the Racecar
	{
		return  (this->m_booster * this->Car::topSpeed()) + this->Car::topSpeed();
	}
}