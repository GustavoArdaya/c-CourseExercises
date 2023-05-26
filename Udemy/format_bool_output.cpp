#include <iostream>
#include <iomanip>

int main() {

    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    std::cout << std::boolalpha;    // change to literal "true" and "false"
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    std::cout << std::noboolalpha;
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // std::cout.setf(std::ios::boolalpha); // long method to set boolalpha
    // std::cout << std::resetiosflags(std::ios::boolalpha); // to reset previous flag to default : 0 and 1
    return 0;
}