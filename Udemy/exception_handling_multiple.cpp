#include <iostream>
#include <string>

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw 0;
    if (miles < 0 || gallons < 0)
        throw std::string{"Negative value error"};
    return static_cast<double> (miles) / gallons;
}

int main() {
    int miles{};
    int gallons{};
    double miles_per_gallon {};

    std::cout << "Enter miles: ";
    std::cin >> miles;
    std::cout << "Enter gallons: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int &ex) {
        std::cerr << "Tried to divide by zero" << std::endl;
    } catch (std::string &ex) {
        std::cerr << ex << std::endl;
    } catch (...) {
        std::cerr << "Unknow error" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;

}