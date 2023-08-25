/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/15
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef  _SDDS_CONFIRMATIONSENDER_H
#define _SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		size_t incrementCounter = 0;
		const Reservation** confirmationReservation{};
	public:
		ConfirmationSender() = default;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender(const ConfirmationSender& confirm);
		ConfirmationSender& operator=(const ConfirmationSender& confirm);
		ConfirmationSender(ConfirmationSender&& confirm);
		ConfirmationSender& operator=(ConfirmationSender&& confirm);
		virtual ~ConfirmationSender();
		friend std::ostream& operator<<(std::ostream& coutRef, const ConfirmationSender& confirmOrder);

	};
}
#endif // ! _SDDS_CONFIRMATIONSENDER_H

