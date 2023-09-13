/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/17/2023
// Author:  Ching Wei Lai
// File:	Fish.h 
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Base class definition for a Pet 
////////////////////////////////////////////////////////
#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include <iostream>
#include "Pet.h"

namespace sdds
{
   class Fish : public Pet
   {
      const double COST_BASE = 1.00;   // Fee: Initial purchase
      const double COST_CREATE = 1.00;   // Fee: Create cost
      const double COST_FEED = 0.10;   // Fee: For each feeding
      const double COST_REVIVE = 0.50;   // Fee: Respawn if perished

   public:
      Fish(const char* name, int age = 0);
      void feed();
      void reSpawn();
      void operator++ (int num);
      Fish& operator=(const Fish& rhs);
   };
   //helper function
   std::ostream& operator<<(std::ostream& os, Fish& fish);
}

#endif