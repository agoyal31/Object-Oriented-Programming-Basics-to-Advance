/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:11/11/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper : public VehicleBasic {

		double m_maxCargoWeight;//in kilograms(percision2)
		double m_currentCargoWeight;
	public:
		Dumper(const char* plateNumber, int vehicleBuiltYear, double maxCargoWeight, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& coutRef, Dumper& right);
	std::istream& operator>>(std::istream& cinRef, Dumper& right);
}
#endif

