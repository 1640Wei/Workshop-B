/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/17/2023
// Author:  Ching Wei Lai
// File:	Dog.h 
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Base class definition for a Pet 
////////////////////////////////////////////////////////
#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include <iostream>
#include "Pet.h"

namespace sdds
{
   class Dog : public Pet
   {
      const double COST_BASE = 1.00;   // Fee: Initial purchase
      const double COST_CREATE = 4.00;   // Fee: Create cost
      const double COST_FEED = 0.25;   // Fee: For each feeding
      const double COST_REVIVE = 1.00;   // Fee: Respawn if perished

      int        m_numWalks; // track the number of walks

   public:
      Dog();
      Dog(const char* name, int age = 0);
      void feed();
      void reSpawn();
      void walk();
      void operator++ (int num);
      Dog& operator=(const Dog& rhs);
      std::ostream& outputData(std::ostream& os);
   };
   //helper function
   std::ostream& operator<<(std::ostream& os, Dog& dog);
}

#endif