#include <iostream>

void func_b();
void func_c();

void func_a() {
    std::cout << "Starting func_a" << std::endl;
    func_b();
    std::cout << "Ending func_a" << std::endl; // this line is not executed
}

void func_b() {
    std::cout << "Starting func_b" << std::endl;
    func_c();
    std::cout << "Ending func_b" << std::endl; // this line is not executed
}

void func_c() {
    std::cout << "Starting func_c" << std::endl;
    throw 100;
    std::cout << "Ending func_c" << std::endl; // this line is not executed
}

int main () {

    std::cout << "Starting main" << std::endl;
    try {
        func_a();
    } catch (int &ex) {         // funcs are removed from stack until thrown error is catched
        std::cout << "Caught error in main" << std::endl;
    }    
    std::cout << "Ending main" << std::endl; 

    return 0;
}