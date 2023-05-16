#include <iostream>
#include "Movie.h"

//Constructor implementation

Movie::Movie(std::string name, std::string rating, int watched)
    : name(name), rating(rating), watched(watched) {
}

//Copy constructor implementation

Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched} {
}

//Destructor implementation
Movie::~Movie() {    
}

//Display method implementation
void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}