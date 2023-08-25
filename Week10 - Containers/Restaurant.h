/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/15
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Reservation.h"
#ifndef _SDDS_RESTAURANT_H
#define _SDDS_RESTAURANT_H
namespace sdds {
	class Restaurant {
		Reservation** previousReservations{};
		size_t reservationCount{};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size();
		Restaurant(const Restaurant& copyConsRestaurant);
		Restaurant& operator=(const Restaurant& copyConsRestaurant);
		Restaurant(Restaurant&& copyConsRestaurant);
		Restaurant& operator=(Restaurant&& copyConsRestaurant);
		virtual ~Restaurant();
		friend std::ostream& operator<<(std::ostream& coutRef, const Restaurant& restaurantReserve);
	};
}
#endif
