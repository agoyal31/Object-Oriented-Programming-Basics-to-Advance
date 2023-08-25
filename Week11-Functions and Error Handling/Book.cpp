/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iterator>
#include"Book.h"
using namespace std;
namespace sdds {
	const std::string& Book::title() const
	{
		return m_bookTitle;
	}
	const std::string& Book::country() const
	{
		return m_bookCountryPublication;
	}

	const size_t& Book::year() const
	{
		return m_bookYearPublication;
	}

	double& Book::price()
	{
		return m_bookPrice;
	}

	Book::Book(const std::string& strBook)
	{
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		size_t startPosition{};
		size_t lastPosition;
		string tempStringStorage;

		lastPosition = strBook.find(',', startPosition);
		m_bookAuthorName = strBook.substr(startPosition, lastPosition);
		m_bookAuthorName.erase(m_bookAuthorName.begin(), find_if(m_bookAuthorName.begin(), m_bookAuthorName.end(), bind1st(not_equal_to<char>(), ' ')));
		m_bookAuthorName.erase(std::find_if(m_bookAuthorName.rbegin(), m_bookAuthorName.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_bookAuthorName.end());

		startPosition = lastPosition + 1;
		lastPosition = strBook.find(',', startPosition);
		m_bookTitle = strBook.substr(startPosition, (lastPosition - startPosition));
		m_bookTitle.erase(m_bookTitle.begin(), find_if(m_bookTitle.begin(), m_bookTitle.end(), bind1st(not_equal_to<char>(), ' ')));
		m_bookTitle.erase(std::find_if(m_bookTitle.rbegin(), m_bookTitle.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_bookTitle.end());
	
		startPosition = lastPosition + 1;
		lastPosition = strBook.find(',', startPosition);
		m_bookCountryPublication = strBook.substr(startPosition, (lastPosition - startPosition));
		m_bookCountryPublication.erase(m_bookCountryPublication.begin(), find_if(m_bookCountryPublication.begin(), m_bookCountryPublication.end(), bind1st(not_equal_to<char>(), ' ')));
		m_bookCountryPublication.erase(std::find_if(m_bookCountryPublication.rbegin(), m_bookCountryPublication.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_bookCountryPublication.end());
	
		startPosition = lastPosition + 1;
		lastPosition = strBook.find(',', startPosition);
		tempStringStorage = strBook.substr(startPosition, (lastPosition - startPosition));
		m_bookPrice = stod(tempStringStorage);

		startPosition = lastPosition + 1;
		lastPosition = strBook.find(',', startPosition);
		tempStringStorage = strBook.substr(startPosition, (lastPosition - startPosition));
		m_bookYearPublication = stoi(tempStringStorage);

		startPosition = lastPosition + 1;
		lastPosition = strBook.find('\n', startPosition);
		m_bookDescription = strBook.substr(startPosition, (lastPosition - startPosition));
		m_bookDescription.erase(m_bookDescription.begin(), find_if(m_bookDescription.begin(), m_bookDescription.end(), bind1st(not_equal_to<char>(), ' ')));
		m_bookDescription.erase(std::find_if(m_bookDescription.rbegin(), m_bookDescription.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_bookDescription.end());
	}

	std::ostream& operator<<(std::ostream& coutRef, const Book& obj)
	{
		// TODO: insert return statement here
		//AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
		//	the author printed on a field of size 20;
		//the title printed on a field of size 22;
		//the country printed on a field of size 5;
		//the year printed on a field of size 4;
		//the price printed on a field of size 6, with 2 decimal digits;
		//see alignment in the sample output.
		coutRef.width(20);
		coutRef.setf(ios::right);
		coutRef << obj.m_bookAuthorName << " | ";
		coutRef.unsetf(ios::right);
		coutRef.width(22);
		coutRef.setf(ios::right);
		coutRef << obj.m_bookTitle << " | ";
		coutRef.unsetf(ios::right);
		coutRef.width(5);
		coutRef.setf(ios::right);
		coutRef << obj.m_bookCountryPublication<< " | ";
		coutRef.unsetf(ios::right);
		coutRef.width(4);
		coutRef << obj.m_bookYearPublication << " | ";
		coutRef.width(6);
		coutRef.setf(ios::right);
		coutRef << fixed;
		coutRef << setprecision(2) << obj.m_bookPrice << " | ";
		coutRef.unsetf(ios::right);
		coutRef << obj.m_bookDescription << endl;
		return coutRef;
	}

}