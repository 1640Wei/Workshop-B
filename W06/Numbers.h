/***********************************************************************
// OOP244 Workshop 6 Part1: Classes with Resource
// File Numbers.h
// Version 1.0
// Date	2023/02
// Author Ching Wei Lai
// Description
// Tests Numbers module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_collection{};
      char m_filename[255];
      int m_collectionSize;
      bool m_originalFlag;
      bool m_addedFlag;    
      unsigned int countLines(const char* filename); 
      void sort(double* collectionPtr, unsigned int size); 
      bool isEmpty()const; 
      void setEmpty(); 
      bool load();
      void save();
      double max()const;
      double min()const;
      double average()const;
   public:
      Numbers();
      Numbers(const char* filename); 
      ~Numbers();
      Numbers(const Numbers& R);
      Numbers& operator=(const Numbers& R);
      operator bool() const;
      void sort();
      Numbers& operator+=(const double dou);
      std::ostream& display(std::ostream& ostr)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

