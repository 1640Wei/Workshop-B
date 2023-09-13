/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Tools.cpp
// Version 1.1
// Date   Winter 2023
// Ching Wei Lai
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ching Wei Lai   23-01-29       reordered user's tweets report
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds {
   void strCpy(char* str1, const char* str2) {
      while(*str2) {
         *str1++ = *str2++;
      }
      *str1 = 0;
   }
}
