#include <iostream>

int main() {

    double celsius {};
    double fahrenheit {};
    std::cout << "Please enter degrees in Celsius: ";
    std::cin >> celsius;

    fahrenheit = (9.0 / 5) * celsius + 32;

    std::cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit" << std::endl;


    return 0;
}