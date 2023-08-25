/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
#include <string>

namespace sdds
{
	class Car : public Vehicle //Car class inherited from base class Vehicle
	{
	private:
		std::string m_carMakerCompany{}; // holds the 
		std::string m_carCondition{}; // holds the car condition (new, broken or used)
		double m_maxCarSpeed{}; // holds the car speed
	public:
		Car() = default; // default constructor
		Car(std::istream& cinRef); // one argument constructor taking argument as cinRef which is basically treated as file object in this case
		std::string condition() const; // returns the condition of car (m_carCondition)
		double topSpeed() const; // returns the speed of car(m_maxCarSpeed)
		void display(std::ostream& out) const;// displays the extracted string tokens(m_carMakerCompany, m_carCondition, m_maxCarSpeed) from the file on the console
	};
}
#endif