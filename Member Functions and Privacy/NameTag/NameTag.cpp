#define _CRT_SECURE_NO_WARNINGS
#include "TagList.h"
#include "Utils.h"

namespace sdds {

	void NameTag::set(const char* name)
	{
		strcpy(this->name, name);
	}

}