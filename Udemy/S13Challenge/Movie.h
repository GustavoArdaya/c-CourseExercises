#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie {
    private:
        std::string name; 
        std::string rating;
        int watched;

    public:
        // 3 args constructor
        Movie(std::string name, std::string rating, int watched);
        
        // copy constructor
        Movie(const Movie &source);

        //destructor
        ~Movie();

        //Setters and Getters

        void set_name(std::string new_name) { this->name = new_name; }
        std::string get_name() const { return name; }

        void set_rating(std::string new_rating) { this->rating = new_rating; }
        std::string get_rating() const { return rating; }

        void set_watched(int new_watched) { this->watched = new_watched; }
        int get_watched() const { return watched; }

        //watched increment by 1
        void increment_watched() { ++watched; }

        //display movie information
        void display() const;
};



#endif // _MOVIE_H_