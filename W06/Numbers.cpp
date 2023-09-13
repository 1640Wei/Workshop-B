/***********************************************************************
// OOP244 Workshop 6 Part1: Classes with Resource
// File Numbers.cpp
// Version 1.0
// Date	2023/02
// Author Ching Wei Lai
// Description
// Tests Numbers module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
#include "Numbers.h"
using namespace std;
namespace sdds {

   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   unsigned int Numbers::countLines(const char* filename) { 
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

   /////////////////////////////////////////////////////////////////

      //Default constructor  -> Sets the object to a safe empty state.
      Numbers::Numbers() {
         setEmpty();
         m_originalFlag = false;
      }

      //One argument constructor  -> Sets the file name to the argument value and call the load() function
      Numbers::Numbers(const char* filename) {
         setEmpty();
         strcpy(m_filename, filename);
         load();
      }

      //Destructor  -> call the save() function and deletes the Collection pointer
      Numbers::~Numbers() {
         save();
         delete[] m_collection;
      }

      //Copy Constructor  -> sets a safe empty state
      Numbers::Numbers(const Numbers& R) {
         setEmpty();
         m_originalFlag = false;
         *this = R;
      }

      //Copy Assignment Operator
      Numbers& Numbers::operator=(const Numbers& R) {

         //save the Collection calling the save() function.
         save();

         delete[] m_collection;

         setEmpty();
         //if (m_collection != R.m_collection && R.m_collection != 0)
         if (m_collection != R.m_collection ) {
            setEmpty();
            m_originalFlag = false;
            m_collection = new double[R.m_collectionSize];
            for (int i = 0; i < R.m_collectionSize; i++) {    
               m_collection[i] = R.m_collection[i];
            }
            m_collectionSize = R.m_collectionSize;
         }
         return *this;
      }

      //setEmpty  -> Sets all attributes to null, zero, false or empty Cstring.
      void Numbers::setEmpty() {
         m_collection = nullptr;
         m_collectionSize = 0;
         m_originalFlag = false;
         m_addedFlag = false;
      }

      //load  
      bool Numbers::load() {

         //Delete the current Collection
         delete[] m_collection;

         //call the countLines() and get the number of lines in the file.
         int lineNum = countLines(m_filename);

         //If the number of lines is greater than zero (the file is not empty)
         int counter = 0;
         double temp;
         
         if (lineNum > 0) {
            ifstream file(m_filename);  //Create an instance of ifstream for reading the data file using the file name
            
            m_collection = new double[lineNum];  //Allocate memory to the number of lines

            //While the ifstream object is in a good state -> keep reading double values from the file into the elements of the Collection
            while (file) {
               file >> temp;    
               file.ignore(1000, '\n');
               if (file) {
                  if (counter < lineNum)
                  m_collection[counter] = temp; 
                  counter++;
               }
            }
            file.ignore(1000, '\n');
         }
         //If the number of lines and the number of successful reads do not match -> discard all the read and set the object back to an empty state
         if (lineNum != counter) {
            delete[]m_collection;
            setEmpty();
         }
         //Otherwise set the Collection size to the number of double values read and set the original flag to true.
         else {
            m_collectionSize = counter;
            m_originalFlag = true;
         }
         return counter == lineNum;
      }

      //save
      void Numbers::save() {
         if (m_addedFlag && m_originalFlag) {
            std::ofstream f(m_filename);
            for (int i = 0; i < m_collectionSize; i++) {
               f.setf(ios::fixed);
               f.precision(2);
               f << m_collection[i] << endl;
            }
         }
      }

      //max -> the largest double number 
      double Numbers::max() const {
         double max = 0.0;
         if (!isEmpty()) {
            max = m_collection[0];
            for (int i = 1; i < m_collectionSize; i++)
               if (max < m_collection[i]) max = m_collection[i];
         }
         return max;
      }

      //min -> the smallest double number 
      double Numbers::min() const {
         double min = 0.0;
         if (!isEmpty()) {
            min = m_collection[0];
            for (int i = 1; i < m_collectionSize; i++)
               if (min > m_collection[i]) min = m_collection[i];
         }
         return min;
      }

      //average -> the average of the double numbers
      double Numbers::average() const {
         double aver = 0.0;
         if (!isEmpty()) {
            for (int i = 0; i < m_collectionSize; i++)
               aver += m_collection[i];
            aver = aver / m_collectionSize;
         }
         return aver;
      }

      //check the collection is not empty
      bool Numbers::isEmpty() const {
         return m_collection == nullptr;
      }

      //Boolean type conversion operator overload (bool cast overload)  -> returns true if Collection pointer is not nullptr
      Numbers::operator bool() const {
         bool flag = false;
         if (m_collection != nullptr) {
            flag = true;
         }
         return flag;
      }

      //sort  -> calls the provided sort function
      void Numbers::sort() {
         sort(m_collection, m_collectionSize);
      }

      //Operator +=   
      Numbers& Numbers::operator+=(const double dou) {

         //Create a temporary local double-pointer and allocate memory with the increased size
         double* temp = new double[m_collectionSize + 1];

         //Copy all the current values from the Collection to the newly allocated memory -> for loop
         for (int i = 0; i < m_collectionSize; i++) {
            temp[i] = m_collection[i];
         }

         //Update the size of the data to the new size
         temp[m_collectionSize] = dou;

         //Now that all the values are copied to the new memory, delete the original Collection pointer
         if (m_collection) {
            delete[] m_collection;
         }
                //Set the original Collection pointer to point to newly allocated memory and update the Collection size
            m_addedFlag = true;
            m_collection = temp;
            m_collectionSize++;     
         return *this;
      }

      //display function
      ostream& Numbers::display(ostream& ostr) const {
         
         //if the object is empty, insert: "Empty list"
         if (isEmpty()) ostr << "Empty list" ;

         else {

            //if the Numbers object is not original insert "Copy Of " else insert the file name
            if (m_originalFlag) 
               ostr << m_filename << endl;
            //else ostr << "Copy Of numbers.txt" << endl;
            else 
               ostr << "Copy of numbers.txt" << endl;

            // set the precision to print two digits after the decimal point.
            //insert all the number in the Collection comma separated like the following example:
            ostr.setf(ios::fixed);
            ostr.precision(2);
            for (int i = 0; i < m_collectionSize; i++) {
               if (i != 0) ostr << ", ";
               ostr << m_collection[i];
            }

            //New line and insert a line with 76 dashes(-) total of numbers. max. min. average. 76 = 
            ostr << endl << "----------------------------------------------------------------------------" << endl;
            ostr << "Total of " << m_collectionSize << " number(s), ";
            ostr << "Largest: " << max() << ", ";
            ostr << "Smallest: " << min() << ", ";
            ostr << "Average: " << average() << endl << "============================================================================";
         }
         ostr.unsetf(ios::fixed);
         return ostr;
      }

      //Overload the insertion operator 
      std::ostream& operator<<(std::ostream& ostr, const Numbers& N) {
         return N.display(ostr);
      }

      //Overload the extraction operator 
      std::istream& operator>>(std::istream& istr, Numbers& N) {
         double enterDouble;
         istr >> enterDouble;
         N += enterDouble;
         return istr;
      }
}