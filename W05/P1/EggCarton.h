/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.h
// Version 1.0
// Date	2023/02
// Author Ching Wei Lai
// Description
// Tests EggCarton module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>
using namespace std;
namespace sdds
{
   const int RegularEggWieght = 50;
   const int JumboEggWieght = 75;
   class EggCarton
   {
      int m_size;
      int m_noOfEgg;
      bool m_jumboSize;
      ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const;
      EggCarton& setBroken(int size, int noOfEggs);

   public:
      EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
      ~EggCarton();
      ostream& display(ostream& ostr = cout) const;
      istream& read(istream& istr = cin);
      operator bool() const;
      operator int() const;
      operator double() const;

      //Unary Operator overloads:
      EggCarton& operator--();
      EggCarton& operator++();
      EggCarton operator--(int);
      EggCarton operator++(int);

      //Binary Member Operators
      EggCarton& operator=(int value);
      EggCarton& operator+=(int value);
      EggCarton& operator+=(EggCarton& right);
      bool operator==(const EggCarton& right) const;
   };

   //Helper Binary Operator Overload
   int operator+(int left, const EggCarton& right);
   ostream& operator<<(ostream& ostr, const EggCarton& right);
   istream& operator>>(istream& istr, EggCarton& right);
}
#endif