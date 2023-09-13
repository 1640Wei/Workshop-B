/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Toys.h
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
#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_
#define MAX_TNAME 31

namespace sdds {

   class Toys {
   private:
      char m_tname[MAX_TNAME];
      int m_sku; 
      double m_price;
      int m_age;
      bool m_onSale;
   public:
      Toys();
      void addToys(const char* tname, int sku, double price, int age);
      void isSale(bool sale);
      void calSale();
      void display()const;
      bool checkSale()const;
      int sku()const;
   };
}

#endif // !SDDS_TOYS_H_
