#ifndef _SDDS_LBLSHAPE_H
#define _SDDS_LBLSHAPE_H
#include "Shape.h"
#include<iostream>
using namespace std;
namespace sdds 
{
	class LblShape : public Shape 
	{//only getSpecs virtual method of base class used->remains abstract
	private:
		char* m_label;
	protected:
		const char* label()const;
    public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream& cinRef);
		/*void draw(ostream& coutRef);*/
    };

}
#endif
