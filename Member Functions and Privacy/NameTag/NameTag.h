#ifndef SDDS_NameTag_h
#define SDDS_NameTag_h



#include <iostream>


namespace sdds {

	class NameTag {

	public:

		char name[50];
		int words;
		void set(const char* name);
	};
}

#endif // !NameTag