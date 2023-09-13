/*
*****************************************************************************
                         50best.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Movie.h"
using namespace std;
using namespace sdds;

// flushes the keyboard
void flushkeys() {
   while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
   char ch = cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}

int main() {
   bool done = false;
   char genre[128];
   loadMovies();
   cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
   while (!done) {
      cout << "Enter the movie genre to start the search: ";
      cin >> genre;
      flushkeys();
      displayMoviesWithGenre(genre);
      cout << "Do another search? (Y)es: ";
      done = !yes();
      cout << endl;
   }
   cout << "Goodbye!" << endl;
   return 0;
}