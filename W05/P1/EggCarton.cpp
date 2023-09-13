/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.cpp
// Version 1.0
// Date	2023/02
// Author Ching Wei Lai
// Description
// Tests EggCarton module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "EggCarton.h"

using namespace std;

namespace sdds {

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {

      //size: coefficient of 6
      //size: between 6 and 36 (inclusively)
      //noOfEggs: between 0 and the size of the Carton
      if ((size % 6) != 0 || (size < 6 || size > 36) || (noOfEggs < 0 || noOfEggs > size) ) {
         //size and number of eggs in the carton to -1.
         setBroken(-1, -1);
      }
      else { 
         //the value is valid then set the size, noOfEggs, jumboSize
         m_size = size;
         m_noOfEgg = noOfEggs;
         m_jumboSize = jumboSize;
      }
   }

   //destructor
   EggCarton::~EggCarton() {
      m_size = 0;
      m_noOfEgg = 0;
      m_jumboSize = false;
   }

   //receive and set the size and number of eggs
   EggCarton& EggCarton::setBroken(int size, int noOfEggs) {
      m_size = size;
      m_noOfEgg = noOfEggs;
      return *this;
   }

   //displays the Carton on the screen -> call the displayCarton function
   ostream& EggCarton::display(ostream& ostr) const {
      // if it is not broken (see operator bool() overload) -> displayCarton function
      if (bool(*this)) {
         displayCarton(m_size, m_noOfEgg, m_jumboSize, ostr);
      }
      else {
         //otherwise, display the message
         ostr << "Broken Egg Carton!" << endl;
      }
      return ostr;
   }

   ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const {
      int cartonWidth = size == 6 ? 3 : 6;
      for (int i = 0; i < size; i++) {
         ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
         ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
      }
      return ostr;
   }

   istream& EggCarton::read(istream& istr) {

      m_jumboSize = false;

      //read a character from istr
      char jumbo;
      istr >> jumbo;

      //j -> set the jumbo flag to true
      if (jumbo == 'j') {
         m_jumboSize = true;
      }
      istr.ignore();     //ignore the next character.
      istr >> m_size;    //read an integer into the size of the Carton
      istr.ignore();     //ignore the next character
      istr >> m_noOfEgg; //read another integer into the number of eggs

      //perform the same validation on the attributes as the constructor, fails -> setBroken()
      if ((m_size % 6) != 0 || (m_size < 6 || m_size > 36) || (m_noOfEgg < 0 || m_noOfEgg > m_size)) {
         setBroken(-1, -1);
      }
      return istr;
   }

   //returns true if the size of the Carton is greater than zero
   EggCarton::operator bool() const {
      return m_size > 0;
   }
   
   EggCarton::operator int() const {
      //use boolean conversion and returns the number of eggs
      if (bool(*this)) {
         return m_noOfEgg;
      }
      else {
         return -1;  //otherwise, it will return -1
      }
   }

   EggCarton::operator double() const {
      double totalWeight = 0.0;
      if (bool(*this)) {
         //using the constant weight values defined in the header file in Kilos.
         totalWeight = (m_noOfEgg * (m_jumboSize ? JumboEggWieght : RegularEggWieght)) / 1000.0;
      }
      else {
         //If the Carton is broken this conversion returns -1.0.
         totalWeight = -1.0;
      }
      return totalWeight; 
   }

   EggCarton& EggCarton::operator--() {
      //If the Carton is not broken and the number of eggs is more than zero
      if (bool(*this) && m_noOfEgg > 0) {
         m_noOfEgg -= 1;  //it will reduce it by one.
      }
      return *this;
   }

   EggCarton& EggCarton::operator++() {
      //Carton is not broken it will add one to the number of eggs ( use operator bool() overload)
      if (bool(*this)) {
         m_noOfEgg += 1;

         //number of eggs exceeds the size -> setBroken();
         if (m_noOfEgg > m_size) {
            setBroken(-1, -1);
         }
      }
      return *this;
   }

   //Creates a local copy: use int, not reference(x)
   EggCarton EggCarton::operator--(int) {
      EggCarton old(*this);
      --(*this);
      return old;
   }

   //Creates a local copy: use int, not reference(x)
   EggCarton EggCarton::operator++(int) {
      EggCarton old(*this);
      ++(*this);
      return old;
   }

   EggCarton& EggCarton::operator=(int value) {
      //Sets the number of eggs to the integer value
      m_noOfEgg = value;

      //If the number of eggs exceeds the size ->setBroken();
      if (m_noOfEgg > m_size) {
         setBroken(-1, -1);
      }
      return *this;
   }

   EggCarton& EggCarton::operator+=(int value) {
      if (bool(*this)) {
         //Add the value to the number of eggs 
         m_noOfEgg += value;
  
         //If the number of eggs exceeds the size ->setBroken();
         if (m_noOfEgg > m_size) {
            setBroken(-1, -1);
         }
      }
      return *this;
   }

   EggCarton& EggCarton::operator+=(EggCarton& right) {
      //move the eggs from the right Carton to the empty spots of the current Carton
      if (bool(*this)) {
         int moveEgges = m_size - m_noOfEgg;
         m_noOfEgg += right.m_noOfEgg;
         m_noOfEgg = m_size;
         right.m_noOfEgg -= moveEgges;
      }
      return *this;
   }

   bool EggCarton::operator==(const EggCarton& right) const {
      // if the difference between the weight of the current Carton and the weight of the right Carton is between -0.001 and 0.001 kilos
      return (double(m_jumboSize) - double(right.m_jumboSize) >= -0.001) &&
             (double(m_jumboSize) - double(right.m_jumboSize) >= 0.001);
   }

   int operator+(int left, const EggCarton& right) {
      int sum = 0;
      //If the right operand is not broken
      if (bool(right)) {
         sum = left;
      }
      else {
         //return the sum of "left" + "right"
         sum = left + right;
      }
      return sum;
   }

   ostream& operator<<(ostream& ostr, const EggCarton& right) {
      //displays the EggCarton and returns ostr
      right.display(ostr);
      return ostr;
   }

   istream& operator>>(istream& istr, EggCarton& right) {
      //Reads the specs from the console into the right Carton and returns istr.
      right.read(istr);
      return istr;
   }
}