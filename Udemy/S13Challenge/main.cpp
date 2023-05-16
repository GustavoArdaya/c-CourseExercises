#include <iostream>
#include "Movies.h"
#include "Movie.h"

//function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

//funcion implementations - Since functions return bool, these functions provide feedback to user

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) { // if name is not repeated and function returns true
        std::cout << name << " watch count incremented" << std::endl;
    } else {
        std::cout << name << " was not found" << std::endl;
    }
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << " added to movie list" << std::endl;
    } else {
        std::cout << name << " already exists in list" << std::endl;
    }
}

int main () {

    Movies my_movies;
    
    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13",2);                 // OK
    add_movie(my_movies,"Star Wars", "PG",5);             // OK
    add_movie(my_movies,"Cinderella", "PG",7);           // OK
     
    my_movies.display();   // Big, Star Wars, Cinderella
    
    add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    add_movie(my_movies,"Ice Age", "PG",12);              // OK
 
    my_movies.display();    // Big, Star Wars, Cinderella, Ice Age
    
    increment_watched(my_movies,"Big");                    // OK
    increment_watched(my_movies,"Ice Age");              // OK
    
    my_movies.display();    // Big and Ice Age watched count incremented by 1
    
    increment_watched(my_movies,"XXX");         // XXX not found

	return 0;
}