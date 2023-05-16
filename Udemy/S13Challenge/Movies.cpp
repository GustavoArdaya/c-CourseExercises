#include <iostream>
#include "Movies.h"

// Movie list no args constructor
Movies::Movies() {    
}

// Movie list destructor
Movies::~Movies() {    
}

//add movie implementation
bool Movies::add_movie(std::string name, std:: string rating, int watched){
    for ( Movie movie : movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    Movie new_movie = Movie(name, rating, watched);
    movies.push_back(new_movie);
    return true;
}

// increment watch count implementation
bool Movies::increment_watched(std::string name) {
    for ( Movie movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    std::cout << name << " not found in movie list";
    return false;
}

// display movie list
void Movies::display() const {
    for (Movie movie: movies) {
        std::cout << movie.get_name() << ", " << movie.get_rating() << ", " << movie.get_watched() << "." << std::endl;  
    }
}