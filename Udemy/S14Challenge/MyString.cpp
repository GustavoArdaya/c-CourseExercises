#include <iostream>
#include <cstring>
#include "MyString.h"

//No arg constructor

MyString::MyString() 
    : str {nullptr} {
        str = new char[1];          // create pointer in heap
        *str = '\0';                // assign terminator to pointer value
}

// Overloaded constructor

MyString::MyString(const char *s)
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];          // same as no args constructor
            *str = '\0';   
        } else {
            str = new char[strlen(s)+1];    // allocate memory in heap for number of characters in str plus 1 for terminator 
            strcpy(str, s);
    }
}

// Copy constructor     
MyString::MyString(const MyString &source)
    : str{nullptr} {                            // since it initializes new pointer, it creates a new object
        str = new char[strlen(source.str) + 1]; // creates space for source string plus 1 for terminator
        strcpy(str, source.str);

        std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
MyString::MyString(MyString &&source)           // this one is not const, as it will delete original pointer after moving
    : str{source.str} {                         // it initializes str with source str, allowing original pointer to be nulled later
        source.str = nullptr;

        std::cout << "Move constructor used" << std::endl;
}

// Destructor
MyString::~MyString() {
    delete [] str;                          // important to delete heap pointer
}

// Copy assignment
MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete [] str;                          // this destroys pointer and deallocates memory from heap
    str = new char[strlen(rhs.str) + 1];    // allocating space for str
    strcpy(str, rhs.str);
    return *this;                           // this returns derreferenced object
}

// Move assignment
MyString &MyString::operator=(MyString &rhs) {
    std::cout << "Using move assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete [] str;                          // deallocate str pointer
    str = rhs.str;                          // "steal" pointer from rhs
    rhs.str = nullptr;                      // rhs pointer deallocated from heap
    return *this;
}

// Display method
void MyString::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// Getters
int MyString::get_length() const { return strlen(str); };
const char *MyString::get_str() const { return str; };

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;                              // assigns string to os object
    return os;                                  // return os as ostream object
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, MyString &rhs) {
    char *buffer = new char[1000];              // this allocates a big enough space in heap for input
    in >> buffer;                               // inserts input into buffer
    rhs = MyString{buffer};                     // assigns new object from buffer to rhs
    delete [] buffer;                           // deallocates memory from buffer
    return in;                                  // returns in as input object
}

// overloaded minus operator
MyString operator-(const MyString &obj) {
    char *new_string = new char[std::strlen(obj.str) + 1]; // allocate space in heap for string + terminator
    std::strcpy(new_string, obj.str);
    for (size_t i = 0; i < std::strlen(new_string); i++)
        new_string[i] = std::tolower(new_string[i]);
    MyString new_obj{new_string};
    delete [] new_string;
    return new_obj;
}

MyString operator+(const MyString &lhs, const MyString &rhs){
    char *new_string = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(new_string, lhs.str);
    std::strcat(new_string, rhs.str);
    MyString new_obj {new_string};
    delete [] new_string;
    return new_obj;
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const MyString &lhs, const MyString &rhs) {
    return !(std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const MyString &lhs, const MyString &rhs){
    return (std::strcmp(lhs.str, rhs.str) < 0);
}


bool operator>(const MyString &lhs, const MyString &rhs){
    return (std::strcmp(lhs.str, rhs.str) > 0);
}

MyString &operator+=(MyString &lhs, const MyString &rhs){
    lhs = lhs + rhs;
    return lhs;                         // this makes use of previously overloaded "+" operator and "="
}

MyString operator*(const MyString &lhs, int n) {
    MyString new_obj;
    for (int i = 1; i <= n; i++)
        new_obj = new_obj + lhs;        // this also seems to make use of previously overloaded "+"
    return new_obj;
}

MyString &operator*=(MyString &lhs, int n) {
    lhs = lhs * n;                      // makes use of previously overloaded "*" and "="
    return lhs; 
}

MyString &operator++(MyString &obj) {       // pre-increment
    for (size_t i = 0; i < std::strlen(obj.str); i++)
        obj.str[i] = std::toupper(obj.str[i]);
    return obj;
}

MyString operator++(MyString &obj, int) {   // int defines post-increment
    MyString new_obj {obj};
    ++obj;                                  // this calls pre-increment
    return new_obj;
}