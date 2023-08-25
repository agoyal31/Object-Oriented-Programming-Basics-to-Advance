/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/04
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"
namespace sdds {
	template <typename T>
	class UniqueQueue :public Queue<T, 100> {
	public:
		UniqueQueue() = default;
		UniqueQueue(const T& m_uniqueQueue) = delete;
		UniqueQueue operator=(const T& m_uniqueQueue) = delete;
		bool push(const T& item);
	};

	template <typename T>
	bool UniqueQueue <T>::push(const T& item) {
		if (this->size() < 100) {
			for (int i = 0; i < this->size(); i++) {
				if (this->arrayForObjects[i] == item) {
					return false;
				}
			}
			this->arrayForObjects[this->size()] = item;
			this->objectCount++;
			return true;
		}
		return false;
	};
	template<>
	bool UniqueQueue <double>::push(const double& item) {
		if (this->size() < 100) {
			for (int i = 0; i < this->size(); i++) {
				if (abs(this->arrayForObjects[i] - item) <= 0.005) {
					return false;
				}
			}
			this->arrayForObjects[this->size()] = item;
			this->objectCount++;
			return true;
		}
		return false;

	};


}
#endif
