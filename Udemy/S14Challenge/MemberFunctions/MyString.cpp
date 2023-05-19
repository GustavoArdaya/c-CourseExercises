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

// overloaded to lower case operator
MyString MyString::operator-() const{
    char *buff = new char[std::strlen(str) + 1];    // allocate space for new string
    std::strcpy(buff, str);                         // copy original string into new one
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);            // convert characters to lower case
    MyString temp {buff};                           // use constructor to create temporary MyString object from new string
    delete [] buff;                                 // deallocate memory from new string
    return temp;                                    // return new object (thus, no & is needed in return type)
}

// overloaded concatenate operator // returns new object...
MyString MyString::operator+(const MyString &rhs){
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);                         // copies str to buff
    std::strcat(buff, rhs.str);                     // adds parameter object's str to end of buff
    MyString temp {buff};                                // creates new MyString object from buff
    delete [] buff;                                 // deallocates memory from buff
    return temp;                                    // returns copy
}

bool MyString::operator==(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool MyString::operator!=(const MyString &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
}

bool MyString::operator<(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool MyString::operator>(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

MyString &MyString::operator+=(const MyString &rhs) {
    *this = *this + rhs;           // makes use of overloaded "=". assigns original object + other object 
    return *this;                  // since it returns original object it uses & in return type and returns a reference
}

MyString MyString::operator*(int n) const {
    size_t buff_size = (std::strlen(str) * n) + 1; // this stores value for size of allocated space per number of repetitions
    char *buff = new char[buff_size];
    strcpy(buff, ""); // this initializes buffer with empty string
    for (int i = 1; i < n; i++)
        strcat(buff, str);          // this adds str content n types to buff
    MyString temp {buff};           // new MyString object created from buff
    delete [] buff;                 // deallocates space from heap
    return temp;                    // returns new object (thus, no & needed)
}

MyString &MyString::operator*=(int n) { // returns reference!
    *this = *this * n;               // makes use of previous overloaded method
    return *this;
}

// to upper case
MyString &MyString::operator++() {      // pre-increment
    for (size_t i=0; i< std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;                       // modifies original
}

MyString MyString::operator++(int) {
    MyString temp (*this);          // copy operator
    operator++();                   // calls previous object to increment original by reference
    return temp;                    // returns original, before increment, and thus a new object
}