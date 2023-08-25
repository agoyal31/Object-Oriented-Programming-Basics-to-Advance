/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include"Movie.h"
#include <functional>
#include <iomanip>
#include <fstream>

using namespace std;
namespace sdds {
	const string& Movie::title() const
	{
		return m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		size_t startPosition{};
		size_t lastPosition{};
		string tempStringStorage;

		//TITLE,YEAR,DESCRIPTION

		lastPosition = strMovie.find(',', startPosition);
		m_title = strMovie.substr(startPosition, (lastPosition - startPosition));
		m_title.erase(m_title.begin(), find_if(m_title.begin(), m_title.end(), bind1st(not_equal_to<char>(), ' ')));
		m_title.erase(std::find_if(m_title.rbegin(), m_title.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_title.end());

		startPosition = lastPosition + 1;
		lastPosition = strMovie.find(',', startPosition);
		tempStringStorage = strMovie.substr(startPosition, (lastPosition - startPosition));
		m_movieReleaseYear = stoi(tempStringStorage);

		startPosition = lastPosition + 1;
		lastPosition = strMovie.find('\n', startPosition);
		m_movieDescription = strMovie.substr(startPosition, (lastPosition - startPosition));
		m_movieDescription.erase(m_movieDescription.begin(), find_if(m_movieDescription.begin(), m_movieDescription.end(), bind1st(not_equal_to<char>(), ' ')));
		m_movieDescription.erase(std::find_if(m_movieDescription.rbegin(), m_movieDescription.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_movieDescription.end());
	
	}
	ostream& operator<<(ostream& coutRef, const Movie& obj)
	{
		//TITLE | YEAR | DESCRIPTION
		//	the title printed on a field of size 40;
		//the year printed on a field of size 4;
		coutRef.width(40);
		coutRef.setf(ios::right);
		coutRef << obj.title() << " | ";
		coutRef.unsetf(ios::right);
		coutRef.width(4);
		coutRef.setf(ios::right);
		coutRef << obj.m_movieReleaseYear << " | ";
		coutRef.unsetf(ios::right);
		coutRef << obj.m_movieDescription << endl;
		return coutRef;
	}
}