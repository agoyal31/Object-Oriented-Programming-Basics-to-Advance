#include "TagList.h"
#include <iostream>
#include <iomanip>
#include "Utils.h"

namespace sdds {

	void TagList::set()
	{
		obj = nullptr;
		noOfnamesT = 0;
	}

	void TagList::set(int num)
	{
		cleanup();
		obj = new NameTag[num]; // no of words (55)
	}

	void TagList::add(const NameTag& nt)
	{
		obj[noOfnamesT] = nt;

			if (strlen(obj[noOfnamesT].name) > biggestLength) {
				biggestLength = strlen(obj[noOfnamesT].name);
			}

		noOfnamesT += 1;
	}

	void sdds::TagList::print()
	{
		for (int i = 0; i < noOfnamesT; i++) {
			std::cout.fill('*');
			std::cout.width(biggestLength);
			std::cout << "*"; // ek star mila ke 26 spaces pad jayengi. Fir 4 stars bad wale. total 30 hogyi spaces.
			std::cout << "****" << std::endl;
			std::cout << std::left;
			std::cout << "* ";
			std::cout.width(biggestLength);
			std::cout.fill(' ');
			std::cout << obj[i].name;
			std::cout << " *" << std::endl;
			std::cout.width(biggestLength);
			std::cout.fill('*');
			std::cout.width(biggestLength);
			std::cout << "*";
			std::cout << "****" << std::endl;
		}
	}

	void sdds::TagList::cleanup()
	{
		delete[] obj;
		obj = nullptr;
	}
}
