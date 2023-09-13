/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/17/2023
// Author:  Ching Wei Lai
// File:	Fish.cpp 
// 
// Last Updated 11/27/2022 by Jitesh Arora
// Version: 0.4 - Switch #DEFINE to const for fees
// 
// Description:
// Base class definition for a Pet 
////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Pet.h"
#include "Fish.h"

using namespace std;

namespace sdds {
	Fish::Fish(const char* name, int age) : Pet(name, age, COST_BASE) {}

	void Fish::feed() 
	{
		//invoking feed() on the base class
		Pet::feed(); 

		//if the fish is alive add the fish feeding fee to the total cost stored within the base class attribute.
		if (isAlive()) {
			addCharge(COST_FEED);
		}
	};

	void Fish::reSpawn() 
	{
		//Invoke reSpawn on the base class
		Pet::reSpawn();

		//Add the fish respawning fee to the total cost stored within the base class attribute
		addCharge(COST_REVIVE);

	};

	void Fish::operator++ (int num) 
	{
		//If the fish is alive calculate its daily health delta.
		if (isAlive()) {
			double healthDelta = 0;
			healthDelta += 0.20 * (getFeeds() - 1);

			//Add the delta to the health attribute in the base class
			applyHealthDelta(healthDelta);

			//Invoke operator++ on the base class
			Pet::operator++(num);
		}	   

	};

	Fish& Fish::operator=(const Fish& rhs) 
	{
		//create a Clone of this fish -> invoke operator= on the base class
		Pet::operator=(rhs);

		//add the cloning fee for a fish based on the fee schedule -> the amount being charged to the customer(stored within the base class)
		addCharge(COST_CREATE * 2.0);
		return *this;

	};

	
	// Global helper function 
	ostream& operator<<(ostream& os, Fish& F)
	{
		os << "** Generic Fish **" << endl;
		return F.outputData(os);
	}
}