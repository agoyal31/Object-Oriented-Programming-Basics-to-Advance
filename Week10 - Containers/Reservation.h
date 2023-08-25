/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/15
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_RESERVATION_H
#define _SDDS_RESERVATION_H
#include <string>
namespace sdds {
	class Reservation {
		std::string m_reservationID{};		
		std::string m_reservationName{};
		std::string m_confirmationEmail{};
		unsigned m_numOfPeople{};
		unsigned m_partyOrganisedDay{};
		unsigned m_partyOrganisedHour{};
	public:
		Reservation() = default;
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& coutRef, const Reservation& obj);

	};
}

#endif
