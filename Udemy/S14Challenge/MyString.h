#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <string>

class MyString {

    // overload operators as non-member funtions
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &in, MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend bool operator!=(const MyString &lhs, const MyString &rhs);
    friend bool operator<(const MyString &lhs, const MyString &rhs);
    friend bool operator>(const MyString &lhs, const MyString &rhs);
    friend MyString &operator+=(MyString &lhs, const MyString &rhs);
    friend MyString operator*(const MyString &lhs, int n);
    friend MyString &operator*=(MyString &lhs, int n);
    friend MyString &operator++(MyString &obj); 
    friend MyString operator++(MyString &obj, int);
    
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
};


#endif // _MYSTRING_H_