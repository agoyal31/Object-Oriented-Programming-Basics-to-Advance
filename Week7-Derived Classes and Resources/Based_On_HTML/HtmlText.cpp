#define _CRT_SECURE_NO_WARNINGS

#include "HtmlText.h"
#include <iostream>

using namespace std;

namespace sdds {

	sdds::HtmlText::HtmlText() : Text()
	{
		m_title = nullptr;
	}

	sdds::HtmlText::HtmlText(const char* title) : Text()
	{
		if (title && title[0]) {
			m_title = new char[ut.strlen(title) + 1];
			ut.strcpy(m_title, title);
		}
		else {
			m_title = new char[ut.strlen(title) + 1];
			ut.strcpy(m_title, "");
		}
	}

	sdds::HtmlText::HtmlText(const HtmlText& H)
	{
		if (H.m_title && H.m_title[0]) {
			m_title = new char[ut.strlen(H.m_title) + 1];
			ut.strcpy(m_title, H.m_title);


			Text::operator=(H);
		}
	}

	HtmlText& sdds::HtmlText::operator=(const HtmlText& H)
	{
		if (&H != this) {
			if (H.m_title && H.m_title[0]) {
				delete[] m_title;

				m_title = new char[ut.strlen(H.m_title) + 1];
				ut.strcpy(m_title, H.m_title);

				Text::operator=(H);
			}
		}
		return *this;
	}

	sdds::HtmlText::~HtmlText()
	{
		delete[] m_title;
	}

	std::ostream& sdds::HtmlText::write(std::ostream& coutRef) const
	{
		bool MS = false;

		coutRef << "<html><head><title>";

		if (m_title) {
			coutRef << m_title;
		}
		else {
			coutRef << "No Title";
		}

		coutRef << "</title></head>\n<body>\n";
		if (m_title) {
			coutRef << "<h1>" << m_title << "</h1>\n";
		}
		for (int i = 0; i < m_contentLength; i++) {

			char tempValue = Text::operator[](i);

			if (tempValue == ' ') {
				if (MS == true) {
					coutRef << "&nbsp;";
				}
				else {
					MS = true;
					coutRef << ' ';
				}
			}
			else if (tempValue == '<') {
				coutRef << "&lt;";
				MS = false;
			}
			else if (tempValue == '>') {
				coutRef << "&gt;";
				MS = false;
			}
			else if (tempValue == '\n') {
				coutRef << "<br />\n";
				MS = false;
			}
			else {
				MS = false;
				coutRef << tempValue;
			}

		}
		return coutRef << "</body>\n</html>";
	}
}

