#ifndef SDDS_TagList_h
#define SDDS_TagList_h



#include <iostream>
#include "NameTag.h"


namespace sdds {

	class TagList {

		public:
		NameTag* obj;
		int noOfnamesT;
		int biggestLength =  0;
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();

	};

}
#endif // !SDDS_TagList_h