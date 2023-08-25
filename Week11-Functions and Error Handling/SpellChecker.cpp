/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "SpellChecker.h"
#include <functional>
#include <iomanip>
#include <fstream>
using namespace std;
namespace sdds {

	SpellChecker::SpellChecker(const char* filename)
	{
		m_counter = 0;
		std::ifstream fptr(filename);
		if (!fptr) {
			throw "Bad file name!";
		}
		else { //(fptr.is_open())
			 do{
				size_t startPosition{};
				size_t lastPosition{};
				std::string tempStringStore;
				std::getline(fptr, tempStringStore);
				if (tempStringStore.length() > 1) {
					lastPosition = tempStringStore.find(' ', startPosition);
					m_badWords[m_counter] = tempStringStore.substr(startPosition, lastPosition);
					m_badWords[m_counter].erase(m_badWords[m_counter].begin(), find_if(m_badWords[m_counter].begin(), m_badWords[m_counter].end(), bind1st(not_equal_to<char>(), ' ')));
					m_badWords[m_counter].erase(std::find_if(m_badWords[m_counter].rbegin(), m_badWords[m_counter].rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_badWords[m_counter].end());

					startPosition = lastPosition + 1;
					lastPosition = tempStringStore.find('\n', startPosition);
					m_goodWords[m_counter] = tempStringStore.substr(startPosition, lastPosition);
					m_goodWords[m_counter].erase(m_goodWords[m_counter].begin(), find_if(m_goodWords[m_counter].begin(), m_goodWords[m_counter].end(), bind1st(not_equal_to<char>(), ' ')));
					m_goodWords[m_counter].erase(std::find_if(m_goodWords[m_counter].rbegin(), m_goodWords[m_counter].rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_goodWords[m_counter].end());
					m_counter++;
				}
			} while (!fptr.eof() && m_counter < 6);
		}
	}
	void SpellChecker::operator()(std::string& text)
	{

		for (int i = 0; i < m_counter; ++i) 
		{
			size_t startPosition{};
			size_t lastPosition{};
			do 
			{
				lastPosition = text.find(m_badWords[i], startPosition);
				if (lastPosition != std::string::npos) 
				{
					text.replace(lastPosition, m_badWords[i].length(), m_goodWords[i]);
					++numOfTimesBadWordCorrected[i];
				}

			} while (lastPosition++ != std::string::npos);
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		cout << "Spellchecker Statistics" << endl;

		for (int i = 0; i < m_counter; ++i) {
			out.width(15);
			out << m_badWords[i] << ": ";
			out << numOfTimesBadWordCorrected[i] << " ";
			out << "replacements" << endl;
		}
	}
}