#ifndef _SDDS_RECTANGLE_H
#define _SDDS_RECTANGLE_H
#include "LblShape.h"
#include<iostream>
namespace sdds
{
	class Rectangle : public LblShape 
	{
		int m_width{};
		int m_height{};
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& cinRef);
		void draw(std::ostream& coutRef)const;

	};
}
#endif
