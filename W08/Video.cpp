/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	Video.cpp
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
#include "Video.h"


using namespace std;
namespace sdds {

   //returns the value of the m_length member variable
   int Video::get() const 
   {
      return m_length;
   };

   //Default(no argument) constructor
   Video::Video() 
   {
      m_length = 0;
   };

   //One argument constructor
   Video::Video(int length) 
   {
      //Set the m_length value to the incoming argument
      m_length = length < 0 ? 0 : length;
   };

   //load
   void Video::load(std::istream& is)
   {
      //Reads the length from the istream and sets the data member
      is >> m_length;
      char c;
      is >> c;
   };

   void Video::set(int length) {
      m_length = 0;
   };
}