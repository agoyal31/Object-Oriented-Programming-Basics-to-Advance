#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H



namespace sdds {

#include <iostream>

	class Text {

		char* m_content{};

	protected:
		const char& operator[](int index)const;

	public:
		int m_contentLength;

		Text() = default;

		Text(const Text& A);
		Text& operator=(const Text& A);
		virtual ~Text();

		std::istream& read(std::istream& cinRef);
		virtual std::ostream& write(std::ostream& coutRef) const;
	};

	std::ostream& operator<<(std::ostream& coutRef, const Text& A);
	std::istream& operator>>(std::istream& cinRef, Text& A);

}

#endif // !SDDS_TEXT_H