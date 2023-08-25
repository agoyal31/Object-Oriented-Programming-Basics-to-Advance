/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
#include <string>

namespace sdds
{
	class Racecar : public Car //Racecar class is inherited from the base class Car
	{
	private:
		double m_booster{}; // holds the booster effects of a Racecar
	public:
		Racecar(std::istream& in); // reads input from the cinRef istream object to initialize the member variables of the Racecar object
		void display(std::ostream& out) const; // displays the extracted tokens of a Racecar record to console by calling the display function of Car
		                                       // but by sending the object of Racecar
		                                       // since the Racecar is inherited from the base class Car(so it can access the member functions of Car and send its own(Racecar) object)
		double topSpeed() const; // returns the topSpeed() of Racecar
	};
}
#endif
