/*
*****************************************************************************
                         movie.h
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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

struct Movie {
   char m_title[128];
   int m_year;
   char m_rating[6];
   int m_duration;
   char m_genres[10][11];
   float m_consumerRating;
};

namespace sdds {
   bool loadMovies();
   bool hasGenre(const Movie* mvp, const char genre[]);
   void displayMovie(const Movie* mvp);
   void displayMoviesWithGenre(const char genre[]);
}

#endif 

