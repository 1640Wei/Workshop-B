/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	VRVideo.cpp
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
#include "VRVideo.h"


using namespace std;

namespace sdds {
   VRVideo::VRVideo() : Video()
   {
      m_equipment = nullptr;
   };


   //Two argument constructorn
   VRVideo::VRVideo(int length, const char* equi) : Video(length)
   {

      //If either the length or the equipment name is invalid -> return empty ?????????????????????
      if (equi == nullptr || strlen(equi) == 0) {
         m_equipment = nullptr;
         this->set(0);
      }
      else {
         //copy of the name of equipment is kept Dynamically by the m_equipment
         m_equipment = new char[strlen(equi) + 1];
         strcpy(m_equipment, equi);
      }

   };

   //Destructor -> Deallocates the m_equipment dynamic C-string.
   VRVideo::~VRVideo() 
   {
      delete[] m_equipment;
      m_equipment = nullptr;
   };

   //load -> overrides the load function of the base class as follows.
   void VRVideo::load(std::istream& is) 
   {
      //call the load function
      Video::load(is);


      //reads the C-string until newline (\n)and ignores newline -> m_equipment is deallocated before overwriting the newly allocated memory
      char string[256];
      is.getline(string, 256, '\n');
      delete[] m_equipment;
      if (string[0] != '\0') {
         m_equipment = new char[strlen(string) + 1];
         strcpy(m_equipment, string);
      }
      else {
         m_equipment = nullptr;
      }
      if (this->get() < 0 || this->m_equipment == nullptr) {

         this->set(0);
         delete[] m_equipment;
         m_equipment = nullptr;
      }

   };

   //play -> This function overrides the play function of the base class.
   ostream& VRVideo::play(std::ostream& os) const
   {
      if (get() == 0) {
         return os;
      }
      //If the VRVideo is not empty, 
      if (m_equipment != nullptr) {
         //-> print the VRVideo requires followed by m_equipement and then go to the new line
         os << "VRVideo requires " << m_equipment << endl;
         
      }
      //prints Video Length = followed by get() of the base
      os << "Video Length = " << get();
      return os;
   };
}