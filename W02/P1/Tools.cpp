/*
*****************************************************************************
                         Tools.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Tools.h"
#include "Package.h"

using namespace std;
FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
    // read the package name
    int read(char* Package_Name) {
       return fscanf(fp, "%60[^\n]\n", Package_Name);
    }

    // read the user_id, dayofyear, Fwifitime and Fctime 
    int read(int& info) {
       return fscanf(fp, "%d,", &info);
    }

    //read the timeinhours
    int read(double& timeinhour) {
       return fscanf(fp, "%lf,", &timeinhour);
    }
    
    //read the dayofweek
    int read(char& dayofweek) {
       return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &dayofweek);
    }


    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}