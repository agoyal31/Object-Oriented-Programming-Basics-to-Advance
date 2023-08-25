/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/15
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include "ConfirmationSender.h"
using namespace std;

namespace sdds {

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		const Reservation** temporaryReservation{};
		bool continueC = true;
		temporaryReservation = confirmationReservation;
		for (size_t i = 0; i < incrementCounter; ++i)
		{
			if (temporaryReservation[i] == &res) 
			{
				continueC = false;
			}
		}

		if (continueC == true) 
		{
			++incrementCounter;
			confirmationReservation = new const Reservation * [incrementCounter];
			for (size_t i = 0; i < (incrementCounter - 1); ++i)
			{
				confirmationReservation[i] = temporaryReservation[i];
			}
			delete[] temporaryReservation;
			temporaryReservation = nullptr;
			confirmationReservation[incrementCounter - 1] = &res;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0; i < incrementCounter; ++i)
		{
			if (confirmationReservation[i] == &res)
			{
				confirmationReservation[i] = nullptr;
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& confirm)
	{
		*this = confirm;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& confirm)
	{
		if (this != &confirm) 
		{
			if (confirmationReservation != nullptr) 
				{
					delete[] confirmationReservation;
					confirmationReservation = nullptr;
			    }
				//shallow copy
				incrementCounter = confirm.incrementCounter;
				//deep copy
				if (confirm.confirmationReservation != nullptr)
				{
					confirmationReservation = new const Reservation * [incrementCounter];
					for (size_t i = 0; i < incrementCounter; i++) {
						confirmationReservation[i] = confirm.confirmationReservation[i];
					}
				}
			
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& confirm)
	{
		operator=(move(confirm));
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& confirm)
	{
		if (this != &confirm) {

				if (confirmationReservation != nullptr) {

					delete[] confirmationReservation;
					confirmationReservation = nullptr;
				}
				incrementCounter = confirm.incrementCounter;
				if (confirm.confirmationReservation != nullptr) 
				{
	
			    confirmationReservation = confirm.confirmationReservation;
				confirm.confirmationReservation = nullptr;
				confirm.incrementCounter = 0;
			    }
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		if (this->confirmationReservation) {
			delete[] confirmationReservation;
		}
	}



	std::ostream& operator<<(std::ostream& coutRef, const ConfirmationSender& confirmOrder)
	{
		coutRef << "--------------------------" << endl;
		coutRef << "Confirmations to Send" << endl;
		coutRef << "--------------------------" << endl;

		if (confirmOrder.confirmationReservation != nullptr)
		{
			for (size_t i = 0; i < (confirmOrder.incrementCounter); i++)
			{
				if (confirmOrder.confirmationReservation[i])
					coutRef << *(confirmOrder.confirmationReservation[i]);
			}
		}
		else
		{
			coutRef << "There are no confirmations to send!" << endl;
		}
		coutRef << "--------------------------" << endl;
		return coutRef;
	}
	

}
