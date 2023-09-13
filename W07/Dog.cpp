/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/17/2023
// Author:  Ching Wei Lai
// File:	Dog.cpp
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
#include "Dog.h"

using namespace std;

namespace sdds {

	Dog::Dog() : Pet()
	{
		m_numWalks = 0;
	}

	Dog::Dog(const char* name, int age) : Pet(name, age, COST_BASE)
	{
		//initialize any new attributes for the Dog class.
		m_numWalks = 0;
	}

	void Dog::operator++ (int num) 
	{
		
		//If the dog is alive calculate its daily health delta. Dogs require:
			if (isAlive()) {
				double healthDelta = 0;
				healthDelta += 0.15 * (getHugs() - 1);
				healthDelta += 0.10 * (getFeeds() - 2);
				healthDelta += 0.10 * (getGrooms() - 1);
				healthDelta += 0.20 * (m_numWalks - 2);

				//Add the delta to the health attribute in the base class
				applyHealthDelta(healthDelta);

				//	//Invoke operator++ on the base class
				Pet::operator++(num);
				m_numWalks = 0;
			}
	};

	Dog& Dog::operator=(const Dog& rhs) 
	{
		Pet::operator=(rhs);
		m_numWalks = rhs.m_numWalks;
		addCharge(COST_CREATE * 2.0);

		return *this;
	};

	void Dog::feed()
	{
		Pet::feed();
		if (isAlive()) {
			addCharge(COST_FEED);
		}
	}

	void Dog::walk() 
	{
		//if the dog is alive.
		if (isAlive()) {
			m_numWalks += 1; // add the number of walk
		}
	};

	void Dog::reSpawn() 
	{
		Pet::reSpawn();
		m_numWalks = 0;  //reset the number of walks for this dog to 0.
		addCharge(COST_REVIVE);
	};

	ostream& Dog::outputData(std::ostream& os)
	{
		os << "   Walks: " << m_numWalks << endl;
		return Pet::outputData(os);
	}

	ostream& operator<<(ostream& os, Dog& dog)
	{
		os << "** Generic Dog **" << endl;
		return dog.outputData(os);
	}
}