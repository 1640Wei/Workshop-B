/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	Animation.cpp
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Virtual functions and Abstract base classes
////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Animation.h"

using namespace std;

namespace sdds {

   Animation::Animation() : Video(), m_dimension(0) {}

   //Two argument constructor
   Animation::Animation(int length, int dimension) : Video(length) 
   {
      if (dimension != 2 && dimension != 3) {
         m_dimension = 0;
         this->set(0);
      }
      else {
         m_dimension = dimension;
      }
   };

   //load -> overrides the load function of the base class as follows
   void Animation::load(std::istream& is) 
   {
      // call the load function
      Video::load(is);

      //read the value of the m_dimention from the istream , ignores the rest of the characters up to and including ('\n').
      is >> m_dimension;
      is.ignore(10000, '\n');
      if (m_dimension != 2 && m_dimension != 3) {
         this->set(0);
      }
   };

   //play -> overrides the play function of the base class
   ostream& Animation::play(ostream& os) const
   {
      //Animation is not empty ->  print Animation is in followed by m_dimension followed by -D .
      if (!isEmpty()) {
         os << "Animation is in " << m_dimension << "-D" << endl;

            //prints Video Length = followed by get().
         os << "Video Length = " << get();
      }
      return os;
   };

   bool Animation::isEmpty() const {
      return (get() == 0 || (m_dimension != 2 && m_dimension != 3));
   }
}