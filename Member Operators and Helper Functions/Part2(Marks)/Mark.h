#ifndef SDDS_MARK_H
#define SDDS_MARK_H

#include <iostream>

namespace sdds{


	class Mark {

		int m_mark;

	public:

		Mark(int value = 0);

		bool operator >(const Mark& right)const;
		bool operator <(const Mark& right)const;
		bool operator >=(const Mark& right)const;
		bool operator <=(const Mark& right)const;
		bool operator ==(const Mark& right)const;
		bool operator !=(const Mark& right)const;
		Mark& operator++();
		Mark& operator--();
		Mark operator++(int);
		Mark operator--(int);
		bool operator~();
		Mark& operator=(const int A);
		Mark& operator+=(const int B);
		Mark& operator-=(const int B);
		operator const int()const;
		operator const double()const;
		operator const char()const;
		operator const bool()const;

		Mark operator+(int right)const;
		Mark operator+(const Mark& right)const;


		Mark& operator<<(Mark& right);
		Mark& operator>>(Mark& right);

	};

	int operator+=(int& B, const Mark& right);
	int operator-=(int& B, const Mark& right);
	int operator+(const int left, const Mark& right);
}

#endif // !SDDS_MARK_H

