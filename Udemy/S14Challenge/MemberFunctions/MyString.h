#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <string>

class MyString {

    // overload operators as non-member funtions
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &in, MyString &rhs);
       
    private:

    char* str; //pointer to C-Style string = chr array

    public:

    MyString();                                 // No args constructor
    MyString(const char* s);                    // String arg constructor
    MyString(const MyString &source);           // Copy constructor
    MyString(MyString &&source);                // Move constructor
    ~MyString();                                // Destructor

    //Operators overload
    MyString &operator=(const MyString &rhs);   // Copy assignment operator
    MyString &operator=(MyString &rhs);         // Move assignment operator

    void display() const;

    //getters

    int get_length() const;
    const char *get_str() const;

    // Overloaded operator as member methods (they only get one parameter)

    MyString operator-() const;                 // to lower case
    MyString operator+(const MyString &rhs);    // concatenate
    bool operator==(const MyString &rhs) const; // equals
    bool operator!=(const MyString &rhs) const; // not equals
    bool operator<(const MyString &rhs) const;  // less than
    bool operator>(const MyString &rhs) const;  // more than
    MyString &operator+= (const MyString &rhs); // concat and assign. It returns ref because it modifies original object (and thus, is not const)
    MyString operator*(int n) const;            // repeat n times. It's not by reference and const because it returns different object
    MyString &operator*=(int n);                // repeat and assign
    MyString &operator++();                     // pre-increment touppercase
    MyString operator++(int);                   // post-increment, so it returns new object after using original
};


#endif // _MYSTRING_H_