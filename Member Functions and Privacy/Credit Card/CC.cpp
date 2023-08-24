#include "CC.h"
#include <iostream>

#include <iomanip> // included this!!!!!!!!! for cout << setfill('0') and setw(something)!!!!!!!!!!!! Setfill fills the preceings with
				   // what ever sepcified till the setw (which is width)
using namespace std;

namespace sdds
{

	void CC::set()
	{
		cardholderName = nullptr;
		CVV = 0;
		expiryM = 0;
		expiryY = 0;
		ccNumber = 0;
	}

	void CC::cleanUp()
	{
		delete[] cardholderName;
		set();
	}

	bool CC::isEmpty() const
	{
		if (cardholderName)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool CC::validate(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) const
	{

		if ((cc_name) && (strlen(cc_name) > 2))
		{

			if (cc_no >= 4000000000000000 && cc_no <= 4099999999999999)
			{

				if (cvv > 100 && cvv < 999)
				{

					if (expMon >= 1 && expMon <= 12)
					{

						if (expYear >= 22 && expYear <= 32)
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	void CC::prnNumber() const
	{
		int a = ccNumber / 1000000000000; // 4098
		cout << setfill('0') << setw(4) << a << " ";
		unsigned long long b = ccNumber % 1000000000000; // 645375646543

		int c = b / 100000000; // 6453
		if (c < 1000)
		{
			cout << setfill('0') << setw(4) << c << " ";
		}
		else
			cout << c << " ";
		unsigned long long d = ccNumber % 100000000; // 75646543
		// cout << d;
		int e = d / 10000; // 7564
		if (e < 1000)
		{
			cout << setfill('0') << setw(4) << e << " ";
		}
		else
			cout << e << " ";
		unsigned long long f = ccNumber % 10000; // 6543
		if (f < 1000)
		{
			cout << setfill('0') << setw(4) << f;
		}
		else
			cout << f;
	}

	void CC::set(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear)
	{
		cleanUp();
		if (validate(cc_name, cc_no, cvv, expMon, expYear))
		{
			cardholderName = new char[71];
			strcpy(cardholderName, cc_name);
			ccNumber = cc_no;
			CVV = cvv;
			expiryM = expMon;
			expiryY = expYear;
		}
	}

	bool CC::read()
	{
		cleanUp();

		char cardholdertemp[71] = "/0";
		short tempCVV;
		short tempexpiryM;
		short tempexpiryY;
		unsigned long long tempccNumber;

		cout << "Card holder name: ";
		cin.getline(cardholdertemp, 71);
		if (cin)
		{
			cout << "Credit card number: ";
			cin >> tempccNumber;
			if (cin)
			{
				cout << "Card Verification Value (CVV): ";
				cin >> tempCVV;
				if (cin)
				{
					cout << "Expiry month and year (MM/YY): ";
					cin >> tempexpiryM;
					cin.ignore(1, 'a') >> tempexpiryY;
					if (cin)
					{
						set(cardholdertemp, tempccNumber, tempCVV, tempexpiryM, tempexpiryY);
						if (tempccNumber >= 4000000000000000 && tempccNumber <= 4099999999999999)
						{
							cin.ignore(100000, '\n');
							return true;
						}
					}
				}
			}
		}
		cin.clear();
		cin.ignore(100000, '\n');
		return false;
	}

	// |  30 | Homer Simpson                  | 4089 0511 8229 9500 | 815 |  6/30 |
	void CC::display(int row) const
	{
		if (cardholderName && cardholderName[0])
		{
			if (row > 0)
			{
				cout << setfill(' ');
				cout << "|";
				cout.setf(ios::right);
				cout.width(4);
				cout << row;
				cout.unsetf(ios::right);
				cout << " | ";
				cout.setf(ios::left);

				// cout << cardholderName;
				// printf("%-30s", cardholderName);

				if (strlen(cardholderName) > 30)
				{
					for (int i = 0; i < 30; i++)
					{
						cout << cardholderName[i]; // !!!!!!!!!!!!! ask for efficient method please !!!!!!!!!
					}
				}
				else
				{
					cout << setw(30) << cardholderName;
				}
				cout << " | ";
				cout.unsetf(ios::left);
				prnNumber();
				cout << setfill(' ');
				cout << " | " << CVV << " | ";
				cout.setf(ios::right);
				cout.width(2);
				cout << expiryM << "/" << expiryY << " |" << endl;
				cout.unsetf(ios::right);
			}

			if (row <= 0)
			{
				cout << "Name: " << cardholderName << endl;
				cout << "Creditcard No: ";
				prnNumber();
				cout << endl;
				cout << "Card Verification Value: " << CVV << endl;
				cout << "Expiry Date: " << expiryM << "/" << expiryY << endl;
			}
		}
		else
		{
			cout << "Invalid Credit Card Record" << endl;
		}
	}
}