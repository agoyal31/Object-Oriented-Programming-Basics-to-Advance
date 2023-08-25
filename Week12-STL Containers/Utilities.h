/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/08
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
#include<iostream>
#include<string>
#include"Vehicle.h"
#include"Car.h"
#include"Racecar.h"

namespace sdds {
		Vehicle* createInstance(std::istream& in); // from main module createInstance(file) object of file is being sent as parameter to createInstance function that returns the pointer to that vehicle 
}
#endif
