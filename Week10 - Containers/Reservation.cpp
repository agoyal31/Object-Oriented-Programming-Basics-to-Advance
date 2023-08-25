/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/15
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
#include "Reservation.h"
using namespace std;

namespace sdds {
	void Reservation::update(int day, int time)
	{
		m_partyOrganisedDay = day;
		m_partyOrganisedHour = time;
	}

	Reservation::Reservation(const string& res)
	{
		//ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
		size_t startPosition{};
		size_t lastPosition;
		string tempStringStorage;
		lastPosition = res.find(':', startPosition);
		m_reservationID = res.substr(startPosition,lastPosition);
		m_reservationID.erase(m_reservationID.begin(), find_if(m_reservationID.begin(), m_reservationID.end(), bind1st(not_equal_to<char>(), ' ')));
		m_reservationID.erase(std::find_if(m_reservationID.rbegin(), m_reservationID.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_reservationID.end());

		startPosition = lastPosition + 1;
		lastPosition = res.find(',', startPosition);
		m_reservationName = res.substr(startPosition, (lastPosition-startPosition));
		m_reservationName.erase(m_reservationName.begin(), find_if(m_reservationName.begin(), m_reservationName.end(), bind1st(not_equal_to<char>(), ' ')));
		m_reservationName.erase(std::find_if(m_reservationName.rbegin(), m_reservationName.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_reservationName.end());

		startPosition = lastPosition + 1;
		lastPosition = res.find(',', startPosition);
		m_confirmationEmail = res.substr(startPosition, (lastPosition - startPosition));
		m_confirmationEmail.erase(m_confirmationEmail.begin(), find_if(m_confirmationEmail.begin(), m_confirmationEmail.end(), bind1st(not_equal_to<char>(), ' ')));
		m_confirmationEmail.erase(std::find_if(m_confirmationEmail.rbegin(), m_confirmationEmail.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_confirmationEmail.end());
		
		startPosition = lastPosition + 1;
		lastPosition = res.find(',', startPosition);
		tempStringStorage = res.substr(startPosition, (lastPosition - startPosition));
		m_numOfPeople = stoi(tempStringStorage);

		startPosition = lastPosition + 1;
		lastPosition = res.find(',', startPosition);
		tempStringStorage = res.substr(startPosition, (lastPosition - startPosition));
		m_partyOrganisedDay = stoi(tempStringStorage);

		startPosition = lastPosition + 1;
		lastPosition = res.find(',', startPosition);
		tempStringStorage = res.substr(startPosition, (lastPosition - startPosition));
		m_partyOrganisedHour = stoi(tempStringStorage);
	}


	 ostream& operator<<(ostream& coutRef, const Reservation& obj)
	 {
		string tempEmailStorage = "<" + obj.m_confirmationEmail + ">";
		coutRef << "Reservation" << " ";
		coutRef.width(10);
		coutRef.setf(ios::right);
		coutRef << obj.m_reservationID << ": ";
		coutRef.unsetf(ios::right);
		coutRef.width(20);
		coutRef.setf(ios::right);
		coutRef << obj.m_reservationName << "  ";
		coutRef.unsetf(ios::right);
		coutRef.width(20);
		coutRef.setf(ios::left);
		coutRef << tempEmailStorage;
		coutRef.unsetf(ios::left);
		coutRef << "    ";

		if (obj.m_partyOrganisedHour >= 6 && obj.m_partyOrganisedHour <= 9) {
			coutRef << "Breakfast on day " << obj.m_partyOrganisedDay;
		}
		else if (obj.m_partyOrganisedHour >= 11 && obj.m_partyOrganisedHour <= 15) {
			coutRef << "Lunch on day " << obj.m_partyOrganisedDay;
		}
		else if (obj.m_partyOrganisedHour >= 17 && obj.m_partyOrganisedHour <= 21) {
			coutRef << "Dinner on day " << obj.m_partyOrganisedDay;
		}
		else {
			coutRef << "Drinks on day " << obj.m_partyOrganisedDay;
		}
		coutRef << " @ " << obj.m_partyOrganisedHour << ":00 " << "for " << obj.m_numOfPeople;
		if (obj.m_numOfPeople == 1) {
			coutRef << " person." << endl;
		}
		else {
			coutRef << " people." << endl;
		}

		return coutRef;
	 }

}
