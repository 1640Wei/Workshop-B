/***********************************************************************
// OOP244 Workshop 4 Part2: Constructor, Destructor and the current object
// File main.cpp
// Version 1.0
// Date	2023/01
// Author Ching Wei Lai
// Description
// Tests NameTag module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
namespace sdds
{
   class NameTag {
   private:
      char* m_name; //The name should be kept dynamically and the maximum of 40 characters
      int m_extension;  //5 digit extension number

   public:
      NameTag();
      ~NameTag();
      NameTag(const char* name);
      NameTag(const char* name, int num);
      void print();
      NameTag& read();
   };
}
#endif