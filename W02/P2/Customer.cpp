/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Customer.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Customer.h"
#include "Tools.h"
using namespace std;

namespace sdds {

   //Sets Customer data members to an empty state
   void EmptyRecord(Customers& c_rec) {
      c_rec = { 0 };
   }

   //Sets CustomersRecord data members to an empty state
   void EmptyRecord(CustomersRecord& t_rec) {
      t_rec = { 0 };
   }

    // complete
    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }
    // complete

    bool read(Customers& rec) {
       bool check = true;

       //request to enter user name and reads a CString into the name of the Customer reference.
       cout << " Enter User name: ";
       read(rec.user_name, 21);

       //name is empty after entry, the function returns false.
       if (strcmp(rec.user_name, "") == 0) {
          check = false;
       }
       else {

          //read the likes_count, retweets_count, replies_count, and share_videos
          cout << " Enter likes_count: ";
          cin >> rec.likes_count;

          cout << " Enter retweets_count: ";
          cin >> rec.retweets_count;

          cout << " Enter replies_count: ";
          cin >> rec.replies_count;

          cout << " Enter share videos (y/n): ";
          cin >> rec.share_videos;
          if (cin.fail())
          {
             cin.clear();
             cin.ignore(1000, '\n');
          }

       }
       return check;
    }

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {

       //Adds a Customer to the dynamically allocated memory of customers in CustomersRecord
       Customers* p;
       if (t_rec.noOfRecords == 0)
       {
          t_rec.ptr_rec = new Customers[t_rec.noOfRecords + 1];
          t_rec.ptr_rec[0] = c_rec;
       }
       else
       {
          p = new Customers[t_rec.noOfRecords + 1];
          for (int i = 0; i < t_rec.noOfRecords; i++)
          {
             p[i] = t_rec.ptr_rec[i];
          }
          p[t_rec.noOfRecords] = c_rec;
          delete[] t_rec.ptr_rec;
          t_rec.ptr_rec = nullptr;
          t_rec.ptr_rec = p;
       }
       t_rec.noOfRecords++;
    }

    void display(const Customers& c_rec) {
       //dispay customers info - name, retweets, likes, replies, share vedios 
       cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count
          << ", " << c_rec.replies_count << ", " << c_rec.share_videos << endl;
    }

    void display(const CustomersRecord& t_rec) {

       //It prints a row number with a period before each user name.
       int i;
       for (i = 0; i < t_rec.noOfRecords; i++) {
          cout << i + 1 << ". ";
          display(t_rec.ptr_rec[i]);
          cout << endl;
       }
    }

  }

