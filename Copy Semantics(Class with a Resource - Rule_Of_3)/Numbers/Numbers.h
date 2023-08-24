#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
      Numbers& sort(bool ascending);
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& toCopyFrom); //copy constructor copies from object of the same type.
      Numbers& operator=(const Numbers& right);
      double average()const;
      double max()const;
      double min()const;
      Numbers operator-()const;
      Numbers operator+()const;
      double numberCount()const;
      bool load();
      Numbers& save();
      Numbers& operator+=(double value);
      std::ostream& display(std::ostream& ostr) const;
      ~Numbers();
   };

   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_