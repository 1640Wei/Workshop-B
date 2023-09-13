/***********************************************************************
// OOP244 Workshop 10:
// File	Student.h
// Version 1.0
// Date	Winter of 2023
// Author	Ching Wei Lai
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_VALIDATE_H_
#define SDDS_VALIDATE_H_
namespace sict {
   template<typename T>
   bool validate(const T& min, const T* testValues, const size_t no, bool* results) {
      bool valid = true;
      for (size_t i = 0; i < no; i++) {
         results[i] = (testValues[i] >= min);
         valid = valid && results[i];
      }
      return valid;
   }
}
#endif
