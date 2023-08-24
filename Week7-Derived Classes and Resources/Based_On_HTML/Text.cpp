
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Text.h"
#include "Utils.h"

namespace sdds
{

	const char &Text::operator[](int index) const
	{
		if (m_content != NULL)
		{
			return m_content[index];
		}
		return m_content[0];
	}

	Text::Text(const Text &A)
	{
		if (A.m_content && A.m_content[0])
		{

			m_content = new char[ut.strlen(A.m_content) + 1];
			ut.strcpy(m_content, A.m_content);
			m_contentLength = ut.strlen(m_content);
		}
	}

	Text &Text::operator=(const Text &A)
	{
		if (this != &A)
		{
			if (A.m_content && A.m_content[0])
			{

				delete[] m_content;
				m_content = new char[ut.strlen(A.m_content) + 1];
				ut.strcpy(m_content, A.m_content);
				m_contentLength = ut.strlen(m_content);
			}
		}
		return *this;
	}

	Text::~Text()
	{
		delete[] m_content;
	}

	std::istream &Text::read(std::istream &cinRef)
	{
		delete[] m_content;
		cinRef.clear();

		int lengthOfFile = ut.getFileLength(cinRef);

		m_content = new char[lengthOfFile + 1];

		for (int i = 0; i < lengthOfFile; i++)
		{
			cinRef.get(m_content[i]);
			cinRef.clear();
			if (i == lengthOfFile - 1)
			{
				m_content[i + 1] = 0;
			}
		}
		return cinRef;
	}

	std::ostream &Text::write(std::ostream &coutRef) const
	{
		if (m_content != NULL)
		{
			for (int i = 0; i < ut.strlen(m_content); i++)
			{
				// why cannot do this!!!!!!!  coutRef << m_content;
				coutRef << m_content[i];
			}
		}
		return coutRef;
	}

	std::ostream &operator<<(std::ostream &coutRef, const Text &A)
	{
		return A.write(coutRef);
	}

	std::istream &operator>>(std::istream &cinRef, Text &A)
	{
		return A.read(cinRef);
	}
}
