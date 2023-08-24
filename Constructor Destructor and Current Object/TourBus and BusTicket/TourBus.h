/*I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  19-11-2022
*/
#include "TourTicket.h"
#include <iostream>

namespace sdds {

	class TourBus {

		TourTicket* ticketObj{};
		int m_CarryPassangers;
		bool done = false;

	public:
		TourBus(int noOfPassangers);
		bool validTour()const;
		TourBus& board();
		void startTheTour()const;
		~TourBus();
	};

}