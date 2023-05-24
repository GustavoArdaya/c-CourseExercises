#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest Constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest Constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest Destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test *ptr) {
    std::cout << "\tUsing custom function deleter" << std::endl;
    delete ptr;
}

int main() {

    { // inside code block to create scope
    // Using a function
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter};
    }

    std::cout << "=========================" << std::endl;
    {
    // using Lambda expression

        std::shared_ptr<Test> ptr2 {new Test{200},
            [] (Test *ptr) {       // anonymous Lambda function
                std::cout << "\tUsing custom Lambda deleter" << std::endl;
                delete ptr;
            }};
    }
    return 0;
}