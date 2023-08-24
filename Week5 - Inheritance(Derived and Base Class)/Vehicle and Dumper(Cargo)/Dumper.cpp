/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:11/11/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{
	Dumper::Dumper(const char* plateNumber, int vehicleBuiltYear, double maxCargoWeight, const char* address):
		VehicleBasic(plateNumber,vehicleBuiltYear), m_currentCargoWeight {0}
	{
		VehicleBasic::NewAddress(address);
		m_maxCargoWeight = maxCargoWeight;
	}

	bool Dumper::loaddCargo(double cargo)
	{
	 double new_currentCargoWeight = cargo + m_currentCargoWeight;
		if (new_currentCargoWeight <= m_maxCargoWeight) {
			m_currentCargoWeight = new_currentCargoWeight;
		}
		
		bool temp;
		if (m_currentCargoWeight == new_currentCargoWeight) {
			temp = true;
		}
		else  {
			temp = false;
		}
		return temp;
	}
	bool Dumper::unloadCargo()
	{
		double previousCargo = m_currentCargoWeight;
		m_currentCargoWeight = 0;
		return m_currentCargoWeight != previousCargo;

	}
	istream& Dumper::read(istream& in) {
		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> m_maxCargoWeight;
		cout << "Cargo: ";
		in >> m_currentCargoWeight;

		return in;
	}
	ostream& Dumper::write(ostream& os)
	{
		VehicleBasic::write(os) << " | " << m_currentCargoWeight << '/' << m_maxCargoWeight;
		return os;
	}

	ostream& operator<<(ostream& coutRef, Dumper& right)
	{
		return right.write(coutRef);
	}

	istream& operator>>(istream& cinRef, Dumper& right)
	{
		return right.read(cinRef);
	}


}

	