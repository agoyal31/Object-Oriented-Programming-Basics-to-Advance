/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/05/21
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_CARADS_H
#define _SDDS_CARADS_H
#include<iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	void listArgs(int argc, char** argv);
	class Cars {
		char* m_carBrand{};
		char m_carModel[15]{};
		int m_manufactureYear{};
		double m_carPrice{};
		char m_carStatus{};
		bool m_carDiscount{};
		char m_isCarDiscount{};
	public:
		Cars() = default;
		Cars(const Cars& c); //cc
		Cars& operator=(const Cars& c); // ca
		virtual ~Cars(); //destructor
		void read(std::istream& is);
		void display(bool reset);
		char getStatus();
		operator bool()const;

	};

	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}

#endif // !
