/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	Animation.h
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Virtual functions and Abstract base classes 
////////////////////////////////////////////////////////
#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include "Video.h"

namespace sdds {
   class Animation : public Video {
      int m_dimension;

   public:
      //Default(no argument) constructor
      Animation();

      //Two argument constructor
      Animation(int length,int dimension);

      //load -> overrides the load function of the base class as follows
      void load(std::istream& is);

      //play -> overrides the play function of the base class
      std::ostream& play(std::ostream& os) const;

      bool isEmpty() const;
   };
}

#endif