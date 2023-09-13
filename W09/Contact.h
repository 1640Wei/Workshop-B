/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.h
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
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"
namespace sdds {
    class Contact : public Person {
        char* address = nullptr;
        char* city = nullptr;
        char province[3]= {};
        char postalCode[8] = {};
    public:
        //constructor
        Contact();
        //Rule of three
        Contact(const Contact& copyFrom);
        Contact& operator=(const Contact& RightOperand);
        ~Contact(); //destructor
        //check if the member is empty or not
        bool isEmpty() const;
        //set it to empty
        void setEmpty();
        //check the input
        void copyInput(const char* address, const char* city, const char* province);
        std::istream& read(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr)const override;
    };
}
#endif