/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:02/12/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef _SDDS_ITEM_H_
#define _SDDS_ITEM_H_
namespace sdds {

	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};


	class Basket {
	private:
        
		Fruit* m_fruitsarray{};
		int m_sizeofArray{};
		double m_priceOfBasket{};

	public:

		Basket();
		Basket(Fruit* arrayofObject, int sizerecieved, double basketPrice);
		Basket(const Basket& B);
		Basket& operator=(const Basket& B);
		virtual ~Basket();
		void setPrice(double price);
		operator bool()const;
		Basket& operator+=(Fruit F);

		friend std::ostream& operator<<(std::ostream& coutRef, const Basket& B);
	};


}
#endif