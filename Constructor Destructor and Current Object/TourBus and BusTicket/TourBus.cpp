/*
I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  19-11-2022
*/
#include "TourBus.h"
#include <iostream>


using namespace std;

namespace sdds {
	TourBus::TourBus(int noOfPassangers)
	{
		m_CarryPassangers = noOfPassangers;
	}

	bool TourBus::validTour()const
	{
		return (m_CarryPassangers == 4 || m_CarryPassangers == 16 || m_CarryPassangers == 22);
	}

	TourBus& TourBus::board()
	{
		ticketObj = new TourTicket[m_CarryPassangers];

		cout << "Boarding" <<" "<< m_CarryPassangers <<" " << "Passengers:" <<endl;

		for (int i = 0; i < m_CarryPassangers; i++) 
		{
			char tempName[40];
			cout << i + 1 << "/" << m_CarryPassangers << "- ";
			cout << "Passenger Name: ";
			cin.getline(tempName, 40, '\n');
			ticketObj[i].issue(tempName);
		}
		done = true;
		return *this;
	}

	void TourBus::startTheTour()const
	{
		if (validTour() && done) 
		{

			cout << "Starting the tour...." << endl;
			cout << "Passenger List:" << endl;
			cout << "|Row | ";
			cout.width(40);
			cout.setf(ios::left);
			cout << "Passenger Name" << " | " << "Num" << " |" << endl;;
			//cout.unsetf(ios::left);
			cout.unsetf(ios::left);
            cout << "+----+";
			cout << "--";
			//cout << setw(40) << setfill('-') << "" << endl;
			cout.width(40);
			cout.fill('-');
			cout << "";
			cout << "+-----+";
			cout << endl;

			for (int i = 0; i < m_CarryPassangers; i++) 
			{
				cout.fill(' ');
				cout << "|";
				cout.width(3);
				cout.setf(ios::right);
				cout << i + 1 << ' ';
				cout.unsetf(ios::right);
				ticketObj[i].display();
				cout << endl;
			}

			cout << "+----+";
			cout << "--";
			cout.width(40);
			cout.fill('-');
			cout << "";
			cout << "+-----+" << endl;
		}
		else if (validTour() && done == false) 
		{
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
	}
	TourBus::~TourBus()
	{
		delete[] ticketObj;
	}
}