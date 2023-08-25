/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/04
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include"Dictionary.h"

using namespace std;

namespace sdds {

	ostream& operator<<(ostream& out, const Dictionary& dictionary)
	{
		out.width(20);
		out.setf(ios::right);
		out << dictionary.getTerm();
		out.unsetf(ios::right);
		out << ':' << ' ';
		out << dictionary.getDefinition();

		return out;
	}

	bool Dictionary::operator==(const Dictionary& dict) const
	{
		if (this->getTerm() == dict.getTerm()) {
			return true;
		}
		return false;
	}

}