#include <iostream>
#include <iomanip>

int main() {

    double num {1234.5678};

    std::cout << num << std::endl; // will display default precision of 6 (2 decimals)
    
    double num1 {123456789.987654321};

    std::cout << num1 << std::endl; // will display scientific notation up to 6 digits by default

    std::cout << std::setprecision(9); 
    std::cout << num1 << std::endl; // rounding

    std::cout << std::fixed; 
    std::cout << std::setprecision(6); //default
    std::cout << num1 << std::endl; // fixed makes precision apply to decimals after point

    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num1 << std::endl;

    std::cout << std::resetiosflags(std::ios_base::fixed);

    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << num1 << std::endl;

    double num2 {12.34};
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios_base::scientific);

    std::cout << num2 << std::endl;

    std::cout << std::showpoint; // displays trailing zeroes up to precision

    std::cout << num2 << std::endl;

    std::cout.unsetf(std::ios::scientific | std::ios::fixed); // this too will reset

    return 0;
}