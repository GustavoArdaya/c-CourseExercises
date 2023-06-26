#include <iostream>

int main() {

    double length {};
    double width {};
    double height {};
    double area {};
    double volume {};

    std::cout << "Box Base Area and Volume Calculator\nPlease enter values: " << std::endl;
    std::cout << "Length: ";
    std::cin >> length;
    std::cout << "Width: ";
    std::cin >> width;
    std::cout << "Height: ";
    std::cin >> height;

    area = width * length;
    volume = area * height;
    std::cout << "The base area is: " << area << std::endl;
    std::cout << "The volume is: " << volume << std::endl;



    return 0;
}