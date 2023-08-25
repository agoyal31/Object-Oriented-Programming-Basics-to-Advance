/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/15
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include "Restaurant.h"
using namespace std;

namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		this->reservationCount = cnt;

		previousReservations = new Reservation * [cnt];

		for (size_t i = 0; i < cnt; ++i)
		{
			previousReservations[i] = new Reservation(*reservations[i]);
			//previousReservations[i] = new Reservation();
			//*previousReservations[i] = *reservations[i];
		}
	}
	size_t Restaurant::size()
	{
		return this->reservationCount;
	}

	Restaurant::Restaurant(const Restaurant& copyConsRestaurant)
	{
		*this = copyConsRestaurant;
	}

	Restaurant& Restaurant::operator=(const Restaurant& copyConsRestaurant)
	{
		if (this != &copyConsRestaurant) 
		{
			//make sure coming objects' pointer is empty
				if (previousReservations != nullptr) {
					for (size_t i = 0; i < reservationCount; i++) {
						delete previousReservations[i];
						previousReservations[i] = nullptr;
					}
					delete[] previousReservations;
					previousReservations = nullptr;
				}

				reservationCount = copyConsRestaurant.reservationCount;

				if (reservationCount>0) {
					previousReservations = new Reservation * [reservationCount];
					for (size_t i = 0; i < reservationCount; ++i)
					{
						previousReservations[i] = new Reservation(*copyConsRestaurant.previousReservations[i]);
					}
				}

			
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& copyConsRestaurant) {
		operator=(move(copyConsRestaurant));

	}

	Restaurant& Restaurant::operator=(Restaurant&& copyConsRestaurant) {
		if (this != &copyConsRestaurant)
		{
				//to make sure the objects' pointer is nullptr before assigning it
				if (this->previousReservations != nullptr) {
					for (size_t i = 0; i < this->reservationCount; i++) {
						delete previousReservations[i];
						previousReservations[i] = nullptr;
					}
					delete[] previousReservations;
					previousReservations = nullptr;
				}
				//shallow copy

			//copying from incoming object to existing(new) object
				reservationCount = copyConsRestaurant.reservationCount;

				if (reservationCount > 0)
				{
			
					this->previousReservations = copyConsRestaurant.previousReservations;
					//existing object pointer(reservation) is pointed to null(to avoid memory loss)
					copyConsRestaurant.previousReservations = nullptr;
					copyConsRestaurant.reservationCount = 0;
				}
			
		}
		return *this;
	}


	Restaurant::~Restaurant()
	{
		if (this->previousReservations != nullptr) 
		{
			for (size_t i = 0; i < reservationCount; ++i)
			{
				delete previousReservations[i];
				previousReservations[i] = nullptr;
			}
			delete[] previousReservations;
			previousReservations = nullptr;
		}
	}


	std::ostream& operator<<(std::ostream& coutRef, const Restaurant& restaurantReserve)
	{
		static int tempFunctionCount = 0;
		if (restaurantReserve.reservationCount == 0) {
			coutRef << "--------------------------"<<endl;
			coutRef << "Fancy Restaurant (" << ++tempFunctionCount << ")"<<endl;
			coutRef << "--------------------------"<<endl;
			coutRef << "This restaurant is empty!" << endl;
			coutRef << "--------------------------" << endl;
		}
		else {
			coutRef << "--------------------------" << endl;
			coutRef << "Fancy Restaurant (" << ++tempFunctionCount << ")" << endl;
			coutRef << "--------------------------" << endl;
			for (size_t i = 0; i < restaurantReserve.reservationCount; ++i) {
				coutRef << *restaurantReserve.previousReservations[i];
			}
			coutRef << "--------------------------" << endl;
		}
		return coutRef;
	}

}
