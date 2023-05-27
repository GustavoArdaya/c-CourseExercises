#include <iostream>
#include <iomanip>

int main() {

    int num1 {255};
    int num2 {-255};
    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::dec << num1 << std::endl;
    std::cout << std::hex << num1 << std::endl;
    std::cout << std::oct << num1 << std::endl;


    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num1 << std::endl;
    std::cout << std::hex << num1 << std::endl;
    std::cout << std::oct << num1 << std::endl;

    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;



    return 0;
}