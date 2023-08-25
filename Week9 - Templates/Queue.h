/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/06/04
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Dictionary.h"
namespace sdds {
	template<typename T, int t_queue_capacity>
	class Queue {
	protected:
		int objectCount{};
		T arrayForObjects[t_queue_capacity];
		static T objectNotInQueue; //dummy object(to be specialized)
	public:
		virtual ~Queue() {};
		virtual bool push(const T& item) {
			if (objectCount <= t_queue_capacity) {
				arrayForObjects[objectCount] = item;
				objectCount++;
				return true;
			}
			else {
				return false;
			}
		}

		T pop() { //because copy is returned(hence no reference)
			T removedFirstObject;
			removedFirstObject = arrayForObjects[0];
			for (int i = 0; i < (objectCount-1); i++) {
				arrayForObjects[i] = arrayForObjects[i + 1];
			}
			arrayForObjects[objectCount-1] = {};
			objectCount--;
			return removedFirstObject;
		}
		int size() {
			return objectCount;
		}
		void display(std::ostream& cout = std::cout)const {
			cout << "----------------------" << std::endl;
			cout << "| Dictionary Content |" << std::endl;
			cout << "----------------------" << std::endl;
			for (int i = 0; i < objectCount; ++i) {
				cout << arrayForObjects[i] << std::endl;
			}
			cout << "----------------------"<<std::endl;
		}
		T operator[](int index) {
			if (index < objectCount) {
				return arrayForObjects[index];
			}
			else {
				return objectNotInQueue;
			}
		}
	};

	template<typename T, int t_queue_capacity>
	T Queue<T, t_queue_capacity>::objectNotInQueue{};

	template<>
	Dictionary Queue<Dictionary, 100>::objectNotInQueue("Empty Term", "Empty Substitute");

}
#endif // !

