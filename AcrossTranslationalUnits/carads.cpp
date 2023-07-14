/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/05/21
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "carads.h"
#include <string>
#include <cstring>
#include "iomanip"
using namespace std;

double g_taxrate;
double g_discount;

namespace sdds
{
	void listArgs(int argc, char** argv)
	{
		cout << "Command Line:" << endl << "--------------------------" << endl;
		for (int i = 0; i < argc; i++) {
			cout <<"  "<< i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------" << endl;
		cout << endl;

	}

	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}

	Cars::Cars(const Cars& c)
	{
		*this = c;
	}

	Cars& Cars::operator=(const Cars& c)
	{
		if (this != &c)
		{
			if (c.m_manufactureYear) {
				// shallow copy
				m_carDiscount = c.m_carDiscount;
				strcpy(m_carModel, c.m_carModel);
				m_carPrice = c.m_carPrice;
				m_carStatus = c.m_carStatus;
				m_carDiscount = c.m_carDiscount;
				m_isCarDiscount = c.m_isCarDiscount;
				m_manufactureYear = c.m_manufactureYear;
				//deep copy (carBrand)
				//DMA
				m_carBrand = new char[strlen(c.m_carBrand) + 1];
				strcpy(m_carBrand, c.m_carBrand);
				//DMA
			}

		}
		return *this;
	}

	Cars::~Cars()
	{
		if (m_carBrand && m_carBrand[0]) {
			delete[] m_carBrand;
		}
	}

	void Cars::read(std::istream& is)
	{
		
		if (is) {

			is.get(m_carStatus);
			is.ignore(1);

			string str;
			getline(is, str, ',');

			//
			//DMA DMA DMA
			//

			m_carBrand = new char[str.length() + 1];

			//
			//DMA DMA DMA
			//

			strcpy(m_carBrand, str.c_str());

			//delete it here
			//delete[] m_carBrand;
			//cannot display it(current car or cars on record) if delete


			//is.getline(m_carBrand, 10, ',');
			is.getline(m_carModel, 15, ',');
			is >> m_manufactureYear;
			is.ignore(1);
			is >> m_carPrice;
			is.ignore(1);
			is.get(m_isCarDiscount);
			if (this->m_isCarDiscount == 'Y') {
				m_carDiscount = true;
			}
			else {
				m_carDiscount = false;
			}
			is.ignore(1000, '\n');

			//<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
		}
	}

	void Cars::display(bool reset)
	{
		static int counter = 1;
		if (reset == true) 
		{
			counter = 1;
		};
		double price = (m_carPrice + (m_carPrice * g_taxrate));
		if (this->m_carBrand) 
		{
			cout.setf(ios::left);
			cout.width(2);
			cout << counter++ << ". ";
			cout.width(10);
			cout << m_carBrand;
            delete[] m_carBrand;
			m_carBrand = nullptr;
			cout << "| ";
			cout.width(15);
			cout << m_carModel;
			cout << "| ";
			cout.width(4);
			cout << m_manufactureYear << " |";
			cout.setf(ios::right);
			cout.width(12);
			cout << fixed;
			cout<<setprecision(2);
			cout << price <<"|";

			if (m_carDiscount) 
			{
				cout.width(12);
				cout.setf(ios::right);
				cout << (price - (price * g_discount));
			}
			cout.unsetf(ios::right);

			cout << endl;

		}
		else {
			cout << "COUNTER No Car";
		}
	}

	char Cars::getStatus()
	{
		return m_carStatus;
	}

	Cars::operator bool() const
	{
		if (this->m_carStatus == 'N') {
			return true;
		}
		else {
			return false;
		}
	}
	// return (this->m_carStatus == 'N');
}


