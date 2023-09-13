/*
*****************************************************************************
                         File.h
Full Name  : Ching Wei Lai
Student ID#: 136893211
Email      : cwlai6@myseneca.ca
Date       : 18 Jan 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   bool readTitle(char title[]);
   bool readYear(int* year);
   bool readMovieRating(char rating[]);
   bool readDuration(int* duration);
   bool readGenres(char genre[][11]);
   bool readConsumerRating(float* rating);
   void flushkeys();
   bool yes();
}
#endif