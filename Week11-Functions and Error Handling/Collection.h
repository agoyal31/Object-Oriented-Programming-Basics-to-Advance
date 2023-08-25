/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/22
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H
#include<string>
namespace sdds {
	template <typename T>
	class Collection {
	private:
		std::string m_collectionName{};
		T* m_dynArray{};
		int m_arraySize{};
		auto (*funcPtr)(const Collection<T>&, const T&) -> void {};
	public:
		Collection(const Collection<T>& colName) = delete;
		Collection<T> operator=(const Collection<T>& colName) = delete;
		Collection(const std::string& name);
		virtual ~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
	};

	template <typename T>
	inline Collection<T>::~Collection() {
		delete[] m_dynArray;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& coutRef, const Collection<T>& collection) {
		for (int i = 0; i < collection.size(); ++i) {
			coutRef << collection[i];
		}
		return coutRef;
	}


	template<typename T>
	inline Collection<T>::Collection(const std::string& name)
	{
		m_collectionName = name;
		m_dynArray = nullptr;
		m_arraySize = 0;
		funcPtr = nullptr;
	}

	template<typename T>
	inline const std::string& Collection<T>::name()const
	{
		return m_collectionName;
	}

	template<typename T>
	inline size_t Collection<T>::size()const
	{
		return m_arraySize;
	}

	template<typename T>
	inline void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&))
	{
		funcPtr = observer;
	}

	template<typename T>
	inline Collection<T>&Collection<T>::operator+=(const T& item)
	{
		bool xcontinue = true;
		for (int i = 0; i < m_arraySize; ++i) {
			if (item.title() == m_dynArray[i].title()) {
				xcontinue = false;
			}
		}
		if (xcontinue == true) 
		{
			T* tempItemStorage{};

			if (m_arraySize > 0) 
			{
				tempItemStorage = new T[m_arraySize];
				for (int i = 0; i < m_arraySize; ++i) 
				{
					tempItemStorage[i] = m_dynArray[i];
				}
			}
			delete[] m_dynArray;
			m_arraySize++;
			m_dynArray = new T[m_arraySize];
			for (int i = 0; i < (m_arraySize - 1); i++) 
			{
				m_dynArray[i] = tempItemStorage[i];
			}
			delete[] tempItemStorage;
			tempItemStorage = nullptr;
			m_dynArray[m_arraySize - 1] = item;

			if (funcPtr) 
			{
				funcPtr(*this, item);
			}
		}
		return *this;
	}

	//		T& operator[](size_t idx) const;

	template<typename T>
	inline T& Collection<T>::operator[](size_t idx) const
	{
		if (idx < m_arraySize && idx >= 0) 
		{
			return m_dynArray[idx];
		}
		else 
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_arraySize) + "] items.");
		}
	}

	template<typename T>
	inline T* Collection<T>::operator[](const std::string& title) const
	{
		for (int i = 0; i < m_arraySize; ++i) 
		{
			if (m_dynArray[i].title() == title) 
			{
				return &m_dynArray[i];
			}
		}
		return nullptr;

	}
}



#endif
