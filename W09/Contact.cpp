/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.cpp
// Version 1.0
// Date	Winter of 2023
// Author	Ching Wei Lai
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include "Tools.h"
namespace sdds {
   //constructor
    Contact::Contact() {
        setEmpty();
    }
    //Rule of three
    //copy constructor
    Contact::Contact(const Contact& copyFrom):Person(copyFrom)
    {
       operator=(copyFrom);
    }
    //copy assignment operator
    Contact& Contact::operator=(const Contact& R)
    {
       if (this != &R) {
          Person::operator=(R);
          delAlloCopy(address, R.address);  //pointer -> DMA
          delAlloCopy(city, R.city);  //pointer -> DMA
          strCpy(province, R.province);  //char -> copy
          strCpy(postalCode, R.postalCode);  //char -> copy
       }
       return *this;
    }
    //destructor -> reuse setEmpty function
    Contact::~Contact() {
       setEmpty();  
    }
    //check if all the member are empty or not
    bool Contact::isEmpty() const {
        bool flag = false;
        //all the members are empty -> return true; otherwise -> return false
        if (address == nullptr && city == nullptr && province[0] == '\0' && postalCode[0] == '\0') {
            flag = true;
        }
        return flag;
    }
    //set all the member to empty space
    void Contact::setEmpty() {
       //check anything in the address? if yes -> delete
       if (address)
          delete[] address;
       address = nullptr;
       //check anything in the city? if yes -> delete
       if (city)
          delete[] city;
       city = nullptr;
       province[0] = '\0';
       postalCode[0] = '\0';
    }
    //copy the input
    void Contact::copyInput(const char* address, const char* city, const char* province) {
       //address -> pointer : DMA
       this->address = new char[sdds::strLen(address) + 1];
       sdds::strCpy(this->address, address);
       //city -> pointer : DMA
       this->city = new char[sdds::strLen(city) + 1];
       sdds::strCpy(this->city, city);
       sdds::strCpy(this->province, province);
    }
    //read
    std::istream& Contact::read(std::istream& istr) {
       if (istr.good()) {
          char* tempProvince = nullptr;
          char tempPostalCode[8] = {};
          delete[] address;
          address = nullptr;
          delete[] city;
          city = nullptr;
          Person::read(istr);
          //Use the Tools functions for your C-string work and dynamic memory allocation -> dynRead
          address = dynRead(istr, ',');
          //check the address
          if (address && address[0] != '\0') {
             city = dynRead(istr, ','); 
             //address is correct -> check the city
             if (city && city[0] != '\0') {
                tempProvince = dynRead(istr, ',');
                //city is correct -> check the province
                if (tempProvince == nullptr || tempProvince[0] == '\0' || tempProvince[2] != '\0') {
                   istr.setstate(std::ios::failbit); // province is not correct -> set to empty state
                   setEmpty();
                }
                else {
                   strCpy(province, tempProvince);
                   //province is correct -> check the postal code
                   istr.getline(tempPostalCode, 7, '\n');
                   if (!istr) { // postal code is not correct -> set to empty state
                      istr.setstate(std::ios::failbit);
                      setEmpty();
                   }
                   else {
                      //set the postal code to correct format -> a space between it
                      postalCode[0] = tempPostalCode[0];
                      postalCode[1] = tempPostalCode[1];
                      postalCode[2] = tempPostalCode[2];
                      postalCode[3] = ' ';
                      postalCode[4] = tempPostalCode[3];
                      postalCode[5] = tempPostalCode[4];
                      postalCode[6] = tempPostalCode[5];
                   }
                }
             } //just in case -> set the empty state
             else {
                istr.setstate(std::ios::failbit);
                setEmpty();
             }
          }//just in case -> set the empty state
          else {
             istr.setstate(std::ios::failbit);
             setEmpty();
          }
        // Don't forget delete the pointer!!
       if (tempProvince)
             delete[] tempProvince;
       }
       return istr;
    }
    //write (print the data in the attributes) 
    std::ostream& Contact::write(std::ostream& ostr) const {
        if (!isEmpty()) {
            Person::write(ostr);
            ostr << "\n" << address << "\n" << city << " " << province << "\n" << postalCode << "\n";
        }
        return ostr;
    }
}
