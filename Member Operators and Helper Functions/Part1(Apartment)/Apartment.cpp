/*I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  13-11-2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
    Apartment::Apartment(int number, double balance)
    {

        if (number >= 1000 && number <= 9999
            && balance >= 0)
        {
            m_number = number;
            m_balance = balance;
        }
    }
    ostream& Apartment::display() const
    {
        if (*this)
        {
            cout.width(4);
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else
        {
            cout << "Invld|  Apartment   ";
        }
        return cout;
    }

    Apartment::operator bool() const
    {
        return(m_number >= 1000 && m_number <= 9999 && m_balance >= 0.0);
    }

    Apartment::operator int() const
    {
        return m_number;
    }

    Apartment::operator double() const
    {
        return m_balance;
    }

    bool Apartment::operator~() const
    {
        return m_balance < 0.00001;
    }

    Apartment& Apartment::operator=(const int right)
    {
        if (right >= 1000 && right <= 9999) 
        {
            m_number = right;
        }
        else 
        {
            m_number = -1;
            m_balance = 0.0;
        }
        return *this;

    }

    Apartment& Apartment::operator=(Apartment& B) // without & run!!!!!!!!
    {
        int tempNumber;
        double tempBalance;// temp variables for swapping (values of one object to another object)
        tempNumber = B.m_number; // 1             // by copying from net(stackoverflow)
        tempBalance = B.m_balance; // 1

        B.m_number = m_number; //0 
        B.m_balance = m_balance; //0

        m_number = tempNumber;
        m_balance = tempBalance;

        return *this;//reference of current obj returned
    }

    Apartment& Apartment::operator+=(const double rightBal)
    {
        if (m_number >= 1000 && m_number <= 9999 && m_balance >= 0.0 && rightBal > 0) {
            m_balance += rightBal;
        }
        return *this;
    }

    Apartment& Apartment::operator-=(const double rightBal)
    {
        if (m_number >= 1000 && m_number <= 9999 && m_balance >= 0.0 && rightBal > 0 && m_balance > rightBal) {
            m_balance -= rightBal;
        }
        return* this;
    }
    Apartment& Apartment::operator<<(Apartment& right)
    {
        if (m_number >= 1000 && m_number <= 9999 && m_balance >= 0.0)
        {
            if (this != &right && right.m_number >= 1000 && right.m_number <= 9999 && right.m_balance >= 0.0) 
            {
                m_balance += right.m_balance;
                right.m_balance = 0;//reset to zero for next one
            }
        }
        return *this;
    }
    Apartment& Apartment::operator>>(Apartment& one)
    {
        if (m_number >= 1000 && m_number <= 9999 && m_balance >= 0.0)
        {
            if (this != &one && one.m_number >= 1000 && one.m_number <= 9999 && one.m_balance >= 0.0)
            {
               one.m_balance += m_balance;
               m_balance = 0;
            }
        }
        return *this;
    }
   
    const double operator+(const Apartment& left, const Apartment& right)
    {
        double sum;
        if ((int(left) >= 1000 && int(left) <= 9999 && double(left) >= 0) && (int(right) >= 1000 && int(right) <= 9999 && double(right) >= 0))
        {
            sum =  double(left) + double(right);
        }
        return sum;
    }

   
    void operator+=(double& left, const Apartment& right)
    {
        if (int(right) >= 1000 && int(right) <= 9999 && left >= 0)
        {
            left += double(right);            
        }
    }

}

  