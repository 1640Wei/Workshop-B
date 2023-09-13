/////////////////////////////////////////////////////////
// Workshop 8: Virtual functions and Abstract base classes
// 
// Date:	03/22/2023
// Author:  Ching Wei Lai
// File:	Media.cpp
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
#include "Media.h"

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& ostr, const Media& R) {
		return R.play(ostr);
	}
	istream& operator>>(istream& istr, Media& R) {
		R.load(istr);
		return istr;
		//reutnr R.load(istr);
	}
}