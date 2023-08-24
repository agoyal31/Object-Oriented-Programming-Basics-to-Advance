#ifndef CC_H
#define CC_H

#include <iostream>
#include "Utils.h"

namespace sdds 
{
    class CC {

        char* cardholderName;
        short CVV;
        short expiryM;
        short expiryY;
        unsigned long long ccNumber;

        bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
        void prnNumber()const;

    public:
        void set();
        void cleanUp();
        bool isEmpty()const;
        void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
        bool read();
        void display(int row = 0) const;
    };
}

#endif // !CC_H
