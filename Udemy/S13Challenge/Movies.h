#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies {
    private:
        
        std::vector<Movie> movies;

    public:

        //constructor
        Movies();
        //destructor
        ~Movies();

        //add movie
        bool add_movie(std::string name, std:: string rating, int watched);

        //increment watch count
        bool increment_watched(std::string name);

        //display
        void display() const;
        
};

#endif // _MOVIES_H_