/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_SPELLCHECKER_H
#define _SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace sdds {
	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];
		int numOfTimesBadWordCorrected[6] = {};
		int m_counter{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
  }


#endif