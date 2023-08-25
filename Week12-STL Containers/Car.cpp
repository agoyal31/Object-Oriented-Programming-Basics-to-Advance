/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Car.h"
#include<iostream>
#include<functional>
#include <iomanip>
 
using namespace std;

namespace sdds {
	Car::Car(istream& cinRef) // Car constructor reads and processes input from the cinRef istream object to initialize the member variables of the Car object. 
		                      // It handles various input validation checks and throws exceptions if any invalid input is encountered
	{
			   getline(cinRef, m_carMakerCompany,',');
			   
				m_carMakerCompany.erase(m_carMakerCompany.begin(), find_if(m_carMakerCompany.begin(), m_carMakerCompany.end(), bind1st(not_equal_to<char>(), ' ')));
				m_carMakerCompany.erase(std::find_if(m_carMakerCompany.rbegin(), m_carMakerCompany.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_carMakerCompany.end());
				
				getline(cinRef, m_carCondition, ',');

				m_carCondition.erase(m_carCondition.begin(), find_if(m_carCondition.begin(), m_carCondition.end(), bind1st(not_equal_to<char>(), ' ')));
				m_carCondition.erase(std::find_if(m_carCondition.rbegin(), m_carCondition.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_carCondition.end());
			    if (m_carCondition == "") {
					m_carCondition = "n";
				}
				else if (m_carCondition != "n"  && m_carCondition != "u" && m_carCondition != "b") {
					cinRef.ignore(1000, '\n');
					string tempStoreException = "Invalid record!";
					throw tempStoreException;
				}

				cinRef >> m_maxCarSpeed;
				if(!cinRef){
					cinRef.clear();
					cinRef.ignore(10000, '\n');
					string tempStoreException = "Invalid record!";

					throw tempStoreException;
 
      			}

	}
	std::string Car::condition() const //returns the condition of a car/Racecar (new, broken or used)
	{
		return m_carCondition;
	}
	double Car::topSpeed() const //returns the speed of a car/Racecar(depends upon which class object is created)
		                         //since it is virtual(so everytime latest class object (car or racecar) topSpeed() is displayed)
	{
		return m_maxCarSpeed;
	}
	void Car::display(std::ostream& out) const //displays the extracted tokens(m_carMakerCompany, m_carCondition and topSpeed()) of a Car or Racecar object to the console
		                                       //in specified format
	{
		out << "| ";
		out.width(10);
		out.setf(ios::right);
		out << m_carMakerCompany << " | ";
		out.unsetf(ios::right);
		out.width(6);
		out.setf(ios::left);
		if (m_carCondition == "n") {
			out << "new" << " | ";
		}
		else  if (m_carCondition == "u") {
			out << "used" << " | ";
		}
		else  if (m_carCondition == "b") {
			out << "broken" << " | ";
		}
		out.unsetf(ios::left);
		out.width(6);
		out.setf(ios::right);
		out << fixed;
		out << setprecision(2) << topSpeed() << " |";
		out.unsetf(ios::right);
	} 
}
