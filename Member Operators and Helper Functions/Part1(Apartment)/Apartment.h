/*I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  13-11-2022
*/

#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
    class Apartment
    {
        int m_number = -1;
        double m_balance = 0.0;

    public:

        Apartment(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator~()const;
        Apartment& operator=(const int right);
        Apartment& operator=(Apartment& B);
        Apartment& operator+=(const double rightBal);
        Apartment& operator-=(const double rightBal);
        Apartment& operator<<(Apartment& right);
        Apartment& operator>>(Apartment& one);
    };
    const double operator+(const Apartment& left, const Apartment& right);
    void operator+=(double& left, const Apartment& right);

}
#endif // SDDS_APARTMENT_H_