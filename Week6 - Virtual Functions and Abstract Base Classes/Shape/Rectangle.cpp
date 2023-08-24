#include "Rectangle.h"
#include"Utils.h"
#include <iostream>
using namespace std;
namespace sdds {

	Rectangle::Rectangle():LblShape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label)
	{
		m_width = width;
	    m_height = height;
		if (m_height < 3 && m_width < ut.strlen(label) + 2)
		{
			m_width = 0;
			m_height = 0;
		}

	}
	void Rectangle::getSpecs(istream& cinRef) 
	{
		LblShape::getSpecs(cinRef);
		cinRef >> m_width;
		cinRef.ignore(1, ',');
		cinRef >> m_height;
		cinRef.ignore(1000, '\n');
		//cinRef >> (m_width);
	}
	void Rectangle::draw(ostream& coutRef) const
	{
		if (m_width != 0 && m_height != 0) 
		{
			coutRef << "+";
			coutRef.width(m_width - 2);
			coutRef.fill ('-');
			coutRef << "";
			coutRef << '+' << endl;
			coutRef << '|';
			coutRef.width(m_width - 2);
			coutRef.fill(' ');
			coutRef.setf(std::ios::left);
			coutRef << label();
			coutRef.unsetf(std::ios::left);
			
			coutRef << '|' << endl;
			for (int i = 0; i < m_height - 3; i++) 
			{
				coutRef << "|";
				coutRef.width(m_width - 2);
				coutRef.fill(' ');
				coutRef << "";
				coutRef << "|"<<endl;
			}
			coutRef << "+";
			coutRef.width(m_width - 2);
			coutRef.fill('-');
			coutRef << "";
			coutRef << "+";

		}
	}
}
