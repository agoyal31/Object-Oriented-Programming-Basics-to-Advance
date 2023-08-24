#include "Mark.h"
#include <iostream>

namespace sdds {

	Mark::Mark(int value)
	{
		if (value > 100 || value < 0) {
			m_mark = -1;
		}
		else {
			m_mark = value;
		}
	}

	Mark::operator const int()const
	{
		return (m_mark < 0 || m_mark > 100) ? 0 : m_mark; // 2 entry/exit point??
	}

	Mark::operator const double()const
	{
		double temp;
		if (m_mark > 0 && m_mark < 100){
			temp = 0.0;
			if (m_mark > 49) {
				temp = 1.0;
				if (m_mark > 59) {
					temp = 2.0;
					if (m_mark > 69) {
						temp = 3.0;
						if (m_mark > 79) {
							temp = 4.0;
						}
					}
				}
			}

		}
		else {
			temp = 0;
		}
		return temp;
	}

	Mark::operator const char ()const
	{
		char temp;
		if (m_mark > 0 && m_mark < 100) {
			temp = 'F';
			if (m_mark > 49) {
				temp = 'D';
				if (m_mark > 59) {
					temp = 'C';
					if (m_mark > 69) {
						temp = 'B';
						if (m_mark > 79) {
							temp = 'A';
						}
					}
				}
			}

		}
		else {
			temp = 'X';
		}
		return temp;
	}

	Mark::operator const bool()const
	{
		return (m_mark >= 0 && m_mark <= 100);
	}

	bool Mark::operator>(const Mark& right) const
	{
		return (m_mark > right.m_mark);
	}

	bool Mark::operator<(const Mark& right) const
	{
		return (m_mark < right.m_mark);
	}

	bool Mark::operator>=(const Mark& right) const
	{
		return (m_mark >= right.m_mark);
	}

	bool Mark::operator<=(const Mark& right) const
	{
		return (m_mark <= right.m_mark);
	}

	bool Mark::operator==(const Mark& right) const
	{
		return (m_mark == right.m_mark);
	}

	bool Mark::operator!=(const Mark& right) const
	{
		return (m_mark != right.m_mark);
	}

	Mark& Mark::operator++()
	{
		if (bool(*this)){
			m_mark++;
		}
		return *this;
	}

	Mark& Mark::operator--()
	{
		if (m_mark >= 0 && m_mark <= 100) {
			m_mark--;
		}
		return *this;
	}

	Mark Mark::operator++(int){
		Mark old(m_mark);
		if (bool(*this)) {
			
			old.m_mark = m_mark++;
		}
		return old;
	}

	Mark Mark::operator--(int){
		Mark old(m_mark);
		if (bool(*this)) {

			old.m_mark = m_mark--;
		}
		return old;
	}

	bool Mark::operator~()
	{
		return (m_mark > 49 && m_mark <= 100);
	}

	Mark& Mark::operator=(const int A)
	{
		if (A > 100 || A < 0) {
			m_mark = 0;
		}
		m_mark = A;

		return *this;
	}

	Mark& Mark::operator+=(const int B)
	{
		m_mark += B;
		return *this;
	}

	Mark& Mark::operator-=(const int B)
	{
		m_mark -= B;
		return *this;
	}

	int operator+=(int& B, const Mark& right)
	{
		B += int(right);
		return B;
	}

	int operator-=(int& B, const Mark& right)
	{
		B -= int(right);
		return B;
	}

	Mark Mark::operator+(int right)const
	{
		Mark a;
		a.m_mark = m_mark + right;
		return a;
	}

	Mark Mark::operator+(const Mark& right)const
	{
		Mark a;
		a.m_mark = m_mark + right.m_mark;
		return a;
	}

	const Mark operator+(const Mark& left, const int right)
	{
		Mark a;
		a = int(left) + right;
		return a;
	}

	int operator+(const int left, const Mark& right)
	{
		return int(right) + left;
	}

	Mark& Mark::operator<<(Mark& right)
	{
		m_mark += right.m_mark;
		right.m_mark = 0;
		return *this;
	}

	Mark& Mark::operator>>(Mark& right)
	{
		right.m_mark += m_mark;
		m_mark = 0;
		return *this;
	}
}