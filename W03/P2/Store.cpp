/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Store.cpp
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
#include "Store.h"

using namespace std;

namespace sdds{

   void Store::setStore(const char* sName, int no) {

      //set the store into an empty state. 
      setEmpty();

      //valid values, store it.  invalid values, set the values to an empty state.
      if (sName != nullptr && strlen(sName) < MAX_SNAME && no > 0 && no < MAX_NUM_TOYS) {
         strcpy(m_sName, sName);
         m_noOfToys = no;
      }
      else {
         setEmpty();
      }
   }

   void Store::setToys(const char* tname, int sku, double price, int age) {

      //Toys will be added until num of added toys is less than m_noOfToys
      if (m_addToys < m_noOfToys) {

         //add the toys one at a time to the m_toy array
         m_toy[m_addToys].addToys(tname, sku, price, age);

         //track of the number of toys added
         m_addToys++;
      }
   }

   void Store::display()const {

      //If a Store object is valid, set the format
      if (m_sName[0] != '\0') {
         cout.fill('*');
         cout.width(60);
         cout << '*' << endl;
         cout << m_sName << endl;
         cout.fill('*');
         cout.width(60);
         cout << '*' << endl;
         cout << "list of the toys" << endl;
         cout.width(30);
         cout.fill(' ');
         cout << "SKU";
         cout.width(10);
         cout << "Age";
         cout.width(11);
         cout << "Price";
         cout.width(10);
         cout << "Sale" << endl;
         for (int i = 0; i < m_addToys; i++) {
            cout << "Toy[" << i + 1 << "] :";
            m_toy[i].display();
         }
      }
      //otherwise prints, "Invalid Store" then a new line.
      else {
         cout << "Invalid Store" << endl;
      }

   }
   
   void Store::find(int sku) {

      //This method will go through the arrays of toys. Use for loop
      for (int i = 0; i < m_addToys; i++) {
         if (sku == m_toy[i].sku() && !m_toy[i].checkSale()){

            //If the number matches then it will pass true to the appropriate Toys method.
            m_toy[i].isSale(true);

            //it will call the calSale() of the toys class to know the sale value.
            m_toy[i].calSale();
         }
      }
   }

   void Store::setEmpty() {

      //set the store to an empty state
      m_sName[0] = '\0';
      m_noOfToys = 0;
      m_addToys = 0;

      //array of toys, use a for loop to set it to an empty state
      for (int i = 0; i < MAX_NUM_TOYS; i++) {
         m_toy[i] = Toys();
      }
   }

}