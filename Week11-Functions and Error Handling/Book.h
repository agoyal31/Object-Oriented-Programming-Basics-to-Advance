/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
namespace sdds {
	class Book {
		std::string m_bookAuthorName{};
		std::string m_bookTitle{};
		std::string m_bookCountryPublication{};
		int m_bookYearPublication{};
		double m_bookPrice{};
		std::string m_bookDescription{};
	public:
		Book() = default;
		const std::string& title() const; // returns book tiitle
		const std::string& country() const; //returns country in which book was published
		const size_t& year() const; //returns book publish year
		double& price(); //returns book price
		Book(const std::string& strBook); // class constructor
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		friend std::ostream& operator<<(std::ostream& coutRef, const Book& obj);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(this->m_bookDescription);
		}
	};
}
#endif
