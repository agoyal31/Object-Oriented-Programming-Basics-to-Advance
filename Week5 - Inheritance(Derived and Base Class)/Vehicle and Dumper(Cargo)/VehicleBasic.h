/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:11/11/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	class VehicleBasic {
	private:
		char m_plateNumber[9 + 1]{};// array is a pointer
		char m_vehicleAddress[64 + 1]{};
		int m_vehicleBuiltYear;
	
	public:

		VehicleBasic(const char* plateNumber, int vehicleBuiltYear);//two argument constructor
		void NewAddress(const char* address);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& coutRef, VehicleBasic right);
	std::istream& operator>>(std::istream& cinRef, VehicleBasic& right);




}

#endif

