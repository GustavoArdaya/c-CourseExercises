#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public: 
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
int get_data() const { return data;}
~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }

};

int main () {

    // Test *t1 = new Test {1000};
    // delete t1;

    std::unique_ptr<Test> t1 {new Test{1000}};
    std::unique_ptr<Test> t2 = std::make_unique<Test>(2000);            // does not use new. Modern C++
    
    // you're not allowed to copy (with = assignment) but you can move it with std::move

    std::unique_ptr<Test> t3;
    t3 = std::move(t1);     // this moves t1 pointer into t3, so t1 becomes a null pointer
    if (!t1)                // t3 is now "owner" of previus t1 address
        std::cout << "t1 is nullptr" << std::endl;

    return 0;
}