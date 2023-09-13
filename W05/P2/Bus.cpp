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
#include <iostream>
#include "Bus.h"
using namespace std;
namespace sdds 
{
   
   //constructor
   Bus::Bus(int numSeats, int numPass)
   {
      //the number of seats --> multiple of 2
      //the number of seats --> between 10 and 40 
      //the number of passengers --> between 0 and the number of seats.
      if (numSeats % 2 != 0 || 
         (numSeats < 10 || numSeats > 40) ||
         (numPass < 0 || numPass > numSeats))
      {
         m_noOfSeat = -1;
      }
      else
      {
         m_noOfSeat = numSeats;
         m_noOfPass = numPass;
      }
   }

   //destructor
   Bus::~Bus()
   {
      m_noOfSeat = 20;
      m_noOfPass = 0;
   }

   ostream& Bus::display(ostream& ostr) const
   {
      // no seat for passenger --> out of service
      if (m_noOfSeat <= 0)
      {
         ostr << "Out of service!" << endl;
      }
      else
      {
         //A bus can be drawn on the screen by getting inserted into the cout object
         drawBus(m_noOfSeat, m_noOfPass, ostr);

         // on a new line the total fare for the bus, price --> two decimal places
         ostr << "Total Fare Price: ";
         ostr.setf(ios::fixed);
         ostr.precision(2);
         ostr << double(*this) << endl;
      }
      return ostr;
   }

   // draw a bus --> booboo~
   void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const
   {
      int i, p;
      ostr.fill('_');
      ostr.width((seats / 2) * 3 + 4);
      ostr << "_";
      ostr << endl
         << "| ";
      for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]")
         ;
      ostr << "|_\\_" << endl;
      ostr << "| ";
      ostr.fill(' ');
      ostr.width(((seats / 2) * 3 - 14) / 2);
      ostr << " "
         << "Seneca College";
      ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
      ostr << " "
         << "    )" << endl;
      ostr << "`---OO";
      ostr.fill('-');
      ostr.width((seats / 2) * 3 - 5);
      ostr << "-"
         << "O---'" << endl;
   }

   //The specifications of a bus can be read from the console by extracting a Bus object from istream (cin).
   istream& Bus::read(istream& istr)
   {
      //read an integer into the number of seats
      istr >> m_noOfSeat;

      //ignore the next character.
      istr.ignore();

      //read an integer into the number of passengers.
      istr >> m_noOfPass;
      istr.ignore();

      // any seat for passenger?  if it fails --> out of service
      if (m_noOfSeat % 2 != 0 || 
         (m_noOfSeat < 10 || m_noOfSeat > 40) ||
         (m_noOfPass < 0 || m_noOfPass > m_noOfSeat))
      {
         m_noOfSeat = -1;
      }
      return istr;
   }

   Bus::operator bool() const
   {
      //returns true if the number of seats is greater than zero. 
      return m_noOfSeat > 0;
   }

   Bus::operator int() const
   {
      // the number of passengers if the Bus is in service otherwise, it will return -1
      return (bool(*this) ? m_noOfPass : -1);
   }

   Bus::operator double() const
   {
      //returns the total fare of the bus --> number of passengers * the price of a ticket,  or out of servie --> -1.0
      return (bool(*this) ? m_noOfPass * busTicket : -1);
   }

   bool Bus::operator--()
   {
      bool result = true;
      //If the bus is out of service or empty --> returns false.
      if (!bool(*this) || m_noOfPass == 0)
      {
         result = false;
      }
      else
      {
         //it will reduce the number of passengers by one and returns true;
         m_noOfPass -= 1;
         result = true;
      }
      return result;
   }

   bool Bus::operator++()
   {
      bool result = true;
      //If the bus is out of service or full --> returns false.Otherwise,
      if (!bool(*this) || m_noOfPass >= m_noOfSeat)
      {
         result = false;
      }
      else
      {
         // it will increase the number of passengers by oneand returns true;
         m_noOfPass += 1;
         result = true;
      }
      return result;
   }

   //Works exactly like the prefix operator--
   bool Bus::operator--(int)
   {
      bool result = true;
      if (!bool(*this) || m_noOfPass == 0)
      {
         result = false;
      }
      else
      {
         m_noOfPass -= 1;
         result = true;
      }
      return result;
   }

   //Works exactly like the prefix opeator++
   bool Bus::operator++(int)
   {
      bool result = true;
      if (!bool(*this) || m_noOfPass >= m_noOfSeat)
      {
         result = false;
      }
      else
      {
         m_noOfPass += 1;
         result = true;
      }
      return result;
   }

   Bus& Bus::operator=(int value)
   {
      m_noOfPass = value;

      //If the number of passengers exceeds the number of seats, the bus will be out of service.
      if (m_noOfPass > m_noOfSeat)
      {
         m_noOfSeat = -1;
      }
      return *this;
   }

   Bus& Bus::operator+=(int value)
   {
      //If the number of passengers not exceeds the number of seats and in the service
      if (bool(*this) && m_noOfPass < m_noOfSeat)
      {
         //Adds the integer value to the number of passengers
         m_noOfPass += value;
      }
      else
      {
         m_noOfSeat = -1;
      }
      
      return *this;
   }

   Bus& Bus::operator+=(Bus& right)
   {
      //If both busses are in service --> move the passengers from one bus (right) to another (left). 
      //If there is not enough seat in the left bus --> the rest of the passengers remain in the right bus.
      int empty = m_noOfSeat - m_noOfPass;
      if (bool(*this) && bool(right))
      {
         if (empty < right.m_noOfPass)
         {
            right.m_noOfPass -= empty;
            m_noOfPass = m_noOfSeat;
         }
         else
         {
            right.m_noOfPass = 0;
            m_noOfPass += right.m_noOfPass;
         }
      }
      return *this;
   }

   bool Bus::operator==(const Bus& right) const
   {
      bool result = true;
      //If both buses are in service and the numbers of passengers are the same --> returns true; otherwise --> return false.
      if (bool(*this) && bool(right))
      {
         if (m_noOfPass == right.m_noOfPass)
         {
            result = true;
         }
         else
         {
            result = false;
         }
      }
      return result;
   }

   int operator+(int left, const Bus& right)
   {
      //If the bus is in service --> return the sum of the number and the number of passengers on the bus. 
      //Otherwise, the integer number is returned as if the number of passengers on the bus was 0.
      int sum = 0;
      if (bool(right))
      {
         sum = left + int(right);
      }
      else {
         sum = left;
      }
      return sum;
   }

   ostream& operator<<(ostream& ostr, const Bus& right)
   {
      right.display(ostr);
      return ostr;
   }

   istream& operator>>(istream& istr, Bus& right)
   {
      right.read(istr);
      return istr;
   }
}
