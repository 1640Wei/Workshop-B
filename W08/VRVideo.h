/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	VRVideo.h
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Virtual functions and Abstract base classes
////////////////////////////////////////////////////////
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include <iostream>
#include "Video.h"

namespace sdds {
   class VRVideo : public Video{
      char* m_equipment;
   public:

      //Default(no argument) constructor
      VRVideo();

      //Two argument constructor
      VRVideo(int length, const char* equi);

      //Destructor
      ~VRVideo();

      //load -> overrides the load function of the base class as follows.
      void load(std::istream& is) override;

      //play -> This function overrides the play function of the base class.
      std::ostream& play(std::ostream& os) const;
   };
}

#endif