/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Store.h
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
#ifndef SDDS_STORES_H_
#define SDDS_STORES_H_
#define MAX_SNAME 31   
#define MAX_NUM_TOYS 10 
#include "Toys.h"

namespace sdds{

   class Store {
   private:
      char m_sName[MAX_SNAME];
      int m_noOfToys;
      int m_addToys;
      Toys m_toy[MAX_NUM_TOYS];
   public:
      void setStore(const char* sName, int no);
      void setToys(const char* tname, int sku, double price, int age);
      void display()const;
      void find(int sku);
      void setEmpty();
   };
}

#endif // !SDDS_STORES_H_
