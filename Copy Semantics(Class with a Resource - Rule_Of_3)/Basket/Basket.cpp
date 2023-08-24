/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:02/12/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include<iostream>
#include"Basket.h"


using namespace std;
 namespace sdds {
	 Basket::Basket()
	 {
	 }
	 Basket::Basket(Fruit* arrayofObject, int sizerecieved, double basketPrice)
	 {
		 if (sizerecieved > 0 && basketPrice > 0 && arrayofObject) {
				 m_fruitsarray = new Fruit[sizerecieved];
				 
				 for (int i = 0; i < sizerecieved; i++) {
					 strcpy(m_fruitsarray[i].m_name, arrayofObject[i].m_name);
					 m_fruitsarray[i].m_qty = arrayofObject[i].m_qty;
				 }
				 m_sizeofArray = sizerecieved;
				 m_priceOfBasket = basketPrice;
		 }
	 }

	 Basket::Basket(const Basket& B)
	 {
		 *this = B;
	 }

	 Basket& Basket::operator=(const Basket& B)
	 {
			 if (this != &B) {
				 m_priceOfBasket = B.m_priceOfBasket;
				 m_sizeofArray = B.m_sizeofArray;
				 delete[] m_fruitsarray;
				 m_fruitsarray = nullptr;
				 m_fruitsarray = new Fruit[B.m_sizeofArray];

				 for (int i = 0; i < m_sizeofArray; i++) {
					 strcpy(m_fruitsarray[i].m_name, B.m_fruitsarray[i].m_name);
					 m_fruitsarray[i].m_qty = B.m_fruitsarray[i].m_qty;
				 }
			 }
		 return *this;
	 }

	 Basket::~Basket()
	 {
		 delete[] m_fruitsarray;
		 m_fruitsarray = nullptr;
	 }

	 void Basket::setPrice(double price)
	 {
		 m_priceOfBasket = price;
	 }

	 Basket::operator bool() const
	 {
		 return (this->m_sizeofArray);
	 }

	 Basket& Basket::operator+=(Fruit F)
	 {
		 if (F.m_name && F.m_qty) {

			 Fruit* A = new Fruit[m_sizeofArray];
			 if (m_sizeofArray > 0) {
				 for (int i = 0; i < m_sizeofArray; i++) {
					 strcpy(A[i].m_name, m_fruitsarray[i].m_name);
					 A[i].m_qty = m_fruitsarray[i].m_qty;
				 }
			 }
			 delete[] m_fruitsarray;
			 m_fruitsarray = nullptr;
			 m_fruitsarray = new Fruit[m_sizeofArray + 1];

			 int iw = 0;

			 for (iw = 0; iw < m_sizeofArray; iw++){
				
				strcpy(m_fruitsarray[iw].m_name, A[iw].m_name);
				m_fruitsarray[iw].m_qty = A[iw].m_qty;
			 }
			 strcpy(m_fruitsarray[iw].m_name, F.m_name);
			 m_fruitsarray[iw].m_qty = F.m_qty;

			 m_sizeofArray++;
			 iw = 0;

			 delete[] A;

		 }
		 return *this;
	 }

	 std::ostream& operator<<(std::ostream& coutRef, const Basket& B)
	 {
		 if (!bool(B)) {
			 coutRef << "The basket is empty!" << endl;
		 }
		 else {
			 coutRef << "Basket Content:" << endl;
			 for (int i = 0; i < B.m_sizeofArray; i++) {
				 coutRef.width(10);
				 coutRef.setf(ios::right);
				 coutRef.setf(ios::fixed);
				 coutRef.precision(2);
				 coutRef << B.m_fruitsarray[i].m_name << ": " << B.m_fruitsarray[i].m_qty << "kg" << endl;
			 }
			 coutRef.unsetf(ios::right);
			 coutRef << "Price: " << B.m_priceOfBasket << endl;
		 }
		 return coutRef;
	 }

 }