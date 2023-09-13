/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.cpp
// Version 1.0
// Date	2023/02
// Author Ching Wei Lai
// Description
// Tests the Bus module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>
using namespace std;
namespace sdds 
{

   const double busTicket = 125.34; //The price of a bus ticket is $125.34

   class Bus 
   {
      int m_noOfSeat;
      int m_noOfPass;
      void drawBus(int seats, int noOfPassengers, ostream& ostr) const;

   public:
      ostream& display(ostream& ostr = cout) const;
      Bus(int m_noOfSeat = 20, int numPass = 0);   //default, a bus has 20 seats and no passengers.
      ~Bus();
      istream& read(istream& istr = cin);

      //Type Conversion Operator overloads
      operator bool() const;
      operator int() const;
      operator double() const;

      //Unary Operator overloads:
      //prefix operator--
      bool operator--(); 
      //prefix operator++
      bool operator++();
      //postfix operator--
      bool operator--(int);
      //postfix operator++
      bool operator++(int);

      //Binary Member Operators
      Bus& operator=(int value);
      Bus& operator+=(int value);
      Bus& operator+=(Bus& right);
      bool operator==(const Bus& right) const;
   };
   //Helper Binary Operator Overload
   int operator+(int left, const Bus& right);
   ostream& operator<<(ostream& ostr, const Bus& right);
   istream& operator>>(istream& istr, Bus& right);
}
#endif