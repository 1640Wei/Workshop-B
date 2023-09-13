/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	Media.h
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Virtual functions and Abstract base classes
////////////////////////////////////////////////////////
#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>

namespace sdds {
   class Media {
   public:
      //two Pure virtual functions
      virtual std::ostream& play(std::ostream& os) const = 0;
      virtual void load(std::istream& is) = 0;
      //destructor -> Create a virtual empty destructor for the Media interface.
      virtual ~Media() {};
   };
   //helper functions
   std::ostream& operator<<(std::ostream& ostr, const Media& R);
   std::istream& operator>>(std::istream& istr, Media& R);
}
#endif