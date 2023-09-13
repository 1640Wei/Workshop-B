/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Toys.cpp
// Version 1.0
// Date	2023/02/07
// Author Ching Wei Lai
// Description
// Tests Store module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Toys.h"
#include "Store.h"

using namespace std;
namespace sdds {

   Toys::Toys() {

      //constructor: set the store to an empty state
      m_tname[0] = '\0';
      m_sku = 0;
      m_price = 0.0;
      m_age = 0;
      m_onSale = false;
   }

   void Toys::addToys(const char* tname, int sku, double price, int age) {

      //checking the validity, this method will set the received values to the appropriate data members.
      if (tname != nullptr && strlen(tname) < MAX_TNAME && sku > 9999999 && sku < 100000000 && price > 0.0) {
         strcpy(m_tname, tname);
         m_sku = sku;
         m_price = price;
         m_age = age;
      }
   }

   void Toys::isSale(bool sale) {

      //It will assign the received value to the data member m_onSale.
      m_onSale = sale;
   }

   void Toys::calSale() {

      //It will decrease the toys price to 20% then the original price.
      m_price = m_price - (m_price * 0.2);
   }

   void Toys::display() const {

      //If a Toy object is valid, set the format
      if (m_tname[0] != '\0') {
         cout.setf(ios::left);
         cout.width(15);
         cout << m_tname;
         cout.unsetf(ios::left);
         cout.setf(ios::right);
         cout.width(10);
         cout << m_sku;
         cout.width(6);
         cout << m_age;
         cout.unsetf(ios::right);
         cout.setf(ios::fixed);
         cout.width(12);
         cout.precision(2);
         cout << m_price;
         cout.unsetf(ios::fixed);

         //If the toy is on sale it will print "On Sale" with width 10. 
         if (m_onSale) {
            cout.width(10);
            cout << "On Sale" << ' ' << endl;
         }
         //Otherwise, print empty spaces with width 8.
         else {
            cout.width(8);
            cout << " " << endl;
         }
      }
      //otherwise prints, "Invalid Toy".
      else {
         cout << "Invalid Toy" << endl;
      }
   }
   bool Toys::checkSale() const {
      return m_onSale;
   }

   int Toys::sku() const {
      return m_sku;
   }
}