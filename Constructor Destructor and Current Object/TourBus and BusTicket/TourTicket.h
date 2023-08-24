/***********************************************************************
// OOP244 Workshop 4 p2: TourTicket Module
//
// File	TourTicket.h
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*I have done all the coding by myselfand only copied the code that my professor provided to complete my
workshops and assignments.
Name        -  Avni Goyal
Seneca email-  agoyal31@myseneca.ca
Seneca ID   -  166795211
Date        -  19-11-2022
*/
#ifndef SDDS_TOURTICKET_H_
#define SDDS_TOURTICKET_H_
#include <iostream>
namespace sdds 
{
   class TourTicket 
   {
      char m_name[41];
      int m_ticketNumber;
      void copyName(const char* str);
   public:
      TourTicket();
      TourTicket& issue(const char* passengerName);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      bool valid()const;
   };
}
#endif // !SDDS_TOURTICKET_H_


