/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/19
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool is_valid_sin(const std::string& sin) const {
			if (sin.size() != 9) {
				return false;
			}

			int sum = 0;
			bool doubleDigit = false;

			for (int i = 8; i >= 0; --i) {
				if (sin[i] < '0' || sin[i] > '9') {
					throw std::invalid_argument("Invalid SIN format");
				}

				int digit = sin[i] - '0';

				if (doubleDigit) {
					digit *= 2;
					if (digit > 9) {
						digit -= 9;
					}
				}

				sum += digit;
				doubleDigit = !doubleDigit;
			}

			return (sum % 10 == 0);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.

		void operator+= (T* t){
			list.push_back(*t);
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.

		void operator+=(std::unique_ptr<T> t) {
			list.push_back(*t);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
