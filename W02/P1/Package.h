/*
*****************************************************************************
                         Package.h
Full Name  : Ching Wei Lai
Student ID#: 136893211
Email      : cwlai6@myseneca.ca
Date       : 26 Jan 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_PACAGE_H_
#define SDDS_PACKAGE_H_

#define filename_r "Filtered_Dataset.csv"

namespace sdds {

    struct Customers {
        char* Package_Name;
        int user_id;
        double timeinhours;
        int dayofyear;
        int Fwifitime;
        int Fctime;
        char dayofweek;
    };

    int loadTraces(); // loads a customers structure with its values from the file
           
    int loadTraces(Customers& user); // allocates dynamic array of customers and loads all the file records into the array.

    void grouptTraces(); //Group the dynamic array of records based on the user id of customers.

   
    // ADD [1]: Declare a prototype for the display function, this function displays a customer record on the screen.
    void display();

   // ADD [2]: Declare a prototype for the deallocateMemory function that do the following:
                         // (1). deallocates all the Package names in the customer (users) elements,
                         // (2). deallocates the users array 
    void deallocateMemory();

}
#endif  