/*I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  17-11-2022
*/

#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_

#include <iostream>

namespace sdds {

    class Seat
    {
        char* m_name;
        int m_rowNum;
        char m_letterNum;

        bool validate(int row, char letter)const;

        Seat& alAndCp(const char* str);

    public:

        Seat& reset();
        bool isEmpty() const;
        bool assigned() const;
        Seat();
        Seat(const char* passengerName);
        Seat(const char* passengerName, int row, char letter);
        Seat& set(int row, char letter);
        int row()const;
        char letter()const;
        const char* passenger()const;
        std::ostream& display(std::ostream& coutRef = std::cout)const;
        std::istream& read(std::istream& cinRef = std::cin);
        ~Seat();

    };
}
#endif // !SDDS_SEAT_H_