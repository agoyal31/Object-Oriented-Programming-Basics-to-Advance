#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }

    Numbers::Numbers(const Numbers& toCopyFrom)
    {
        setEmpty();
        m_isOriginal = false;
        *this = toCopyFrom; // calls the copy assignment operator
    }

    Numbers& Numbers::operator=(const Numbers& right)
    {
        if (this != &right) {
            delete[] m_numbers;
           //  setEmpty(); // this was the issue for memory leak ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!@@@@!!!
            m_numbers = new double[right.m_numCount];
            for (int i = 0; i < right.m_numCount; i++) {
                m_numbers[i] = right.m_numbers[i];
            }
            m_isOriginal = false;
            m_numCount = right.m_numCount;
        }
        return *this;
    }

    Numbers::~Numbers() {
        save();
        deallocate();
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::deallocate() {
        delete[] m_filename;
        delete[] m_numbers;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    Numbers& Numbers::sort(bool ascending)
    {
        if (ascending == true) {
            int i, j;
            double temp;

            for (i = 0; i < m_numCount; i++) {
                for (j = i + 1; j < m_numCount; j++) {
                    if (m_numbers[j] < m_numbers[i]) {

                        temp = m_numbers[j];
                        m_numbers[j] = m_numbers[i];
                        m_numbers[i] = temp;

                    }
                }
            }
        }

        else {
            int i, j;
            double temp;
            for (i = 0; i < m_numCount; i++) {
                for (j = i + 1; j < m_numCount; j++) {
                    if (m_numbers[j] > m_numbers[i]) {

                        temp = m_numbers[j];
                        m_numbers[j] = m_numbers[i];
                        m_numbers[i] = temp;

                    }
                }
            }
        }
        return *this;
    }


   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }


   Numbers Numbers::operator-() const
   {
       Numbers A(*this);
       A.sort(false);
       return A;
   }

   Numbers Numbers::operator+() const
   {
       Numbers A(*this);
       A.sort(true);
       return A;
   }

   double Numbers::numberCount()const
   {
       char temp;
       double countN = 0;

       ifstream f(m_filename);
       do{
           f.get(temp);
           if (f && temp == '\n') {
               countN++;
           }
       } while (f);

       return countN;
   }

   bool Numbers::load()
   {
       int start = 0;
       bool value = false;

       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream f(m_filename);
           do 
           {
               f >> m_numbers[start];

               if (f)
               {
                   start++;
               }
           } while (f);

           if (start == m_numCount) {
               value = true;
           }
       }
       return value;
   }

   Numbers& Numbers::save()
   {
       int i = 0;

       if (m_isOriginal == true && !isEmpty()) {
           ofstream r(m_filename);
           r.setf(ios::fixed);
           r.precision(2);

           while (i < m_numCount) {
               r << m_numbers[i] << endl;
               i++;
           }
       }
       return *this;
   }

   Numbers& Numbers::operator+=(double value)
   {
       int m_newnumCount = m_numCount + 1;
       double* m_numbersNew;
       m_numbersNew = new double[m_newnumCount];
       for (int i = 0; i < m_numCount; i++) {
           m_numbersNew[i] = m_numbers[i];
       }
       m_numbersNew[m_newnumCount - 1] = value;
       delete[] m_numbers;
       m_numbers = m_numbersNew;
       m_numCount++;

       return *this;
   }

   ostream& Numbers::display(ostream& ostr) const
   {
       if (isEmpty()) {
           ostr << "Empty list";
       }

       else {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount; i++) {
               ostr.setf(ios::fixed);
               ostr.precision(2);
               ostr << m_numbers[i];
               if (i < m_numCount-1) {
                   ostr << ", ";
               }
               else {
                   ostr << "";
               }

           }
           ostr << "\n-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average:         " << average() << endl;
           ostr << "=========================";

       }
       return ostr;
   }

   double Numbers::max() const {
      double maxVal = 0.0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   ostream& operator<<(ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N)
   {
       double temp;
       istr >> temp;
       if (istr) {
           N += temp;
       }
       return istr;
   }
}
