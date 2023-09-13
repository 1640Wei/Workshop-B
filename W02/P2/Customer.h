/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Customer.h
// Version 1.1
// Date   Winter 2023
// Ching Wei Lai
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ching Wei Lai   23-01-29       reordered user's tweets report
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    
       
    
   
    // to be completed

    //Implement 2 overloads of a function called EmptyRecord
    void EmptyRecord(Customers & c_rec);
    void EmptyRecord(CustomersRecord & t_rec);

    //Implement the follwoing 5 functions
    bool read(Customers & rec);
    void read(char* str, int len); //provided
    void addCustomer(CustomersRecord & t_rec, const Customers & c_rec);
    void display(const Customers & c_rec);
    void display(const CustomersRecord& t_rec);

}

#endif 
