#ifndef _SDDS_SHAPE_H
#define _SDDS_SHAPE_H
#include<iostream>

namespace sdds
{
	class Shape 
	{
	public:
		virtual void draw(std::ostream& coutRef)const = 0;
		virtual void getSpecs(std::istream & cinRef) = 0;
		virtual ~Shape();
	};
	std::ostream& operator<<(std::ostream& coutRef, const Shape& A);
	void operator>>(std::istream& cinRef, Shape& B);

}
#endif
