/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"Autoshop.h"
using namespace std;

namespace sdds 
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) 
	{
		m_vehicles.push_back(theVehicle);
		// responsible for adding 'theVehicle' pointer into the vector -> 'm_vehicles' 
		return *this;
	}


	void Autoshop::display(std::ostream& out) const
	//the display function prints a header, iterates over the m_vehicles collection, calls the display 
	//function for each vehicle object, and outputs a separator line at the end. This allows for the display of information 
	//about the cars in the autoshop when using an std::ostream object as the output destination.
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i) 
		{ 
			(*i)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop() //destructor
	{
	//responsible for deleting all the dynamically allocated vehicle objects stored in the m_vehicles collection. 
	//It's essential to ensure proper memory management to avoid memory leaks when dynamically allocating objects.
		for (long unsigned int i = 0; i < m_vehicles.size(); ++i) 
		{
			delete m_vehicles[i]; 
		}
	}

}