#ifndef _SDDS_LINE_H
#define _SDDS_LINE_H
#include "LblShape.h"
#include<iostream>
namespace sdds
{
	class Line :public LblShape 
	{
	private:
		int m_length;
	public:
		Line();

		Line(const char* label, int length);
		void getSpecs(std::istream& cinRef);
		void draw(std::ostream& coutRef)const;
	};
}
#endif
