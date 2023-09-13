/***********************************************************************
// OOP244 Workshop 4 Part2: Constructor, Destructor and the current object
// File main.cpp
// Version 1.0
// Date	2023/01
// Author Ching Wei Lai
// Description
// Tests NameTag module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NameTag.h"
using namespace std;
namespace sdds {

   //default constructor (for an empty tag)
   NameTag::NameTag() {
      m_name = nullptr;
      m_extension = 0;
   }

   //have a destructor to avoid memory leaks, DMA
   NameTag::~NameTag() {
      delete[] m_name;
      m_name = nullptr;
   }

   //constructor with one argument to set the name without extension number
   NameTag::NameTag(const char* name) {
      *this = NameTag();
      if (name) {
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
   }

   //constructor with two arguments to set the name and the extension
   NameTag::NameTag(const char* name, int num) {
      *this = NameTag();
      if (name){
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
      m_extension = num;
   }

   //a function called print to print the name tag as shown above
   void NameTag::print() {
      if (m_name == nullptr || (m_extension != 0 && (m_extension < 10000 || m_extension > 99999))) {
         cout << "EMPTY NAMETAG!" << endl;
      }
      else {
         int len = strlen(m_name);
         int width;
         if (len < 20)
         {
            width = 20;
         }
         else if (len >= 40)
         {
            width = 40;
         }
         else
         {
            width = len;
         }

         cout.setf(ios::left);
         cout << "+";
         cout.width(static_cast<std::streamsize>(width) + 3);
         cout.fill('-');
         cout.unsetf(ios::left);
         cout << "+" << endl;

         cout.setf(ios::left);
         cout << "| ";
         cout.width(width);
         cout.fill(' ');
         cout << ' ';
         cout << " |" << endl;

         cout << "| ";
         for (int i = 0; i < len && i < 40; i++)
         {
            cout << m_name[i];
         }
         if (len < 20)
         {
            cout.width(width - len - 1);
            cout << ' ' << ' ' << ' ' << '|' << endl;
         }
         else
         {
            cout << " |" << endl;
         }

         cout << "| ";
         cout.width(width);
         cout.fill(' ');
         cout << ' ';
         cout << " |" << endl;

         cout << "| ";
         cout << "Extension: ";
         cout.width(static_cast<std::streamsize>(width) - 11);
         if (m_extension == 0) {
            cout << "N/A";
         }
         else {
            cout << m_extension;
         }
         cout << " |" << endl;

         cout << "| ";
         cout.width(width);
         cout.fill(' ');
         cout << ' ';
         cout << " |" << endl;

         cout << "+";
         cout.width(static_cast<std::streamsize>(width) + 3);
         cout.fill('-');
         cout.unsetf(ios::left);
         cout << "+" << endl;
      }
   }

   //receives the name and extension number from console and returns the reference of the current object (NameTag&).
   NameTag& NameTag::read() {

      char name[41]; //the maximum of 40 characters
      int num = 0;  //5 digit extension number
      char yn;  // yes or no
      bool check = false;

      //check the length of the name. if it is longer than 40, wipe it.
      cout << "Please enter the name: ";
      cin.get(name, 41);
      cin.clear();
      cin.ignore(1000, '\n');
      
      //this is the most important part!! without check the m_name, it causes the memory leak.
      if (m_name) {
         delete[] m_name;
      }

      // if the length is less than 40 characters, store the name (make sure the name is empty state)
      m_name = nullptr;
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      //check the m_name is not empty
      if (strlen(m_name) == 0 || strcmp(m_name, " ") == 0){
         cout << "EMPTY NAMETAG!" << endl;
      }
      else {
         // ask user the enter an extension
         cout << "Would you like to enter an extension? (Y)es/(N)o: ";
         do {
            //make sure the input is valid, if it is not valid, wipe it
            cin >> yn;
            cin.clear();
            cin.ignore(1000, '\n');

            //Use the toupper() function converts a lowercase alphabet to an uppercase alphabet.
            //if the input is not Y/y/N/n, ask user to enter the answer again
            if (toupper(yn) != 'Y' && toupper(yn) != 'N') {
               cout << "Only (Y) or (N) are acceptable, try agin: ";
               check = true;
            }
            // the input is valid
            else {
               check = false;
            }
         } while (check != false);

         //user input is N/n: do nothing, user input is Y/y: ask user to type the extension
         if (toupper(yn) == 'Y') {
            cout << "Please enter a 5 digit phone extension: ";
            do
            {
               //ask user to type the extension
               check = false;
               cin >> num;
               cin.clear();
               cin.ignore(1000, '\n');

               //bad interger value, the input should be a number
                  if (cin.fail() || !num) {
                     cout << "Bad integer value, try again: ";
                     check = true;
                  }
                  // the extension: 10000<=value<=99999
                  else if (num < 10000 || num > 99999) {
                     cout << "Invalid value [10000<=value<=99999]: ";
                     check = true;
                  }
            } while (check != false);
         }
      }
      //the user enters a correct value then the input should be assign to extension
      m_extension = num;
      return *this;
   }
}