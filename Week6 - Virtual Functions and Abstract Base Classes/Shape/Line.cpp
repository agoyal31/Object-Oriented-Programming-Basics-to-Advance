#include "Line.h"
#include <iostream>
using namespace std;
namespace sdds 
{
	Line::Line():LblShape()
	{
		m_length = 0;
	}
	Line::Line(const char* label, int length) : LblShape(label) 
	{
		m_length = length;
	}

	void Line::getSpecs(istream& cinRef)
	{
		LblShape::getSpecs(cinRef);
		cinRef >> m_length;
		cinRef.ignore(1000, '\n');

	}
	void Line::draw(ostream& coutRef) const
	{
		if (m_length > 0 && label() != NULL) //error
		{
			coutRef.width(m_length);
			coutRef.fill('=');
			coutRef.setf(std::ios::left);
			coutRef << label();
			coutRef.unsetf(std::ios::left);
		}
	}
}