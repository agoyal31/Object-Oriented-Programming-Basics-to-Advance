/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:11/11/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{

	VehicleBasic::VehicleBasic(const char* plateNumber, int vehicleBuiltYear) //:vehicleAddress{ Factory } {

	{	
		strcpy(m_vehicleAddress, "Factory");
		strcpy(m_plateNumber, plateNumber);
		m_vehicleBuiltYear = vehicleBuiltYear;
	}

	void VehicleBasic::NewAddress(const char* address)
	{
		int res = strcmp(m_vehicleAddress, address);
		if (res != 0)//for diff check
		{
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_plateNumber;
			cout.unsetf(ios::right);
			cout << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_vehicleAddress;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);
			cout << "|" << endl;

			strcpy(m_vehicleAddress, address);
		}
    }

	ostream& VehicleBasic::write(ostream& os)
	{
		os << "| " << m_vehicleBuiltYear << " | " << m_plateNumber << " | " << m_vehicleAddress;
		return os;
	}
	istream& VehicleBasic::read(istream& in)
	{
		cout << "Built year: ";
		in >> m_vehicleBuiltYear;
		cout << "License plate: ";
		in >> m_plateNumber;
		cout << "Current location: ";
		in >> m_vehicleAddress;
		return in;
	}

	ostream& operator<<(ostream& coutRef, VehicleBasic right)
	{
		return right.write(coutRef);
	}

	istream& operator>>(istream& cinRef, VehicleBasic& right)
	{
		return right.read(cinRef);
	}


}
