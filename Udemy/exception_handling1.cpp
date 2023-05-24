#include <iostream>

int main() {
    // double kilometers{};
    // double liters{};         // doubles don't crash when dividing by 0!
    int kilometers{};
    int liters{};
    double kilometers_per_liter {};

    std::cout << "Enter the kilometers: ";
    std::cin >> kilometers;
    std::cout << "Enter the liters: ";
    std::cin >> liters;


    // avoid divide by zero with if else
    /* if (liters != 0) {
    kilometers_per_liter = kilometers / liters;
    std::cout << "Result: " << kilometers_per_liter << std::endl;
    } else {
        std::cerr << "Divide by 0!" << std::endl;
    } */

    // throw exception

    try {
        if (liters == 0)
            throw 0;
        // if exception is thrown this code does not execute:
        kilometers_per_liter = kilometers / liters;
        std::cout << "Result: " << kilometers_per_liter << std::endl;    
    } catch (int &ex) {
        std::cerr << "Divide by 0!" << std::endl;
        std::cout << "Thrown int: " << ex << std::endl;
    }    

    std::cout << "Bye" << std::endl;

    return 0;
}