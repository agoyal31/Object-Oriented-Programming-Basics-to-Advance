/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H
#include <iostream>
#include <string>
namespace sdds{
	class Movie {
		std::string m_title{};
		int m_movieReleaseYear{};
		std::string m_movieDescription{};
	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& coutRef, const Movie& obj);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(this->m_title);
			spellChecker(this->m_movieDescription);
		}

	};
 }


#endif