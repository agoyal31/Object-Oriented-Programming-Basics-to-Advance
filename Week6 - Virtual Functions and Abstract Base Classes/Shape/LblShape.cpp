#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include"Utils.h"
#include <iostream>
#include <string.h>
using namespace std;
namespace sdds 
{
    const char* LblShape::label()const 
	{
		return m_label;
	}

	LblShape::LblShape() {
		m_label = NULL;
	}

	LblShape::LblShape(const char* label) 
	{
		m_label = new char [ut.strlen(label)+1];
		if (label && label[0]) {
			m_label = new char[ut.strlen(label) + 1];
			ut.strcpy(m_label, label);
		}
	}
	LblShape::~LblShape() 
	{
		delete[] m_label;
	}
	void LblShape::getSpecs(istream& cinRef)
	{
		delete[] m_label;
		char cstr[200];
		cinRef.getline(cstr, 200, ','); //not cin ignore wused why????????????????
		m_label = new char[ut.strlen(cstr) + 1];
		ut.strcpy(m_label, cstr);
     }
}