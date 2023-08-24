#include "Shape.h"
#include <iostream>
using namespace std;
namespace sdds 
{
	
	Shape::~Shape()
	{

	}

	ostream& operator<<(ostream& coutRef, const Shape& A)
	{  
		 A.draw(coutRef);
		 return coutRef;
	
	}
	void operator>>(istream& cinRef, Shape& B)
	{
		B.getSpecs(cinRef);
	
	}
}
