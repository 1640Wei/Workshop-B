/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	Video.h
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Virtual functions and Abstract base classes
////////////////////////////////////////////////////////
#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include <iostream>
#include "Media.h"

namespace sdds {
   class Video : public Media {
      int m_length; //the length of the video

   protected:
      int get() const;

   public:
      //Default(no argument) constructor
      Video();

      //One argument constructor
      Video(int length);

      //deleted actions -> copy constructor and assignment operator are deleted
      Video(const Video& V) = delete;
      void operator=(const Video& V) = delete;

      void load(std::istream& is) override; 
      void set(int length);
   };
}

#endif