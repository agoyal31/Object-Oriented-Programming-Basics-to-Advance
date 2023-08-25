/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include "Vehicle.h"
#include <string>
#include<vector>
#include<list>


namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles; // vector 'm_vehicles' holds pointer of -> Vehicle*
	public:
		Autoshop& operator +=(Vehicle* theVehicle); // adds the vehicle pointer to the vector
		void display(std::ostream& out) const;      // displays the extracted string tokens(m_carMakerCompany, m_carCondition, 
		                                            //m_maxCarSpeed) from the file on the console
		virtual ~Autoshop(); // destructor

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);

	};
	// the select function in the Autoshop class is a template function that selects vehicles from the m_vehicles collection 
	// based on a given test condition. It iterates over the collection, applies the test condition to each vehicle, and adds 
	// the vehicles that pass the test to the vehicles list
	template<typename T>
	inline void Autoshop::select(T test, std::list<const Vehicle*>& vehicles)
	{
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
			if (test(*it)) {
				vehicles.push_back(*it);
			}

		}
	}
}
#endif
