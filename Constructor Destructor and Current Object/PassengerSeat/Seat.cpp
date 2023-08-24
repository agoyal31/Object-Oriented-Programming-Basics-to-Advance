/*I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  17-11-2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <string.h>
#include <iomanip>

namespace sdds {

	bool Seat::validate(int row, char letter) const
	{
		bool temp = false;

		if ((row >= 1 && row <= 4) || (row >= 7 && row <= 15) || (row >= 20 && row <= 38)) {
			if ((row >= 1 && row <= 4) && (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')) {
				temp = true;
			}
			else if (((row >= 7 && row <= 15) || (row >= 20 && row <= 38)) && (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')) {
				temp = true;
			}
		}
		return temp;
	}


	Seat& Seat::alAndCp(const char* str)
	{
		reset(); // check this!!!!!
		m_name = nullptr;

		if (str && str[0]) {
			m_name = new char[strlen(str) + 1];
			strcpy(m_name, str);
		}
		return *this;
	}
	//Seat& Seat::alAndCp(const char* str)// AFTERWARDS try with reset simply 
	//{
	// m_name = nullptr;
	// if (str && str[0]) {
	// m_name = new char[strlen(str) + 1];
	// strcpy(m_name, str);
	// return *this;
	// }
	// return *this;
	//}

	Seat& Seat::reset()
	{
		if (m_name && m_name[0])
		{
			delete[] m_name;
		}
		m_name = nullptr;

		m_rowNum = 0;
		m_letterNum = 0;
		return *this;
	}

	bool Seat::isEmpty() const
	{
		return m_name == nullptr;
	}

	bool Seat::assigned() const
	{
		return validate(m_rowNum, m_letterNum);
	}

	Seat::Seat()
	{
		reset();
	}

	Seat::Seat(const char* passengerm_name) : m_rowNum{ 0 }, m_letterNum{ 0 }
	{
		alAndCp(passengerm_name);
	}

	Seat::Seat(const char* passengerm_name, int row, char letter)
	{
		alAndCp(passengerm_name);
		set(row, letter);
	}

	Seat& Seat::set(int row, char letter)
	{
		if (validate(row, letter)) {
			m_rowNum = row;
			m_letterNum = letter;
		}
		else {
			m_rowNum = 0;
			m_letterNum = 0;
		}
		return *this;
	}

	int Seat::row() const
	{
		return m_rowNum;
	}

	char Seat::letter() const
	{
		return m_letterNum;
	}

	const char* Seat::passenger() const
	{
		return m_name;
	}

	std::ostream& Seat::display(std::ostream& coutRef) const
	{
		/*char temp_passengername [40 + 1];
		if (m_name && m_name[0]) {
			strcpy(temp_passengername, m_name);
		}*/

		
		

		if(m_name) {
			coutRef.width(40);
			coutRef.setf(std::ios::left);

			coutRef.fill('.');

			
	
			if (strlen(m_name) > 40)
			{
				coutRef << "Hubert Blaine Wolfeschlegelsteinhausenbe";
			}
			else {
				coutRef << m_name;
			}

			coutRef.unsetf(std::ios::left);




			coutRef << ' ';
			if (m_rowNum != 0) {
				coutRef << m_rowNum << m_letterNum;
			}
			else {
				coutRef << "___";
			}
		}
		else {
			coutRef << "Invalid Seat!";
		}
		return coutRef;
	}

	std::istream& Seat::read(std::istream& cinRef)
	{
		reset();

		char tcstr[70 + 1];
		int trow;
		char tletter;

		cinRef.getline(tcstr, 70,',');
		//cinRef.ignore(1, ',');// not working because something is there in buffer at back
		cinRef >> trow >> tletter;
		cinRef.ignore(10000, '\n');

		if (cinRef) {
			alAndCp(tcstr);
			if (m_name && m_name[0]) {
				set(trow, tletter);
			}
		}
		return cinRef;
	}

	Seat::~Seat()
	{
		delete[] m_name;
		m_name = nullptr;
	}

}
